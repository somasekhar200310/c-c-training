#include <iostream>
#include <vector>
#include <algorithm>

// Functor to add a specific value to the element
class Adder {
public:
    // Constructor that sets the value to be added
    Adder(int val) : value(val) {}

    // Overload the function call operator
    void operator()(int& element) const {
        element += value;
    }

private:
    int value;
};

int main() {
    // Create a vector of integers
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Print original vector
    std::cout << "Original vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Create an instance of the functor
    Adder addTen(10);

    // Use the functor with the std::for_each algorithm
    std::for_each(numbers.begin(), numbers.end(), addTen);

    // Print the modified vector
    std::cout << "Modified vector (after adding 10 to each element): ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
