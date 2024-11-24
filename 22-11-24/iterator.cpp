#include <iostream>
#include <vector>

int main() {
    // Create a vector of integers
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // Create an iterator for the vector
    std::vector<int>::iterator it;

    // Traverse through the vector using the iterator
    std::cout << "Elements in the vector: ";
    for (it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";  // Dereferencing the iterator to access the value
    }

    std::cout << std::endl;

    return 0;
}
