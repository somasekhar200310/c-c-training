#include <iostream>
#include <functional>

int main() {
    // Define a recursive lambda to calculate factorial
    std::function<int(int)> factorial = [&](int n) -> int {
        if (n <= 1) return 1;  // Base case: factorial(0) = factorial(1) = 1
        else return n * factorial(n - 1);  // Recursive case
    };

    // Test the recursive lambda
    int result = factorial(5);  // Should calculate 5!
    std::cout << "Factorial of 5 is: " << result << std::endl;

    return 0;
}
