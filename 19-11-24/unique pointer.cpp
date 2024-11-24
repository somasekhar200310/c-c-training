#include <iostream>
#include <memory>  // For std::unique_ptr

class MyClass {
public:
    MyClass(int value) : value_(value) {
        std::cout << "MyClass constructor: " << value_ << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass destructor: " << value_ << std::endl;
    }

    void display() const {
        std::cout << "Value: " << value_ << std::endl;
    }

private:
    int value_;
};

int main() {
    // Creating a unique_ptr that owns a dynamically allocated object of type MyClass
    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>(10);

    // Accessing members of MyClass using the unique_ptr
    ptr1->display();

    // Transfer ownership from ptr1 to ptr2 using std::move
    std::unique_ptr<MyClass> ptr2 = std::move(ptr1);

    // Now ptr1 is empty (nullptr), and ptr2 owns the object
    if (!ptr1) {
        std::cout << "ptr1 is empty after ownership transfer." << std::endl;
    }

    ptr2->display();

    // No need to manually delete the object; it's automatically destroyed when ptr2 goes out of scope
    return 0;
}
