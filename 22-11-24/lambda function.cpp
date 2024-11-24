#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {5, 3, 8, 6, 2, 7};

    // Sort the vector in descending order using a lambda
    std::sort(vec.begin(), vec.end(), [](int a, int b) -> bool {
        return a > b; // Sorting in descending order
    });

    std::cout << "Sorted in descending order: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
