#include <iostream>
#include <cstring>  // For strcpy and strlen

class RuleOfFive {
private:
    char* data;  // Dynamically allocated memory for a string

public:
    // Constructor: Allocates memory and initializes it
    RuleOfFive(const char* str) {
        std::cout << "Constructor called" << std::endl;
        if (str) {
            data = new char[strlen(str) + 1];  // Allocate memory
            strcpy(data, str);  // Copy the string into allocated memory
        } else {
            data = nullptr;
        }
    }

    // Destructor: Releases dynamically allocated memory
    ~RuleOfFive() {
        std::cout << "Destructor called" << std::endl;
        delete[] data;
    }

    // Copy Constructor: Deep copy of resources
    RuleOfFive(const RuleOfFive& other) {
        std::cout << "Copy Constructor called" << std::endl;
        if (other.data) {
            data = new char[strlen(other.data) + 1];  // Allocate new memory
            strcpy(data, other.data);  // Copy data from the other object
        } else {
            data = nullptr;
        }
    }

    // Copy Assignment Operator: Handles deep copy and resource management
    RuleOfFive& operator=(const RuleOfFive& other) {
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

    // Move Constructor: Transfers ownership of resources from a temporary object
    RuleOfFive(RuleOfFive&& other) noexcept {
        std::cout << "Move Constructor called" << std::endl;
        data = other.data;  // Transfer ownership
        other.data = nullptr;  // Set the other object's data pointer to null
    }

    // Move Assignment Operator: Transfers resources from a temporary object
    RuleOfFive& operator=(RuleOfFive&& other) noexcept {
        std::cout << "Move Assignment Operator called" << std::endl;
        if (this != &other) {  // Prevent self-assignment
            delete[] data;  // Release the current resource
            data = other.data;  // Transfer ownership
            other.data = nullptr;  // Nullify the other object's data pointer
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
    // Creating an object of RuleOfFive
    RuleOfFive obj1("Hello, Rule of Five!");
    obj1.showData();

    // Using copy constructor
    RuleOfFive obj2 = obj1;
    obj2.showData();

    // Using copy assignment operator
    RuleOfFive obj3("Temporary data");
    obj3 = obj1;
    obj3.showData();

    // Using move constructor
    RuleOfFive obj4 = std::move(obj1);
    obj4.showData();
    obj1.showData();  // obj1's data should now be null

    // Using move assignment operator
    RuleOfFive obj5("Another temporary data");
    obj5 = std::move(obj2);
    obj5.showData();
    obj2.showData();  // obj2's data should now be null

    return 0;
}
