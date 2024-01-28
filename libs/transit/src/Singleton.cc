#include "Singleton.h"

/**
 * Static methods should be defined outside the class.
 */

Singleton* Singleton::pinstance_{nullptr};
std::mutex Singleton::mutex_;

/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
Singleton* Singleton::GetInstance(const std::string& value) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new Singleton(value);
    }
    return pinstance_;
}

void Singleton::write2CSV() {
    std::ofstream myfile;
    myfile.open("output.csv");
    myfile << "Name,Number of Trips,Total Distance,Distance on Pickups,"
     << "Distance on Trips,Total Time,Trip Time\n";

     std::cout << "Name,Number of Trips,Total Distance,Distance on Pickups,"
     << "Distance on Trips,Total Time,Trip Time" << std::endl;

    // Iterate through the list of drones and output their data into CSV
    for (int i = 0; i < droneList.size(); i++) {
        std::map<std::string, float> data = droneList.at(i)->GetData();
        myfile << droneList.at(i)->GetDetails()["name"] << ","
         << data["number of trips"] << "," << data["total distance"] << ","
         << data["pickup distance"] << "," << data["distance on trips"]
         << "," << data["total time"] << "," << data["trip time"] << "\n";

        std::cout << droneList.at(i)->GetDetails()["name"] << ","
         << data["number of trips"] << "," << data["total distance"] << ","
         << data["pickup distance"] << "," << data["distance on trips"]
         << "," << data["total time"] << "," << data["trip time"] << std::endl;
    }
    myfile.flush();
    myfile.close();
}

void Singleton::UpdateTotalDistance(Drone& drone, float distance) {
    drone.GetData()["total distance"] += distance;
}

void Singleton::UpdatePickupDistance(Drone& drone, float distance) {
    drone.GetData()["pickup distance"] += distance;
}

void Singleton::UpdateTripDistance(Drone& drone, float distance) {
    drone.GetData()["distance on trips"] += distance;
}

void Singleton::UpdateTotalTrips(Drone& drone) {
    drone.GetData()["number of trips"] += 1;
    // std::cout << "Number of trips:" << drone.GetData()["number of trips"]
    // << std::endl;
}

void Singleton::UpdateTotalTime(Drone& drone, double time) {
    drone.GetData()["total time"] += time;
}

void Singleton::UpdateTripTime(Drone& drone, double time) {
    drone.GetData()["trip time"] += time;
}
