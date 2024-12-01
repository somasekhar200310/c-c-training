#include <iostream>

// Create a typedef for an integer type
typedef int Integer;

int main() {
    Integer a = 10;  // 'Integer' is now an alias for 'int'
    Integer b = 20;

    std::cout << "a + b = " << a + b << std::endl;

    return 0;
}
