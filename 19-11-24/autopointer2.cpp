#include <iostream>
#include <memory>  // For std::unique_ptr

int main() {
    // Creating a unique_ptr that manages a dynamically allocated integer
    std::unique_ptr<int> ptr1 = std::make_unique<int>(100);

    // Displaying the value of the dynamically allocated integer
    std::cout << "Value managed by ptr1: " << *ptr1 << std::endl;

    // Transferring ownership of the object from ptr1 to ptr2 using std::move
    std::unique_ptr<int> ptr2 = std::move(ptr1);

    // After the move, ptr1 is empty (nullptr), and ptr2 now owns the integer
    if (!ptr1) {
        std::cout << "ptr1 is now empty after the ownership transfer." << std::endl;
    }

    // Displaying the value of the dynamically allocated integer through ptr2
    std::cout << "Value managed by ptr2: " << *ptr2 << std::endl;

    // No need to explicitly delete the memory, it will be automatically freed
    return 0;
}
