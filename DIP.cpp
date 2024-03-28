// To adhere to DIP, we introduce an abstraction (interface) that both the high-level and low-level modules depend on. This decouples the high-level module from the low-level module, making our system more flexible and maintainable.

#include <iostream>

// Abstraction (Interface)
class StorageDevice {
public:
    virtual void readData() const = 0;
};

// Low-level module implements the abstraction
class HardDrive : public StorageDevice {
public:
    void readData() const override {
        std::cout << "Reading data from Hard Drive." << std::endl;
    }
};

// Another low-level module
class SSD : public StorageDevice {
public:
    void readData() const override {
        std::cout << "Reading data from SSD." << std::endl;
    }
};

// High-level module depends on abstraction, not on concrete implementation
class Computer {
private:
    const StorageDevice& storageDevice;
public:
    Computer(const StorageDevice& sd) : storageDevice(sd) {}
    void start() {
        storageDevice.readData(); // Uses abstraction
        std::cout << "Computer started." << std::endl;
    }
};

int main() {
    HardDrive myHardDrive;
    SSD mySSD;
    Computer myComputer(myHardDrive); // We can easily switch to SSD without changing Computer class
    myComputer.start();
    return 0;
}


// The Computer class doesn't directly depend on a specific storage device. Instead, it works with any storage device that follows the StorageDevice interface. This is much more flexible because you can easily switch from a HardDrive to an SSD (or any other storage device) without changing the Computer class's code.
// This adherence to DIP makes our code more modular, easier to maintain, and ready for future changes or extensions.