#include <iostream>
#include <typeinfo>  // For typeid

class Animal {
public:
    virtual void speak() { std::cout << "Animal speaks!" << std::endl; }
    virtual ~Animal() {}  // Virtual destructor for polymorphism
};

class Dog : public Animal {
public:
    void speak() override { std::cout << "Woof! Woof!" << std::endl; }
    void fetch() { std::cout << "Fetching the ball!" << std::endl; }
};

class Cat : public Animal {
public:
    void speak() override { std::cout << "Meow! Meow!" << std::endl; }
};

int main() {
    Animal* animalPtr = new Dog;  // Upcasting: Dog* to Animal*

    // Downcasting using dynamic_cast
    Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);  // Safe downcast from Animal* to Dog*
    if (dogPtr) {
        dogPtr->speak();  // Output: Woof! Woof!
        dogPtr->fetch();  // Output: Fetching the ball!
    } else {
        std::cout << "Failed to cast to Dog." << std::endl;
    }

    // Downcasting to a wrong type
    Cat* catPtr = dynamic_cast<Cat*>(animalPtr);  // Invalid cast: Dog* to Cat*
    if (catPtr) {
        catPtr->speak();  // Won't be executed
    } else {
        std::cout << "Failed to cast to Cat." << std::endl;  // Output: Failed to cast to Cat.
    }

    delete animalPtr;  // Clean up
    return 0;
}
