#include <iostream>
#include <memory>  // For std::shared_ptr

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
    // Creating a shared_ptr that owns a dynamically allocated object of type MyClass
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>(100);

    // Display the value managed by ptr1
    ptr1->display();

    {
        // Creating another shared_ptr that shares ownership of the same object
        std::shared_ptr<MyClass> ptr2 = ptr1;  // ptr1 and ptr2 now share ownership

        // Display the value managed by ptr2
        ptr2->display();

        std::cout << "Reference count after ptr2 creation: " << ptr1.use_count() << std::endl;

        // ptr2 goes out of scope here, but ptr1 still owns the object
    }

    // ptr2 is out of scope, but ptr1 still owns the object
    std::cout << "Reference count after ptr2 goes out of scope: " << ptr1.use_count() << std::endl;

    // The resource will be automatically freed when ptr1 goes out of scope at the end of main
    return 0;
}
