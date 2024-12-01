#include <iostream>
#include <vector>
#include <algorithm> // For STL algorithms
#include <numeric>   // For accumulate
#include <iterator>  // For std::distance

int main() {
    // Initialize a vector of integers
    std::vector<int> vec = {10, 20, 30, 40, 50, 20, 60, 10, 30};

    // Display the original vector
    std::cout << "Original Vector: ";
    for (int n : vec) std::cout << n << " ";
    std::cout << std::endl;

    // 1. Sort the vector in ascending order
    std::sort(vec.begin(), vec.end());
    std::cout << "Sorted Vector (Ascending): ";
    for (int n : vec) std::cout << n << " ";
    std::cout << std::endl;

    // 2. Reverse the vector
    std::reverse(vec.begin(), vec.end());
    std::cout << "Reversed Vector: ";
    for (int n : vec) std::cout << n << " ";
    std::cout << std::endl;

    // 3. Find the maximum element
    auto maxElem = std::max_element(vec.begin(), vec.end());
    std::cout << "Maximum Element: " << *maxElem << std::endl;

    // 4. Find the minimum element
    auto minElem = std::min_element(vec.begin(), vec.end());
    std::cout << "Minimum Element: " << *minElem << std::endl;

    // 5. Accumulate the elements (sum of elements)
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum of Elements: " << sum << std::endl;

    // 6. Count the occurrences of the number 20
    int count_20 = std::count(vec.begin(), vec.end(), 20);
    std::cout << "Count of 20: " << count_20 << std::endl;

    // 7. Find an element (20)
    auto it = std::find(vec.begin(), vec.end(), 20);
    if (it != vec.end()) {
        std::cout << "Element 20 found at index: " << std::distance(vec.begin(), it) << std::endl;
    } else {
        std::cout << "Element 20 not found" << std::endl;
    }

    // 8. Binary search (after sorting the vector)
    std::sort(vec.begin(), vec.end());  // Ensure the vector is sorted for binary search
    bool found = std::binary_search(vec.begin(), vec.end(), 30);
    std::cout << "Binary search for 30: " << (found ? "Found" : "Not Found") << std::endl;

    // 9. Lower bound (find the first position where 20 could be inserted)
    auto lb = std::lower_bound(vec.begin(), vec.end(), 20);
    std::cout << "Lower bound for 20: " << *lb << " at index " << std::distance(vec.begin(), lb) << std::endl;

    // 10. Upper bound (find the first position where 30 could be inserted)
    auto ub = std::upper_bound(vec.begin(), vec.end(), 30);
    std::cout << "Upper bound for 30: " << *ub << " at index " << std::distance(vec.begin(), ub) << std::endl;

    return 0;
}
