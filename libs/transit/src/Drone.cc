#define _USE_MATH_DEFINES

#include "Drone.h"
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "AstarStrategy.h"
#include "DijkstraStrategy.h"
#include "JumpDecorator.h"
#include "SpinDecorator.h"
#include "globals.h"

#include <cmath>
#include <limits>

Drone::Drone(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  data["total distance"] = 0;
  data["pickup distance"] = 0;
  data["distance on trips"] = 0;
  data["number of trips"] = 0;
  data["total time"] = 0;
  data["trip time"] = 0;

  s = Singleton::GetInstance("s");
  s->AddDrone(this);

  available = true;
}

Drone::~Drone() {
  // Delete dynamically allocated variables
}

void Drone::GetNearestEntity(std::vector<IEntity*> scheduler) {
  float minDis = std::numeric_limits<float>::max();
  for (auto entity : scheduler) {
    if (entity->GetAvailability()) {
      float disToEntity = this->position.Distance(entity->GetPosition());
      if (disToEntity <= minDis) {
        minDis = disToEntity;
        nearestEntity = entity;
      }
    }
  }

  if (nearestEntity) {
    nearestEntity->SetAvailability(false);
    available = false;
    pickedUp = false;

    destination = nearestEntity->GetPosition();
    toTargetPosStrategy = new BeelineStrategy(this->GetPosition(), destination);
    std::string targetStrategyName = nearestEntity->GetStrategyName();
    if (targetStrategyName.compare("astar") == 0) {
        toTargetDestStrategy = new AstarStrategy(nearestEntity->GetPosition(),
         nearestEntity->GetDestination(), graph);
        toTargetDestStrategy = new SpinDecorator(toTargetDestStrategy);
    } else if (targetStrategyName.compare("dfs") == 0) {
        toTargetDestStrategy = new DfsStrategy(nearestEntity->GetPosition(),
         nearestEntity->GetDestination(), graph);
        toTargetDestStrategy = new JumpDecorator(toTargetDestStrategy);
    } else if (targetStrategyName.compare("dijkstra") == 0) {
        toTargetDestStrategy = new DijkstraStrategy(
          nearestEntity->GetPosition(), nearestEntity->GetDestination(), graph);
        toTargetDestStrategy = new SpinDecorator(toTargetDestStrategy);
        toTargetDestStrategy = new JumpDecorator(toTargetDestStrategy);
    }
  }
}

void Drone::Update(double dt, std::vector<IEntity*> scheduler) {
  float distance;
  Vector3 prevPos;
  if (available) {
    GetNearestEntity(scheduler);
  }

  if (toTargetPosStrategy) {
    // Collect data on Total distance
    prevPos = this->GetPosition();

    toTargetPosStrategy->Move(this, dt);

    distance = this->GetPosition().Distance(prevPos);
    s = Singleton::GetInstance("s");
    s->UpdateTotalDistance(*this, distance);
    s->UpdatePickupDistance(*this, distance);

    // Update Total Time
    s->UpdateTotalTime(*this, dt);

    if (toTargetPosStrategy->IsCompleted()) {
      delete toTargetPosStrategy;
      toTargetPosStrategy = NULL;
    }
  } else if (toTargetDestStrategy) {
    // std::cout << "moving to dest" << std::endl;
    // if (toTargetDestStrategy != NULL) {
    //   std::cout << "deststrat not null" <<  std::endl;
    // } else {
    //   std::cout << "deststrat is null?" << std::endl;
    // }

    prevPos = this->GetPosition();

    toTargetDestStrategy->Move(this, dt);

    distance = this->GetPosition().Distance(prevPos);
    s = Singleton::GetInstance("s");
    s->UpdateTotalDistance(*this, distance);
    s->UpdateTripDistance(*this, distance);

    // Update Trip Time and Total Time
    s->UpdateTotalTime(*this, dt);
    s->UpdateTripTime(*this, dt);

    // Moving the robot
    nearestEntity->SetPosition(this->GetPosition());
    nearestEntity->SetDirection(this->GetDirection());
    if (toTargetDestStrategy->IsCompleted()) {
      delete toTargetDestStrategy;
      toTargetDestStrategy = NULL;
      available = true;
      nearestEntity = NULL;
      s->UpdateTotalTrips(*this);
    }
  }
}

void Drone::Rotate(double angle) {
  Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}

void Drone::Jump(double height) {
  if (goUp) {
    position.y += height;
    jumpHeight += height;
    if (jumpHeight > 5) {
      goUp = false;
    }
  } else {
    position.y -= height;
    jumpHeight -= height;
    if (jumpHeight < 0) {
      goUp = true;
    }
  }
}

std::map<std::string, float>& Drone::GetData() {
  return data;
}
