//auto pointer deprecated in c++ 11 and removed in c++17.
//instead of auto pointers introduced unique and shared pointers






#include <iostream>
#include <memory> // For auto_ptr

int main() {
    // Creating an auto_ptr (old C++ style)
    std::auto_ptr<int> ptr1(new int(10));  // ptr1 owns the dynamically allocated integer

    std::cout << "Value pointed to by ptr1: " << *ptr1 << std::endl;

    // Transferring ownership from ptr1 to ptr2
    std::auto_ptr<int> ptr2 = ptr1;  // Ownership is transferred, ptr1 is now empty

    // After the transfer, ptr1 no longer owns the memory
    if (!ptr1) {
        std::cout << "ptr1 no longer owns the memory." << std::endl;
    }

    std::cout << "Value pointed to by ptr2: " << *ptr2 << std::endl; // ptr2 now owns the memory

    // Memory is automatically freed when ptr2 goes out of scope
    return 0;
}

