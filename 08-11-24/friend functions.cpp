#include <iostream>
using namespace std;

class Box {
private:
    double length;  // private attribute

public:
    Box(double l) : length(l) {}  // Constructor

    // Friend function declaration
    friend void printLength(Box b);
};

// Friend function definition
void printLength(Box b) {
    // Accessing private member of class Box
    cout << "Length of the box: " << b.length << endl;
}

int main() {
    Box b(10.5);  // Create an object of Box
    printLength(b);  // Call the friend function

    return 0;
}
