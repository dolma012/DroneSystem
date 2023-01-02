#include "BaseDecorator.h"

BaseDecorator::BaseDecorator(IEntity* entity) : entity(entity) {
    this->entity = entity;
}
BaseDecorator::~BaseDecorator() {}

void BaseDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    this->entity->Update(dt, scheduler);
}
