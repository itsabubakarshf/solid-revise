#include <iostream>

// Low-level module
class HardDrive {
public:
    void readData() const {
        std::cout << "Reading data from Hard Drive." << std::endl;
    }
};

// High-level module directly depends on the low-level module
class Computer {
private:
    HardDrive hd;
public:
    void start() {
        hd.readData(); // Direct dependency
        std::cout << "Computer started." << std::endl;
    }
};

int main() {
    Computer myComputer;
    myComputer.start(); // This directly uses HardDrive
    return 0;
}
