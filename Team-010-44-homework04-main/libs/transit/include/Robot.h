#ifndef LIBS_TRANSIT_INCLUDE_ROBOT_H_
#define LIBS_TRANSIT_INCLUDE_ROBOT_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
/**
 * @brief Class that represents a robot.
 * Robots move using euler integration based on a specified
 * velocity and direction.
 */
class Robot : public IEntity {
 public:
  /**
   * @brief Parameter constructor
   * Construct a new Robot object
   * 
   * @param[in] obj the Robot's name
   */
  Robot(JsonObject& obj);

  /**
   * @brief Destructor
   * Override and destroy the Robot object
   */
  ~Robot() override = default;

  /**
   * @brief Get the Robot's position
   * 
   * @return Vector3 Object containing the Robot's position
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the Robot's direction
   * 
   * @return Vector3 Object containing the Robot's direction
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the Robot's destination
   * 
   * @return Vector3 Object containing the Robot's destination
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Get the Robot's availibility status
   * 
   * @return The Robot's status. true - available, talse - unavailable
   */
  bool GetAvailability() const { return available; }

  /**
   * @brief Overrides GetDatils() from IEntity
   * 
   * @return JsonObject
   */
  JsonObject GetDetails() const override;

   /**
   * @brief Get the Robot's speed
   * 
   * @return the Robot's speed
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Get Robot's strategy name
   * 
   * @return a string contianing the Robot's strategy name
  */
  std::string GetStrategyName() {return strategyName;}

  /**
   * @brief Set the Robot's availibility
   * 
   * @param[in] choice true for available, false for unavailable
   */
  void SetAvailability(bool choice);

  /**
   * @brief Set the Robot's position
   * 
   * @param[in] pos_ a Vector3 Object containing the position to be set
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Set the Robot's direction
   * 
   * @param[in] dir_ a Vector3 Object containing the direction to be set
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Set the robot's destination
   * 
   * @param[in] des_ a Vector3 Object containing the destination to be set
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Set Robot's strategy name
   * 
   * @param[in] the strategy name to be set
  */
  void SetStrategyName(std::string strategyName_) {
    strategyName = strategyName_;
  }

  /**
   * @brief Rotate the robot
   * 
   * @param[in] angle the angle in which to rotate the Robot
   */
  void Rotate(double angle);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
};

#endif  // LIBS_TRANSIT_INCLUDE_ROBOT_H_
