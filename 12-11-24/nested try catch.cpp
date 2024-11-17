#include <iostream>
#include <stdexcept>

void innerFunction() {
    try {
        std::cout << "In inner try block" << std::endl;
        throw std::runtime_error("Error in inner function");
    }
    catch (const std::runtime_error& e) {
        std::cout << "Caught exception in inner catch: " << e.what() << std::endl;
        // Rethrow the exception to the outer try-catch
        throw;
    }
}

void outerFunction() {
    try {
        std::cout << "In outer try block" << std::endl;
        innerFunction();
    }
    catch (const std::runtime_error& e) {
        std::cout << "Caught exception in outer catch: " << e.what() << std::endl;
    }
}

int main() {
    try {
        std::cout << "In main try block" << std::endl;
        outerFunction();
    }
    catch (const std::exception& e) {
        std::cout << "Caught exception in main catch: " << e.what() << std::endl;
    }
    return 0;
}
