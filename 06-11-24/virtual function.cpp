#include <iostream>
using namespace std;

class Shape {
public:
    // Virtual function to be overridden in derived classes
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }

    // Virtual destructor to ensure proper cleanup of derived class objects
    virtual ~Shape() {
        cout << "Shape destructor" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {  // Overriding the draw function
        cout << "Drawing a circle" << endl;
    }

    ~Circle() {
        cout << "Circle destructor" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {  // Overriding the draw function
        cout << "Drawing a rectangle" << endl;
    }

    ~Rectangle() {
        cout << "Rectangle destructor" << endl;
    }
};

int main() {
    // Creating an array of Shape pointers, but pointing to different derived objects
    Shape* shapes[3];
    shapes[0] = new Shape();          // Base class object
    shapes[1] = new Circle();         // Derived class Circle
    shapes[2] = new Rectangle();      // Derived class Rectangle

    // Calling draw function on each shape
    for (int i = 0; i < 3; ++i) {
        shapes[i]->draw();            // Virtual function, calls the appropriate function
    }

    // Cleanup
    for (int i = 0; i < 3; ++i) {
        delete shapes[i];             // Destructor will also be called correctly
    }

    return 0;
}
