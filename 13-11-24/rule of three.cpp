#include <iostream>
#include <cstring>  // For strcpy and strlen

class RuleOfThree {
private:
    char* data;  // Dynamically allocated memory for a string

public:
    // Constructor: Allocates memory and initializes it
    RuleOfThree(const char* str) {
        std::cout << "Constructor called" << std::endl;
        if (str) {
            data = new char[strlen(str) + 1];  // Allocate memory
            strcpy(data, str);  // Copy the string into allocated memory
        } else {
            data = nullptr;
        }
    }

    // Destructor: Releases dynamically allocated memory
    ~RuleOfThree() {
        std::cout << "Destructor called" << std::endl;
        delete[] data;
    }

    // Copy Constructor: Deep copy of resources
    RuleOfThree(const RuleOfThree& other) {
        std::cout << "Copy Constructor called" << std::endl;
        if (other.data) {
            data = new char[strlen(other.data) + 1];  // Allocate new memory
            strcpy(data, other.data);  // Copy data from the other object
        } else {
            data = nullptr;
        }
    }

    // Copy Assignment Operator: Handles deep copy and resource management
    RuleOfThree& operator=(const RuleOfThree& other) {
        std::cout << "Copy Assignment Operator called" << std::endl;
        if (this != &other) {  // Prevent self-assignment
            delete[] data;  // Free existing resource
            if (other.data) {
                data = new char[strlen(other.data) + 1];  // Allocate new memory
                strcpy(data, other.data);  // Copy data from the other object
            } else {
                data = nullptr;
            }
        }
        return *this;
    }

    // Utility function to display the stored data
    void showData() const {
        if (data) {
            std::cout << "Data: " << data << std::endl;
        } else {
            std::cout << "Data is null" << std::endl;
        }
    }
};

int main() {
    // Creating an object of RuleOfThree
    RuleOfThree obj1("Hello, Rule of Three!");
    obj1.showData();

    // Using copy constructor
    RuleOfThree obj2 = obj1;
    obj2.showData();

    // Using copy assignment operator
    RuleOfThree obj3("Temporary data");
    obj3 = obj1;
    obj3.showData();

    return 0;
}
