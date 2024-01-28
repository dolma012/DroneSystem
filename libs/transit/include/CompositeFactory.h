#ifndef LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_

#include "IEntityFactory.h"

/**
 * @brief Concrete Composite Factory class which contains DroneFactory and RobotFactories
 * as its component factories. Uses the Composite Factory pattern
*/
class CompositeFactory : public IEntityFactory {
 public:
   /**
   * @brief Loops through its vector of factories and calls their CreateEntity()
   * untill it reaches the factory that matches the entity's type. An entity of the correct
   * type will then be created by the corresponding component factory.
   * 
   * @param[in] entity the entity to be created
  */
  IEntity* CreateEntity(JsonObject& entity);

  /**
   * @brief Add the factory into componentFactories
   * 
   * @param[in] factoryEntity factory to be added
  */
  void AddFactory(IEntityFactory* factoryEntity);

  /**
   * @brief Deconstructor for CompositeFactory
  */
  virtual ~CompositeFactory();

 private:
  std::vector<IEntityFactory*> componentFactories;
};

#endif  // LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_
