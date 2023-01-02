#ifndef LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_

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
class BeelineStrategy : public IStrategy {
 public:
  /**
   * @brief Constructor for BeelineStrategy. Sets position and destination.
   * 
   * @param[in] position_ starting position
   * @param[in] destination_ final destination
  */
  BeelineStrategy(Vector3 position_, Vector3 destination_);

  /**
   * @brief Destructor for BeelineStrategy
  */
  ~BeelineStrategy();

  /**
   * @brief Function to move toward the next drone/position
   * 
   * @param[in] entity The entity to be moved
   * @param[in] dt Delta time
  */
  void Move(IEntity* entity, double dt);

  /**
   * @brief Check if the position/node has arrived to destination
   * position/node
   * 
   * @return boolean true for completed, false for not completed
  */
  bool IsCompleted();

 private:
  Vector3 position;
  Vector3 destination;
};  // end class

#endif  // LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_
