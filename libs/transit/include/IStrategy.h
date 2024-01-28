#ifndef LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_

#include <vector>
#include "graph.h"
#include "IEntity.h"

using namespace routing;

/**
 * @brief Strategy interface that is implemented by BeelineStrategy, DijkstraStrategy
 * AStarStrategy and DFSStrategy. Uses the Strategy design pattern.
 * Allows client to choose which routing algorithm that is used by the Drone to transport the Robot
*/
class IStrategy {
 public:
   /**
     * @brief Function to move toward the next drone/position
     * 
     * @param[in] entity The entity to be moved
     * @param[in] dt Delta time
    */
    virtual void Move(IEntity* entity, double dt) = 0;

   /**
     * @brief Check if the position/node has arrived to destination
     * position/node
     * 
     * @return boolean true for completed, false for not completed
    */
    virtual bool IsCompleted() = 0;
 protected:
    // IGraph object to be used in the simulation.
    const IGraph* graph;  //!< Graph of the map
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_
