#include "MyClass.h"
#include <iostream>

// Definition of the PImpl class (hidden from the user)
class MyClassImpl {
public:
    std::string data;  // The actual data

    MyClassImpl() : data("Initial Data") {}

    void setData(const std::string& newData) {
        data = newData;
    }

    std::string getData() const {
        return data;
    }

    void display() const {
        std::cout << "Data: " << data << std::endl;
    }
};

// MyClass constructor: Creates the PImpl object
MyClass::MyClass() : pImpl(std::make_unique<MyClassImpl>()) {}

// MyClass destructor: The PImpl object is automatically cleaned up
MyClass::~MyClass() = default;

// Set the data via the implementation
void MyClass::setData(const std::string& data) {
    pImpl->setData(data);
}

// Get the data via the implementation
std::string MyClass::getData() const {
    return pImpl->getData();
}

// Display the data via the implementation
void MyClass::display() const {
    pImpl->display();
}
