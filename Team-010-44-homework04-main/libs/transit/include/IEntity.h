#ifndef LIBS_TRANSIT_INCLUDE_IENTITY_H_
#define LIBS_TRANSIT_INCLUDE_IENTITY_H_

#include <vector>

#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"
using namespace routing;

//--------------------  Controller Interface ----------------------------

/**
 * @brief Represents an entity
 * Abstract controller class used in the Transit Service.  Uses the Model View
 * Controller Pattern 
 */
class IEntity {
 public:
 /**
  * @brief Default constructor
  * Construct a new IEntity object
  */
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }

  /**
   * @brief Destructor
   * Destroy the IEntity object
   */
  virtual ~IEntity() {}

  /**
   * @brief Gets the entity's id
   * 
   * @return The entity's id
   */
  virtual int GetId() const { return id; }

  /**
   * @brief Get the entity's position
   * 
   * @return Vector3 Object containing the entity's position
   */
  virtual Vector3 GetPosition() const = 0;

  /**
   * @brief Gets the entity's direction
   * 
   * @return Vector3 Object containing the entity's direction
   */
  virtual Vector3 GetDirection() const = 0;

  /**
   * @brief Gets the entity's destination
   * 
   * @return Vector3 Object containing the entity's destination
   */
  virtual Vector3 GetDestination() const = 0;

  /**
   * @brief Get the details of the entity
   * 
   * @return JsonObject of the properties of the entity
   */
  virtual JsonObject GetDetails() const = 0;

  /**
   * @brief Get the entity's speed
   * 
   * @return the entity's speed
   */
  virtual float GetSpeed() const = 0;

  /**
   * @brief Get the entity's availibility status
   * 
   * @return true - entity is available
   * @return false - entity is not available
   */
  virtual bool GetAvailability() const = 0;

  /**
   * @brief Get entity's strategy name
   * 
   * @return a string contianing a strategy name
  */
  virtual std::string GetStrategyName() {}

  /**
   * @brief Set the entity's availibility
   * 
   * @param[in] choice true for available, false for unavailable
   */
  virtual void SetAvailability(bool choice) {}

  /**
   * @brief Update the entity
   * 
   * @param[in] dt delta time. The change in time between each frame
   * @param[in] scheduler A vector containing pointers to entities
   */
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}

  /**
   * @brief Set the entity's graph
   * 
   * @param[in] graph the graph to be set
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /**
   * @brief Set the entity's position
   * 
   * @param[in] pos_ a Vector3 Object containing the position to be set
   */
  virtual void SetPosition(Vector3 pos_) {}

  /**
   * @brief Set the entity's direction
   * 
   * @param[in] dir_ a Vector3 Object containing the direction to be set
   */
  virtual void SetDirection(Vector3 dir_) {}

  /**
   * @brief Set the entity's destination
   * 
   * @param[in] des_ a Vector3 Object containing the destination to be set
   */
  virtual void SetDestination(Vector3 des_) {}

  /**
   * @brief Set entity strategy name
   * 
   * @param[in] The startegy name to be set
  */
  virtual void SetStrategyName(std::string strategyName_) {}

  /**
   * @brief Rotate the entity
   * 
   * @param[in] dt delta time. The change in time between each frame
   */
  virtual void Rotate(double dt) {}

  /**
   * @brief Make the entity jump
   * 
   * @param[in] height how high to jump
  */
  virtual void Jump(double height) {}

 protected:
  int id;  //!< Entity's id
  const IGraph* graph;  //!< Pointer to graph of Entity
};

#endif  // LIBS_TRANSIT_INCLUDE_IENTITY_H_
