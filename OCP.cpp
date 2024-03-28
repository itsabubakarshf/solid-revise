#include <iostream>
#include <vector>

class Shape {
public:
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a square." << std::endl;
    }
};

class ShapePrinter {
public:
    void printShape(const Shape& shape) {
        shape.draw(); // No modification needed to add new shapes
    }
};

int main() {
    Circle circle;
    Square square;
    ShapePrinter printer;
    printer.printShape(circle);
    printer.printShape(square); // Easily extendable for more shapes
    return 0;
}
