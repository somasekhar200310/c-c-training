#include <iostream>
#include <vector>
#include <algorithm>  // For sort
#include <numeric>    // For accumulate

int main() {
    // Creating a vector with initial values
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 1. Size of the vector
    std::cout << "Size of vector: " << vec.size() << std::endl;

    // 2. Accessing elements with operator[]
    std::cout << "Element at index 2: " << vec[2] << std::endl;

    // 3. Accessing elements with at() (bounds-checked)
    std::cout << "Element at index 2 using at(): " << vec.at(2) << std::endl;

    // 4. Checking if vector is empty
    if (vec.empty()) {
        std::cout << "Vector is empty." << std::endl;
    } else {
        std::cout << "Vector is not empty." << std::endl;
    }

    // 5. Adding elements (push_back)
    vec.push_back(6);
    std::cout << "After push_back(6): ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    // 6. Inserting elements (insert)
    vec.insert(vec.begin() + 2, 10);  // Insert 10 at index 2
    std::cout << "After insert(10) at index 2: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    // 7. Removing elements (pop_back)
    vec.pop_back();
    std::cout << "After pop_back(): ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    // 8. Erasing elements (erase)
    vec.erase(vec.begin() + 1);  // Erase element at index 1
    std::cout << "After erase at index 1: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    // 9. Clearing the vector (clear)
    vec.clear();
    std::cout << "After clear(), size: " << vec.size() << std::endl;

    // 10. Resizing the vector (resize)
    vec.resize(5, 100);  // Resize to 5 elements, initialize with 100
    std::cout << "After resize(5, 100): ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    // 11. Accessing the first and last element (front, back)
    std::cout << "First element: " << vec.front() << std::endl;
    std::cout << "Last element: " << vec.back() << std::endl;

    // 12. Modifying an element by reference
    vec[2] = 200;  // Change the element at index 2
    std::cout << "After modifying vec[2] = 200: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    // 13. Finding an element (find)
    auto it = std::find(vec.begin(), vec.end(), 200);
    if (it != vec.end()) {
        std::cout << "Element 200 found at position: " << std::distance(vec.begin(), it) << std::endl;
    } else {
        std::cout << "Element 200 not found" << std::endl;
    }

    // 14. Sorting the vector (sort)
    std::sort(vec.begin(), vec.end());
    std::cout << "After sort: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    // 15. Reversing the vector (reverse)
    std::reverse(vec.begin(), vec.end());
    std::cout << "After reverse: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    // 16. Accumulating elements (accumulate)
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum of elements: " << sum << std::endl;

    // 17. Reserving capacity (reserve)
    vec.reserve(10);  // Ensure at least 10 elements of space
    std::cout << "Capacity after reserve(10): " << vec.capacity() << std::endl;

    // 18. Shrinking to fit (shrink_to_fit)
    vec.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit: " << vec.capacity() << std::endl;

    return 0;
}
