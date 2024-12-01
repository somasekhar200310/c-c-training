#include <iostream>
#include <functional>  // For std::function

// A calculator function that takes a callback as an argument
double calculator(double a, double b, std::function<double(double, double)> operation) {
    return operation(a, b);  // Call the passed callback function
}

// Define various operations as callback functions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        std::cout << "Error: Division by zero!" << std::endl;
        return 0;
    }
}

int main() {
    double num1, num2;
    char op;

    // Input two numbers and the operation
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> op;

    // Use callback functions based on user input
    double result = 0;

    switch (op) {
        case '+':
            result = calculator(num1, num2, add);
            break;
        case '-':
            result = calculator(num1, num2, subtract);
            break;
        case '*':
            result = calculator(num1, num2, multiply);
            break;
        case '/':
            result = calculator(num1, num2, divide);
            break;
        default:
            std::cout << "Invalid operation!" << std::endl;
            return 1;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}
