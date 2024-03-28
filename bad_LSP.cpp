#include <iostream>
#include <stdexcept>

// Base class Vehicle
class Vehicle {
public:
    virtual void startEngine() const {
        std::cout << "Vehicle engine started." << std::endl;
    }
};

// Derived class Car from Vehicle
class Car : public Vehicle {
public:
    void startEngine() const override {
        std::cout << "Car engine started with a smooth purr." << std::endl;
    }
};

// Derived class Truck from Vehicle
class Truck : public Vehicle {
public:
    void startEngine() const override {
        std::cout << "Truck engine started with a powerful roar." << std::endl;
    }
};

// Derived class Bicycle from Vehicle - Violates LSP
class Bicycle : public Vehicle {
public:
    void startEngine() const override {
        throw std::logic_error("Bicycles don't have engines!");
    }
};

// Function that starts any vehicle's engine
void startAnyVehicleEngine(const Vehicle& vehicle) {
    vehicle.startEngine();
}

int main() {
    Car myCar;
    Truck myTruck;
    Bicycle myBicycle; // This doesn't really fit the Vehicle abstraction anymore

    // Using the function with different types of Vehicles
    startAnyVehicleEngine(myCar);     // Works with a Car
    startAnyVehicleEngine(myTruck);   // Works with a Truck
    // startAnyVehicleEngine(myBicycle); // Throws an exception, breaking the program's flow

    return 0;
}
