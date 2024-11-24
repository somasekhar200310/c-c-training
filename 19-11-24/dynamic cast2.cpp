#include <iostream>
#include <typeinfo>

class Shape {
public:
    virtual void draw() { std::cout << "Drawing a shape" << std::endl; }
    virtual ~Shape() {}  // Virtual destructor to enable polymorphism
};

class Circle : public Shape {
public:
    void draw() override { std::cout << "Drawing a circle" << std::endl; }
    void area() { std::cout << "Calculating area of the circle" << std::endl; }
};

class Rectangle : public Shape {
public:
    void draw() override { std::cout << "Drawing a rectangle" << std::endl; }
    void perimeter() { std::cout << "Calculating perimeter of the rectangle" << std::endl; }
};

int main() {
    // Create a Shape pointer that points to a Circle object
    Shape* shapePtr = new Circle;  

    // Perform downcast from Shape* to Circle* using dynamic_cast
    Circle* circlePtr = dynamic_cast<Circle*>(shapePtr);
    if (circlePtr) {
        circlePtr->draw();     // Output: Drawing a circle
        circlePtr->area();     // Output: Calculating area of the circle
    } else {
        std::cout << "Failed to cast to Circle" << std::endl;
    }

    // Now try casting to Rectangle*, which will fail
    Rectangle* rectanglePtr = dynamic_cast<Rectangle*>(shapePtr);
    if (rectanglePtr) {
        rectanglePtr->draw();     // This won't be executed
        rectanglePtr->perimeter(); // This won't be executed
    } else {
        std::cout << "Failed to cast to Rectangle" << std::endl;  // Output: Failed to cast to Rectangle
    }

    // Cleanup
    delete shapePtr;

    return 0;
}
