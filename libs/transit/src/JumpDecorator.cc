#include "JumpDecorator.h"

JumpDecorator::
  JumpDecorator(IStrategy* strategy) : CelebrationDecorator(strategy) {}

JumpDecorator::~JumpDecorator() {}

void JumpDecorator::Move(IEntity* entity, double dt) {
  if (this->strategy->IsCompleted()) {
    if (!IsCompleted()) {
      entity->Jump(10 * dt);
      time += dt;
    }
  } else {
    this->strategy->Move(entity, dt);
  }
}

bool JumpDecorator::IsCompleted() {
  return time >= 1.5;
}
