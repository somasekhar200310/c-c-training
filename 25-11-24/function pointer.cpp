#include <iostream>

// A simple function that takes two integers and returns their sum
int add(int a, int b) {
    return a + b;
}

// Another function that takes two integers and returns their difference
int subtract(int a, int b) {
    return a - b;
}

int main() {
    // Define a function pointer that points to functions taking two ints and returning an int
    int (*funcPtr)(int, int);

    // Point to the 'add' function
    funcPtr = add;
    std::cout << "Result of add: " << funcPtr(10, 5) << std::endl;

    // Point to the 'subtract' function
    funcPtr = subtract;
    std::cout << "Result of subtract: " << funcPtr(10, 5) << std::endl;

    return 0;
}
