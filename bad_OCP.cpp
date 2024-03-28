#include <iostream>
#include <string>

class ShapePrinter {
public:
    void printShape(const std::string& shapeType) {
        if (shapeType == "circle") {
            std::cout << "Drawing a circle." << std::endl;
        } else if (shapeType == "square") {
            std::cout << "Drawing a square." << std::endl;
        }
    }
};

int main() {
    ShapePrinter printer;
    printer.printShape("circle");
    printer.printShape("square"); // What if we want to print a triangle?
    return 0;
}
