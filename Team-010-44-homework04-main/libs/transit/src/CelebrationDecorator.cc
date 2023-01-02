#include "CelebrationDecorator.h"

CelebrationDecorator::
CelebrationDecorator(IStrategy* strategy) : strategy(strategy) {
  this->strategy = strategy;
  time = 0;
}

CelebrationDecorator::~CelebrationDecorator() {}

void CelebrationDecorator::Move(IEntity* entity, double dt) {
  this->strategy->Move(entity, dt);
}

bool CelebrationDecorator::IsCompleted() {
  return time >= 1.5;
}
