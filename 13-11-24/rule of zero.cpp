#include <iostream>
#include <memory>
#include <string>

class RuleOfZero {
private:
    // Use a smart pointer to automatically manage dynamic memory
    std::unique_ptr<std::string> data;

public:
    // Constructor: Initialize data using a smart pointer
    RuleOfZero(const std::string& str) 
        : data(std::make_unique<std::string>(str)) {
        std::cout << "Constructor called: " << *data << std::endl;
    }

    // Function to show the data
    void showData() const {
        if (data) {
            std::cout << "Data: " << *data << std::endl;
        } else {
            std::cout << "No data" << std::endl;
        }
    }

    // No need to define destructor, copy constructor, or copy assignment operator
    // std::unique_ptr automatically handles cleanup and resource management
};

int main() {
    {
        RuleOfZero obj1("Hello, Rule of Zero!");
        obj1.showData();
        
        // No need to manually call delete or manage resources
    }  // obj1 goes out of scope, and its unique_ptr automatically releases the memory

    // obj1's destructor is automatically called when it goes out of scope, cleaning up the resource

    return 0;
}
