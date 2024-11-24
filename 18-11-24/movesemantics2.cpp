#include <iostream>
#include <algorithm>  // For std::copy

class Vector {
private:
    int* data;
    size_t size;
    size_t capacity;

public:
    // Constructor
    Vector(size_t capacity = 10) : size(0), capacity(capacity) {
        data = new int[capacity];  // Allocate memory
        std::cout << "Constructor: Allocated memory with capacity " << capacity << std::endl;
    }

    // Move Constructor
    Vector(Vector&& other) noexcept
        : data(other.data), size(other.size), capacity(other.capacity) {
        // Steal the resource
        other.data = nullptr;  // Nullify the other object's data pointer
        other.size = 0;
        other.capacity = 0;

        std::cout << "Move Constructor: Moved from object\n";
    }

    // Move Assignment Operator
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {  // Check for self-assignment
            delete[] data;  // Release the current resource

            // Steal the resource from the other object
            data = other.data;
            size = other.size;
            capacity = other.capacity;

            // Nullify the other object's data pointer
            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;

            std::cout << "Move Assignment: Moved from object\n";
        }
        return *this;
    }

    // Destructor
    ~Vector() {
        if (data) {
            delete[] data;  // Free allocated memory
            std::cout << "Destructor: Freed memory\n";
        }
    }

    // Add an element to the vector
    void push_back(int value) {
        if (size == capacity) {
            // Reallocate memory if needed
            capacity *= 2;
            int* new_data = new int[capacity];
            std::copy(data, data + size, new_data);  // Copy existing elements
            delete[] data;
            data = new_data;
        }
        data[size++] = value;
    }

    // Print vector elements
    void print() const {
        std::cout << "Vector: ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Vector v1;  // Constructor
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    v1.print();

    // Move Constructor
    Vector v2 = std::move(v1);
    v2.print();

    // Move Assignment Operator
    Vector v3;
    v3 = std::move(v2);
    v3.print();

    // At this point, v1 and v2 are in a valid but unspecified state (data is nullptr).
    std::cout << "v1 after move: ";
    v1.print();
    std::cout << "v2 after move: ";
    v2.print();

    return 0;
}
