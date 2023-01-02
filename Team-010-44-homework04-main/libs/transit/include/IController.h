#ifndef LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_
#define LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_

#include "IEntity.h"
#include "util/json.h"

//--------------------  Controller Interface ----------------------------

/**
 * @brief Abstract controller class used in the Transit Service.  Uses the Model View
   Controller Pattern
 */
class IController {
 public:
  /**
   * @brief Destructor. Destroy the IController object
   * 
   */
  virtual ~IController() {}

  /**
   * @brief Adds an entity to the program
   * @param[in] entity the entity to be added
   */
  virtual void AddEntity(const IEntity& entity) = 0;

  /**
   * @brief Updates the entity
   * @param[in] entity entity to be updated
  */
  virtual void UpdateEntity(const IEntity& entity) = 0;

  /**
   * @brief Removes an entity from the program
   * @param[in] id of the entity to be removed
   */
  virtual void RemoveEntity(int id) = 0;

  /**
   * @brief Adds a path to the program
   * @param[in] id id of the path
   * @param[in] path a 2D vector containing the path to be added
   */
  virtual void AddPath(int id,
                       const std::vector<std::vector<float> >& path) = 0;

  /**
   * @brief Removes a path from the program
   * @param[in] id id of the path to be removed
   */
  virtual void RemovePath(int id) = 0;

  /**
   * @brief Allows messages to be passed back to the view
   * @param[in] event the message to be sent to the view
   * @param[in] details the view to which to send the message to
   */
  virtual void SendEventToView(const std::string& event,
                               const JsonObject& details) = 0;
};

#endif  // LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_
