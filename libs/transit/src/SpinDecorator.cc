#include "SpinDecorator.h"

SpinDecorator::
  SpinDecorator(IStrategy* strategy) : CelebrationDecorator(strategy) {}

SpinDecorator::~SpinDecorator() {}

void SpinDecorator::Move(IEntity* entity, double dt) {
  if (this->strategy->IsCompleted()) {
    if (!IsCompleted()) {
      entity->Rotate(5 * dt);
      time += dt;
    }
  } else {
    this->strategy->Move(entity, dt);
  }
}

bool SpinDecorator::IsCompleted() {
  return time >= 1.5;
}
