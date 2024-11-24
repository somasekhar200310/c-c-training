#include <iostream>

int main() {
    int intVal = 42;
    float floatVal = static_cast<float>(intVal);  // Convert int to float using static_cast

    std::cout << "intVal: " << intVal << std::endl;  // Output: 42
    std::cout << "floatVal: " << floatVal << std::endl;  // Output: 42.0
    return 0;
}
