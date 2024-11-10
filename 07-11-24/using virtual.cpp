#include <iostream>

// Base class Object with a virtual method for calculating area
class Object {
public:
    virtual float Area() { 
        return 0.0f; 
    }

    virtual ~Object() {} // Virtual destructor for proper cleanup of derived objects
};

// Derived class Circle
class Circle : public Object {
public:
    float Area() override { 
        return 3.14159f * 10 * 10; // Area of the circle (π * r^2), example with radius = 10
    }
};

// Derived class Rect
class Rect : public Object {
public:
    float Area() override { 
        return 5.0f * 10.0f; // Example area for a rectangle with length 5 and width 10
    }
};

// Derived class Square
class Square : public Object {
public:
    float Area() override { 
        return 4.0f * 4.0f; // Area of a square with side length 4
    }
};

// Function that takes a pointer to Object and calls its Area method
void GetFun(Object *ptr) {
    // Calling the Area method, this will be polymorphic
    std::cout << "Area: " << ptr->Area() << std::endl;
}

int main() {
    // Create instances of Circle and Square
    Circle *pCircle = new Circle;
    Square *pSquare = new Square;

    // Calling GetFun with different object types
    GetFun(pSquare);  // This will call the Square's Area method
    GetFun(pCircle);  // This will call the Circle's Area method

    // Cleanup dynamically allocated memory
    delete pCircle;
    delete pSquare;

    return 0;
}
