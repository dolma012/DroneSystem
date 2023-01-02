#ifndef LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"

#include <vector>

/**
 * @brief Component Robot Factory that creates Robots
*/
class RobotFactory : public IEntityFactory {
 public:
    /**
     * @brief Checks if the JsonObject argument, entity is of type "robot", then creates Robot entity
     * @param[in] entity The entity to be created
     */
    IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
