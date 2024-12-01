#include <iostream>
#include <memory>

int main() {
    // Lambda function as a custom deleter to release a dynamically allocated array
    auto customDeleter = [](int* ptr) {
        std::cout << "Custom deleter called. Deleting array.\n";
        delete[] ptr;  // Deleting the array
    };

    // Create a unique_ptr with the custom deleter
    std::unique_ptr<int[], decltype(customDeleter)> ptr(new int[10], customDeleter);

    // Use the array
    for (int i = 0; i < 10; ++i) {
        ptr[i] = i * 10;  // Initialize the array
    }

    // The custom deleter will be called automatically when 'ptr' goes out of scope
    std::cout << "Array initialized and ready to be deleted when ptr goes out of scope.\n";

    return 0;
}
