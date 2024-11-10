#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {   // Virtual function
        cout << "Some animal sound" << endl;
    }
    
    virtual ~Animal() {      // Virtual destructor
        cout << "Animal destroyed" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {  // Overriding the sound function
        cout << "Bark" << endl;
    }

    ~Dog() {
        cout << "Dog destroyed" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {  // Overriding the sound function
        cout << "Meow" << endl;
    }

    ~Cat() {
        cout << "Cat destroyed" << endl;
    }
};

int main() {
    Animal* animal1 = new Dog();  // Base pointer pointing to derived object
    Animal* animal2 = new Cat();  // Base pointer pointing to another derived object

    animal1->sound();  // Will call Dog's sound()
    animal2->sound();  // Will call Cat's sound()

    delete animal1;  // Destructor for Dog will be called
    delete animal2;  // Destructor for Cat will be called

    return 0;
}
