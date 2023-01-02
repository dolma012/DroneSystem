#ifndef LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_

#include "IStrategy.h"

/**
 * @brief Base Decorator using Decorator Pattern
*/
class CelebrationDecorator : public IStrategy {
 protected:
  IStrategy* strategy;  //!< The IStrategy we want to add the decorator onto
  float time;  //!< time count check; how long since last celebration occured

 public:
 /**
  * @brief Constructor, sets time to 0
  * @param[in] strategy the IStartegy we want to add the deocrator onto
 */
  CelebrationDecorator(IStrategy* strategy);

  /**
   * @brief Destructor
  */
  ~CelebrationDecorator();

  /**
   * @brief Move the entity using this strategy to celebrate
   * @param[in] entity IEntity we want to move/celebrate
   * @param[in] dt delta time 
  */
  void Move(IEntity* entity, double dt);

  /**
   * @brief Checks if current strategy is completed
  */
  bool IsCompleted();
};

#endif  // LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_

