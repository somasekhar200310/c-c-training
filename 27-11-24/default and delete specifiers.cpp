#include <iostream>

class MyClass {
public:
    // Default constructor is explicitly defaulted
    MyClass() = default;

    // Copy constructor is deleted to prevent copying
    MyClass(const MyClass& other) = delete;

    // Custom constructor
    MyClass(int value) : data(value) {}

    // Method to display the data
    void display() const {
        std::cout << "MyClass data: " << data << std::endl;
    }

private:
    int data;
};

int main() {
    // Using the default constructor
    MyClass obj1;  // Calls the default constructor

    // Using the custom constructor
    MyClass obj2(10);  // Calls the custom constructor with an integer argument
    obj2.display();  // Outputs: MyClass data: 10

    // Uncommenting the following line will cause a compilation error
    // MyClass obj3 = obj2;  // Error: Copy constructor is deleted

    return 0;
}
