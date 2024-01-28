#ifndef LIBS_TRANSIT_INCLUDE_SINGLETON_H_
#define LIBS_TRANSIT_INCLUDE_SINGLETON_H_

#include <iostream>
#include <mutex>
#include <fstream>
#include "Drone.h"

/**
 * @brief The Singleton class defines the `GetInstance` method that serves as an
 * alternative to constructor and lets clients access the same instance of this
 * class over and over.
 * 
 * Note: Singleton.h and Singleton.cc were derived from the Singleton code example
 * providied by Refactoring.Guru. The base code was then modified to fit our
 * extension.
 */
class Singleton {
    /**
     * The Singleton's constructor/destructor should always be private to
     * prevent direct construction/desctruction calls with the `new`/`delete`
     * operator.
     */
 private:
    static Singleton * pinstance_;
    static std::mutex mutex_;

 protected:
    /**
     * @brief Singleton constructor
     * 
     * @param[in] value the value used to differentiate between Singletons
     * 
     */
    Singleton(const std::string value): value_(value) {}
    ~Singleton() {}
    std::string value_;
    std::vector<Drone*> droneList;

 public:
    /**
     * @brief Singletons should not be cloneable.
     */
    Singleton(Singleton &other) = delete;

    /**
     * @brief Singletons should not be assignable.
     */
    void operator=(const Singleton &) = delete;

    /**
     * @brief This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     * 
     * @param[in] value value used to differentiate between Singletons
     * 
     * @return an instance of the Singleton
     */
    static Singleton *GetInstance(const std::string& value);

    /**
     * @brief Writes data to a csv file
     */
    void write2CSV();

    /**
     * @brief Adds a drone to the droneList
     * @param[in] drone the drone to be added
     */
    void AddDrone(Drone* drone) {
        droneList.push_back(drone);
    }

    /**
     * @brief Return Singleton's value
     * 
     * @return string representing this->value
     */
    std::string value() const {
        return value_;
    }

    /**
     * @brief Updates the drone's totalDistance traveled
     * 
     * @param[in] drone a reference to the drone
     * @param[in] distance the distance to be added
     */
    void UpdateTotalDistance(Drone& drone, float distance);

    /**
     * @brief Updates distance traveled durring pickup
     * 
     * @param[in] drone a reference to the drone
     * @param[in] distance the distance to be added
     */
    void UpdatePickupDistance(Drone& drone, float distance);

    /**
     * @brief Update distance traveled via trips only
     * 
     * @param[in] drone a reference to the drone
     * @param[in] distance the distance to be added
     */
    void UpdateTripDistance(Drone& drone, float distance);

    /**
     * @brief Increments the drone number of trips by 1
     * 
     * @param[in] drone a reference to the drone
     */
    void UpdateTotalTrips(Drone& drone);

    /**
     * @brief Updates the total time
     * 
     * @param[in] drone a reference to the drone
     * @param[in] time the time to be added
     */
    void UpdateTotalTime(Drone& drone, double time);

    /**
     * @brief Updates the total time spent on trips
     * * 
     * @param[in] drone a reference to the drone
     * @param[in] time the time to be added
     */
    void UpdateTripTime(Drone& drone, double time);
};

#endif  // LIBS_TRANSIT_INCLUDE_SINGLETON_H_
