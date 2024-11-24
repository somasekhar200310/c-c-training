#include <iostream>
#include <algorithm>

// Callback function to compare integers for ascending order
bool ascending(int a, int b) {
    return a < b;
}

// Callback function to compare integers for descending order
bool descending(int a, int b) {
    return a > b;
}

// Function that accepts a comparison callback to sort an array
void sortArray(int* arr, int size, bool (*compare)(int, int)) {
    std::sort(arr, arr + size, compare);
}

int main() {
    int arr1[] = {5, 3, 8, 6, 2, 7};
    int size = sizeof(arr1) / sizeof(arr1[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    // Sort the array in ascending order
    sortArray(arr1, size, ascending);
    std::cout << "Sorted array (ascending): ";
    for (int i = 0; i < size; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    // Sort the array in descending order
    sortArray(arr1, size, descending);
    std::cout << "Sorted array (descending): ";
    for (int i = 0; i < size; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
