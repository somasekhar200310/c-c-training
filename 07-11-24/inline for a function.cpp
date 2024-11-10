#include <iostream>

#define AREA_OF_RECTANGLE(length, width) ((length) * (width))

int main() {
    int length = 10;
    int width = 5;
    std::cout << "Area of rectangle: " << AREA_OF_RECTANGLE(length, width) << std::endl;
    return 0;
}
