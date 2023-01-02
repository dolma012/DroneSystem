#ifndef LIBS_TRANSIT_INCLUDE_BASEDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_BASEDECORATOR_H_

#include "IEntity.h"

/**
 * @brief Base Decorator using Decorator Pattern
*/
class BaseDecorator : public IEntity {
 public:
  BaseDecorator(IEntity* entity);
  ~BaseDecorator();
  /**
    * @brief Constructor, sets time to 0
    * @param[in] entity the IEntity we want to add the deocrator onto
  */
  void Update(double dt, std::vector<IEntity*> scheduler);

 protected:
  IEntity* entity;
  int id;
  const IGraph* graph;
  int numRobots;
  Vector3 nextDest;
  std::vector<int> robotlist;
  bool pickup;
};

#endif  // LIBS_TRANSIT_INCLUDE_BASEDECORATOR_H_

