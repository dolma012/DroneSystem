#ifndef LIBS_TRANSIT_INCLUDE_DFSSTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_DFSSTRATEGY_H_

/**
 * include
 */
#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for generating the beeline that the drone will take.
 */
class DfsStrategy : public IStrategy {
 public:
    /**
     * @brief Constructor for DfsStrategy. Sets position and destination.
     * @param[in] position_ starting position
     * @param[in] destination_ final destination
     * @param[in] graph graph of the map
    */
    DfsStrategy(Vector3 position_, Vector3 destination_, const IGraph* graph);

    /**
     * @brief Destructor for DfsStrategy
    */
    ~DfsStrategy();

    /**
     * @brief Function to move toward the next drone/position
     * @param[in] entity The entity to be moved
     * @param[in] dt Delta time
    */
    void Move(IEntity* entity, double dt);

    /**
     * @brief Check if the position/node has arrived to destination
     * position/node
     * @return boolean true for completed, false for not completed
    */
    bool IsCompleted();

 private:
  std::vector<std::vector<float>> path;
  int currentIndex;
  int maxIndex;
};  // end class
#endif  // LIBS_TRANSIT_INCLUDE_DFSSTRATEGY_H_
