#include <iostream>
#include <cstring>  // For strcpy and strlen

class String {
private:
    char* data;

public:
    // Constructor
    String(const char* str = "") {
        data = new char[strlen(str) + 1];  // Allocate memory
        strcpy(data, str);  // Copy the string
        std::cout << "Constructor: " << data << std::endl;
    }

    // Move Constructor
    String(String&& other) noexcept {
        data = other.data;  // Steal the resource
        other.data = nullptr;  // Set the source to a valid state
        std::cout << "Move Constructor: " << data << std::endl;
    }

    // Move Assignment Operator
    String& operator=(String&& other) noexcept {
        if (this != &other) {  // Check for self-assignment
            delete[] data;  // Free the existing resource
            data = other.data;  // Steal the resource
            other.data = nullptr;  // Set the source to a valid state
            std::cout << "Move Assignment: " << data << std::endl;
        }
        return *this;  // Return *this for chain assignment
    }

    // Destructor
    ~String() {
        if (data) {
            std::cout << "Destructor: " << data << std::endl;
            delete[] data;  // Free memory
        }
    }

    // Get the data
    const char* getData() const {
        return data;
    }
};

int main() {
    String str1("Hello");  // Constructor called
    String str2 = std::move(str1);  // Move Constructor called

    String str3("World");  // Constructor called
    str3 = std::move(str2);  // Move Assignment called

    std::cout << "str1: " << (str1.getData() ? str1.getData() : "moved-from") << std::endl;
    std::cout << "str2: " << (str2.getData() ? str2.getData() : "moved-from") << std::endl;
    std::cout << "str3: " << str3.getData() << std::endl;

    return 0;
}
