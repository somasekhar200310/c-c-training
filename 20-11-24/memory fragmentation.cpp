#include <iostream>

int main() {
    const size_t smallSize = 100;  // Small memory block size
    const size_t largeSize = 500;  // Large memory block size

    // Step 1: Allocate small blocks
    int* block1 = new int[smallSize];  // Small block
    int* block2 = new int[smallSize];  // Small block
    int* block3 = new int[smallSize];  // Small block
    std::cout << "Allocated three small blocks of size " << smallSize << std::endl;

    // Step 2: Deallocate some blocks to create gaps
    delete[] block2;  // Free one block
    std::cout << "Deallocated block 2." << std::endl;

    // Step 3: Attempt to allocate a large block
    // Even though total memory is enough, fragmentation may prevent allocation
    int* largeBlock = nullptr;
    try {
        largeBlock = new int[largeSize];  // Try to allocate a large block
        std::cout << "Successfully allocated a large block of size " << largeSize << std::endl;
    } catch (std::bad_alloc& e) {
        std::cout << "Failed to allocate large block due to fragmentation!" << std::endl;
    }

    // Clean up remaining allocations
    delete[] block1;
    delete[] block3;

    return 0;
}

