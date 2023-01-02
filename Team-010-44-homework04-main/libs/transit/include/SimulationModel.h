#ifndef LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
#define LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_

#include "IController.h"
#include "CompositeFactory.h"
#include "IEntity.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------

/**
 * @brief Simulation Model handling the transit simulation.  The model can communicate
 * with the controller.
 */
class SimulationModel {
 public:
 /**
  * @brief Parameter constructor.
  * Construct a new Simulation Model object
  * 
  * @param[in] controller Controller that the model communicates with
  */
  SimulationModel(IController& controller);

  /**
   * @brief Set the model's graph
   * 
   * @param[in] graph graph to be set
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /**
   * @brief Creates an simulation entity
   * 
   * @param[in] entity entity to be created
   */
  void CreateEntity(JsonObject& entity);

  /**
   * @brief Schedules a trip for an object in the scene
   * 
   * @param[in] details a JsonObject containing the properties/details for the object
   */
  void ScheduleTrip(JsonObject& details);

  /**
   * @brief Updates the simulation
   * 
   * @param[in] dt delta time. The change in time between each frame
   */
  void Update(double dt);

  /**
   * @brief Adds a new entity type
   * @param[in] factory the entity type to be added
   */
  void AddFactory(IEntityFactory* factory);

  /**
   * @brief Writes to CSV file
   *
   */
  void Write2CSV();

 protected:
  IController& controller;  //!< Controller for the simulation
  std::vector<IEntity*> entities;  //!< Vector of entities in the simulation
  std::vector<IEntity*> scheduler;  //!< Vector of entities scheduled for a trip
  const IGraph* graph;  //!< Graph of the map
  CompositeFactory* compFactory;  //!< CompositeFactory used to create entities
};

#endif  // LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
