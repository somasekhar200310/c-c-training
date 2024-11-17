#include <iostream>

// Base case: sum of no arguments is 0
int sum() {
    return 0;
}

// Recursive case: sum the first argument and recurse with the rest
template <typename T, typename... Args>
int sum(const T& first, const Args&... rest) {
    return first + sum(rest...);  // Add first element to the sum of the rest
}

int main() {
    std::cout << "Sum: " << sum(1, 2, 3, 4, 5) << std::endl;   // Output: 15
    std::cout << "Sum: " << sum(10, 20) << std::endl;          // Output: 30
    std::cout << "Sum: " << sum(100) << std::endl;             // Output: 100
    return 0;
}
