#ifndef LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_

#include "util/json.h"

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"

//--------------------  EntityFactory Interface ----------------------------

/**
 * @brief Abstract Entity Factory class used in CompositeFactory,
 * DroneFactory, and RobotFactory. Uses the Composit Factory pattern
*/
class IEntityFactory {
 public:
  /**
  * @brief IEntityFactory destructor
  */
  virtual ~IEntityFactory() {}

  /**
   * @brief Generic entity creation which should be overwritten in
   * the component factories
   * 
   * @param[in] entity the generic entity to be created
 */
  virtual IEntity* CreateEntity(JsonObject& entity) = 0;
};

#endif  // LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_
