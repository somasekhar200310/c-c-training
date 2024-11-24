#include <iostream>

int main() {
    const int a = 10;  // A constant variable
    int* ptr = const_cast<int*>(&a);  // Remove the const qualifier using const_cast
    
    // Now, ptr is a non-const pointer, but dereferencing and modifying a const variable is undefined behavior!
    *ptr = 20;  // This is undefined behavior because 'a' is a const variable.

    std::cout << "a = " << a << std::endl;  // Output is unpredictable, undefined behavior occurred

    return 0;
}


void printValue(const int* ptr) {
    std::cout << "Value: " << *ptr << std::endl;
}

int main() {
    int a = 10;
    int* ptr = &a;  // Non-const pointer

    // Adding const qualifier using const_cast to pass to a function that expects a const int*
    printValue(const_cast<const int*>(ptr));  // Pass non-const pointer as const pointer

    return 0;
}
