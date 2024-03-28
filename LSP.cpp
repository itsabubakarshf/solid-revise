// Let's create a C++ example that adheres to the Liskov Substitution Principle. We'll use a simplified scenario involving a Vehicle class and its subclasses. According to LSP, if we have a function that uses a Vehicle, it should work with objects of subclasses of Vehicle (like Car or Truck) without any problems.


// Here is the code for LSP
// This is good apprach, I want you to write complete code with bad approach as well
// So, I share how bad looks if we compare it with good


#include <iostream>

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

// Function that starts any vehicle's engine
void startAnyVehicleEngine(const Vehicle& vehicle) {
    vehicle.startEngine();
}

int main() {
    Car myCar;
    Truck myTruck;
    Vehicle myVehicle;

    // Using the function with different types of Vehicles
    startAnyVehicleEngine(myVehicle); // Works with a Vehicle
    startAnyVehicleEngine(myCar);     // Works with a Car
    startAnyVehicleEngine(myTruck);   // Works with a Truck

    return 0;
}
