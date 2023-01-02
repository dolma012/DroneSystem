#ifndef LIBS_TRANSIT_INCLUDE_DRONE_H_
#define LIBS_TRANSIT_INCLUDE_DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief A class that represents a drone in a physical system.
   Drones move using euler integration based on a specified
   velocity and direction
*/
class Drone : public IEntity {
 public:
  /**
   * @brief Parameter constructor.
   * Drones are created with a name
   * 
   * @param[in] obj Name of the drone
   */
  Drone(JsonObject& obj);

  /**
   * @brief Destructor
   */
  ~Drone();

  /**
   * @brief Gets the drone speed 
   * 
   * @return the drone speed
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Gets the drone position
   * 
   * @return a Vector3 Object containing the drone position. 
   * x and y coordinates 
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the drone direction
   * 
   * @return Vector3 Object of the drone direction
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the drone destination
   * 
   * @return Vector3 Object of drone destination
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Get drone details
   * 
   * @return JsonObject of drone properties
   */
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Gets the drone availability
   * 
   * @return true - the drone is available
   * @return false - the drone is not available
   */
  bool GetAvailability() const { return available; }

  /**
   * @brief Gets the nearest entity
   * 
   * @param[in] scheduler A vector of pointers to IEntitys (entities)
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  /**
   * @brief Updates the drone's position
   * 
   * @param[in] dt Delta time. The change in time between each frame
   * @param[in] scheduler A vector of pointers to entities
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Set the drone's position
   * 
   * @param[in] pos_ Vectory3 object containing position
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Set the drone's direction
   * 
   * @param[in] dir_ Vector3 object containing direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Set the dron'es destination
   * 
   * @param[in] des_ Vector3 object containing destination
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Rotates the Drone
   * @param[in] angle angle in which to rotate the Drone
   * 
   */
  void Rotate(double angle);

  /**
   * @brief Make the drone jump
   * @param[in] height how tall the drone should jump
   */
  void Jump(double height);

  /**
   * @brief Gets the drone's data map
   * @return data 
   */
  std::map<std::string, float>& GetData();
  
  /**
   * @brief Removing the copy constructor
   * so that drones cannot be copied
   */
  Drone(const Drone& drone) = delete;
   
  /**
   * @brief Removing the assignment operator
   * so that drones cannot be copied
   */
  Drone& operator=(const Drone& drone) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  float jumpHeight = 0;
  bool goUp = true;  // jump helper
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  std::string strategyName;
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
  std::map<std::string, float> data;
};

#endif  // LIBS_TRANSIT_INCLUDE_DRONE_H_
