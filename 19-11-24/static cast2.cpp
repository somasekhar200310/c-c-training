#include <iostream>

class Base {
public:
    virtual void show() { std::cout << "Base class" << std::endl; }
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived class" << std::endl; }
};

int main() {
    Derived derivedObj;
    Base* basePtr = &derivedObj;

    // Upcasting: Derived to Base (implicit conversion, no need for static_cast)
    Base* basePtr2 = static_cast<Base*>(basePtr);  // basePtr is already of type Base*
    basePtr2->show();  // Output: Derived class

    // Downcasting: Base to Derived (using static_cast)
    Derived* derivedPtr = static_cast<Derived*>(basePtr);  // Upcasted Base* to Derived*
    derivedPtr->show();  // Output: Derived class

    return 0;
}
