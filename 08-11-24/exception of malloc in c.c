#include <stdio.h>
#include <stdlib.h>  // For malloc and free

// Function to allocate memory and handle malloc failure
int* allocateMemory(size_t size) {
    int* ptr = (int*)malloc(size * sizeof(int));  // Allocate memory
    if (ptr == NULL) {
        // If malloc fails, handle the error
        perror("Memory allocation failed");  // Print system error message
        exit(EXIT_FAILURE);  // Terminate the program
    }
    return ptr;
}

int main() {
    size_t numElements = 10;

    // Try to allocate memory for 10 integers
    int* ptr = allocateMemory(numElements);

    // If allocation is successful, use the memory
    for (size_t i = 0; i < numElements; ++i) {
        ptr[i] = i * 10;  // Assign values to the allocated memory
    }

    // Print the values to verify that memory allocation worked
    for (size_t i = 0; i < numElements; ++i) {
        printf("Element %zu: %d\n", i, ptr[i]);
    }

    // Free the allocated memory
    free(ptr);

    return 0;
}
