#ifndef LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_

#include "CelebrationDecorator.h"

/**
 * @brief Concrete decorator class that will celebrate by jumping
*/
class JumpDecorator : public CelebrationDecorator {
 public:
  /**
  * @brief Constructor, sets time to 0
  * @param[in] strategy the IStartegy we want to add the deocrator onto
  */
  JumpDecorator(IStrategy* strategy);

  /**
   * @brief Destructor
  */
  ~JumpDecorator();

  /**
   * @brief Move the entity by jumping to celebrate
   * @param[in] entity IEntity we want to move/celebrate
   * @param[in] dt delta time 
  */
  void Move(IEntity* entity, double dt);

  /**
   * @brief Checks if current strategy is completed
  */
  bool IsCompleted();
};

#endif  // LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_
