#include <iostream>
#include <cstring>  // For strcpy and strlen

class Person {
private:
    char* name;

public:
    // Constructor
    Person(const char* name = "") {
        this->name = new char[strlen(name) + 1];  // Allocate memory
        strcpy(this->name, name);  // Copy the name
        std::cout << "Constructor: " << name << std::endl;
    }

    // Copy Constructor (Deep Copy)
    Person(const Person& other) {
        name = new char[strlen(other.name) + 1];  // Allocate new memory
        strcpy(name, other.name);  // Copy the data
        std::cout << "Copy Constructor: " << name << std::endl;
    }

    // Copy Assignment Operator (Deep Copy)
    Person& operator=(const Person& other) {
        if (this != &other) {  // Check for self-assignment
            delete[] name;  // Free existing memory
            name = new char[strlen(other.name) + 1];  // Allocate new memory
            strcpy(name, other.name);  // Copy the data
            std::cout << "Copy Assignment: " << name << std::endl;
        }
        return *this;  // Return *this for chain assignment
    }

    // Destructor
    ~Person() {
        std::cout << "Destructor: " << name << std::endl;
        delete[] name;  // Free allocated memory
    }

    // Get the name
    const char* getName() const {
        return name;
    }
};

int main() {
    Person person1("soma sekhar");  // Constructor called
    Person person2 = person1;    // Copy Constructor called

    Person person3("soma sekhar");  // Constructor called
    person3 = person1;           // Copy Assignment Operator called

    std::cout << "person1: " << person1.getName() << std::endl;
    std::cout << "person2: " << person2.getName() << std::endl;
    std::cout << "person3: " << person3.getName() << std::endl;

    return 0;
}
