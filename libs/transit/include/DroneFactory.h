#ifndef LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"

#include <vector>

/**
 * @brief Component Drone Factory that creates Drones
*/
class DroneFactory : public IEntityFactory {
 public:
    /**
     * @brief DroneFactory deconstructor
    */
    virtual ~DroneFactory() {}

    /**
     * @brief Checks if the JsonObject argument, entity is a of type "drone", then creates Drone entity
     * @param[in] entity The entity to be created
    */
    IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
