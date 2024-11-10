#include <iostream>
#include <cmath>  // For M_PI

// Base class
class Shape {
public:
    // Virtual method to calculate area, to be overridden in derived classes
    virtual double calculateArea() const = 0;

    // Virtual destructor for proper cleanup of derived class objects
    virtual ~Shape() {}
};

// Derived class for Circle
class Circle : public Shape {
public:
    double calculateArea() const override {
        double radius = 5.0;  // Example radius for circle
        return M_PI * radius * radius;  // Area = π * r^2
    }
};

// Derived class for Rectangle
class Rectangle : public Shape {
public:
    double calculateArea() const override {
        double length = 4.0;
        double width = 6.0;
        return length * width;  // Area = length * width
    }
};

// Derived class for Square
class Square : public Shape {
public:
    double calculateArea() const override {
        double side = 4.0;  // Example side length for square
        return side * side;  // Area = side^2
    }
};

// Function to calculate area using base class pointer (runtime polymorphism)
void printArea(const Shape* shape) {
    std::cout << "Area: " << shape->calculateArea() << std::endl;
}

int main() {
    // Create objects for each shape
    Circle circle;
    Rectangle rectangle;
    Square square;

    // Use the base class pointer to call the overridden method
    printArea(&circle);
    printArea(&rectangle);
    printArea(&square);

    return 0;
}
