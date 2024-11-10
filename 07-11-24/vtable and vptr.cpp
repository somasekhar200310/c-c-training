#include <iostream>

class Shape {
public:
    // Virtual function for drawing shape
    virtual void draw() {
        std::cout << "Drawing Shape" << std::endl;
    }

    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    // Override the draw function for Circle
    void draw() override {
        std::cout << "Drawing Circle" << std::endl;
    }
};

class Rectangle : public Shape {
public:
    // Override the draw function for Rectangle
    void draw() override {
        std::cout << "Drawing Rectangle" << std::endl;
    }
};

void drawShape(Shape* shape) {
    // Calls the appropriate 'draw' method depending on the actual object type
    shape->draw();
}

int main() {
    Shape* shape1 = new Circle();       // Create a Circle object
    Shape* shape2 = new Rectangle();    // Create a Rectangle object

    drawShape(shape1);  // Should call Circle's draw()
    drawShape(shape2);  // Should call Rectangle's draw()

    delete shape1;  // Cleanup dynamically allocated memory
    delete shape2;

    return 0;
}
