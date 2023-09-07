/*
Problem Statement:
We want to build a cab booking platform to allow a rider to book a cab.
Details:
The location is represented as a (x, y) coordinate.
Distance between two points (x1, y1) and(x2, y2) is sqrt((x1-x2)² + (y1-y2)²)
Platform has decided upon maximum distance a driver has to travel to pickup a rider.
A cab has only 1 driver.
Sharing of cab is not allowed between riders
There is a single type of cab
Please build an application that exposes following features to riders and drivers.
1. Register a rider.
2. Register a driver/cab
3. Update a cab’s location
4. A driver can switch on/off his availability
5. A rider can book a cab
6. Fetch history of all rides taken by a rider.
7. End the Trip
Expectation from this round
1. Demonstrable code is first expectation.
2. Code should be extensible.
3. Clean professional level code.
4. Functional Completeness including good modelling.
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

class Location {
public:
    Location(double x, double y) : x(x), y(y) {}
    
    double getX() const {
        return x;
    }
    
    double getY() const {
        return y;
    }
    
    double calculateDistance(const Location& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }
    
private:
    double x;
    double y;
};

class Cab {
public:
    Cab(int id) : id(id), available(false) {}
    
    int getId() const {
        return id;
    }
    
    bool isAvailable() const {
        return available;
    }
    
    void setAvailability(bool status) {
        available = status;
    }
    
    const Location& getLocation() const {
        return location;
    }
    
    void updateLocation(const Location& newLocation) {
        location = newLocation;
    }
    
private:
    int id;
    bool available;
    Location location;
};

class Rider {
public:
    Rider(int id) : id(id) {}
    
    int getId() const {
        return id;
    }
    
    void bookCab(Cab& cab) {
        if (cab.isAvailable()) {
            double distance = cab.getLocation().calculateDistance(location);
            if (distance <= maxDistance) {
                cab.setAvailability(false);
                bookedCab = &cab;
            } else {
                std::cout << "Cab is too far away." << std::endl;
            }
        } else {
            std::cout << "Cab is not available." << std::endl;
        }
    }
    
    void endTrip() {
        if (bookedCab) {
            bookedCab->setAvailability(true);
            bookedCab = nullptr;
        }
    }
    
private:
    int id;
    Location location;
    Cab* bookedCab = nullptr;
    const double maxDistance = 10.0; // Maximum distance a driver has to travel
};

class RideHistory {
public:
    void addRide(int riderId, int cabId, double distance) {
        rides.push_back({riderId, cabId, distance});
    }
    
    void printRideHistory(int riderId) {
        std::cout << "Ride History for Rider " << riderId << ":\n";
        for (const auto& ride : rides) {
            if (ride.riderId == riderId) {
                std::cout << "Cab " << ride.cabId << ", Distance: " << ride.distance << " km\n";
            }
        }
    }
    
private:
    struct Ride {
        int riderId;
        int cabId;
        double distance;
    };
    
    std::vector<Ride> rides;
};

class Platform {
public:
    void registerRider(int id) {
        riders[id] = Rider(id);
    }
    
    void registerCab(int id) {
        cabs[id] = Cab(id);
    }
    
    void updateCabLocation(int cabId, const Location& location) {
        if (cabs.find(cabId) != cabs.end()) {
            cabs[cabId].updateLocation(location);
        }
    }
    
    void toggleDriverAvailability(int cabId, bool status) {
        if (cabs.find(cabId) != cabs.end()) {
            cabs[cabId].setAvailability(status);
        }
    }
    
    void bookCab(int riderId, int cabId) {
        if (riders.find(riderId) != riders.end() && cabs.find(cabId) != cabs.end()) {
            riders[riderId].bookCab(cabs[cabId]);
        }
    }
    
    void endTrip(int riderId) {
        if (riders.find(riderId) != riders.end()) {
            riders[riderId].endTrip();
        }
    }
    
    void recordRide(int riderId, int cabId, double distance) {
        rideHistory.addRide(riderId, cabId, distance);
    }
    
    void printRideHistory(int riderId) {
        rideHistory.printRideHistory(riderId);
    }
    
private:
    std::unordered_map<int, Rider> riders;
    std::unordered_map<int, Cab> cabs;
    RideHistory rideHistory;
};

int main() {
    Platform platform;

    // Register riders and cabs
    platform.registerRider(1);
    platform.registerRider(2);
    platform.registerCab(101);
    platform.registerCab(102);

    // Update cab locations
    platform.updateCabLocation(101, Location(1.0, 2.0));
    platform.updateCabLocation(102, Location(3.0, 4.0));

    // Toggle driver availability
    platform.toggleDriverAvailability(101, true);
    platform.toggleDriverAvailability(102, true);

    // Book a cab
    platform.bookCab(1, 101);

    // End the trip
    platform.endTrip(1);

    // Record and print ride history
    platform.recordRide(1, 101, 5.0);
    platform.printRideHistory(1);

    return 0;
}
