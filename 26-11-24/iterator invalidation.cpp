#include <iostream>
#include <vector>

int main() {
    // Create a vector of integers
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // Create an iterator pointing to the second element (20)
    auto it = vec.begin() + 1;
    std::cout << "Iterator before modification: " << *it << std::endl;

    // Remove an element (invalidates iterators)
    vec.erase(vec.begin() + 2);  // This erases the element '30'

    // Accessing the iterator after erasing will lead to undefined behavior
    std::cout << "Iterator after modification (invalidated): " << *it << std::endl;

    // Correct way: refresh iterator
    it = vec.begin() + 1;  // Reassign the iterator to a valid position
    std::cout << "Iterator after refreshing: " << *it << std::endl;

    return 0;
}
