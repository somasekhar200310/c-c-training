#include <iostream>

class Shape {
public:
    // Virtual function to draw the shape, overridden by derived classes
    virtual void draw() const {
        std::cout << "Drawing a Shape" << std::endl;
    }

    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    // Override the draw function for Circle
    void draw() const override {
        std::cout << "Drawing a Circle" << std::endl;
    }
};

class Rectangle : public Shape {
public:
    // Override the draw function for Rectangle
    void draw() const override {
        std::cout << "Drawing a Rectangle" << std::endl;
    }
};

int main() {
    // Create instances of derived classes
    Shape* shape1 = new Circle();       // Pointer to Shape, but object is a Circle
    Shape* shape2 = new Rectangle();    // Pointer to Shape, but object is a Rectangle

    // Call the draw method via base class pointer
    shape1->draw();  // Expected: Drawing a Circle
    shape2->draw();  // Expected: Drawing a Rectangle

    // Clean up memory
    delete shape1;
    delete shape2;

    return 0;
}
