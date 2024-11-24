#include <iostream>
#include <vector>

class MyVector {
private:
    std::vector<int> data;
public:
    // Move Constructor
    MyVector(MyVector&& other) noexcept : data(std::move(other.data)) {
        std::cout << "Move Constructor\n";
    }

    // Move Assignment Operator
    MyVector& operator=(MyVector&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
            std::cout << "Move Assignment\n";
        }
        return *this;
    }
};

int main() {
    MyVector v1;            // Regular object
    MyVector v2 = std::move(v1);  // Move Constructor is called
    MyVector v3;
    v3 = std::move(v2);      // Move Assignment is called
    return 0;
}
