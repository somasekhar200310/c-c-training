#include <iostream>

// Custom smart pointer class
template <typename T>
class MyUniquePtr {
private:
    T* ptr;  // Raw pointer to the object

public:
    // Constructor that takes a raw pointer and owns it
    explicit MyUniquePtr(T* p = nullptr) : ptr(p) {}

    // Destructor that deletes the owned object when the unique pointer goes out of scope
    ~MyUniquePtr() {
        delete ptr;
        std::cout << "Object deleted!" << std::endl;
    }

    // Move constructor (Transfers ownership)
    MyUniquePtr(MyUniquePtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;  // Set the other pointer to null after transferring ownership
    }

    // Move assignment operator (Transfers ownership)
    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;  // Delete the existing object
            ptr = other.ptr;  // Transfer ownership
            other.ptr = nullptr;  // Nullify the other pointer
        }
        return *this;
    }

    // Delete copy constructor and copy assignment operator to prevent copying
    MyUniquePtr(const MyUniquePtr& other) = delete;
    MyUniquePtr& operator=(const MyUniquePtr& other) = delete;

    // Dereferencing operator to access the object
    T& operator*() const {
        return *ptr;
    }

    // Arrow operator to access the object's members
    T* operator->() const {
        return ptr;
    }

    // Get the raw pointer
    T* get() const {
        return ptr;
    }

    // Release ownership of the pointer without deleting it
    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    // Reset the unique pointer to a new object (deletes old object if any)
    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }
};

// Example class to be used with custom smart pointer
class MyClass {
public:
    void sayHello() const {
        std::cout << "Hello from MyClass!" << std::endl;
    }
};

int main() {
    // Create a unique pointer to a MyClass object
    MyUniquePtr<MyClass> ptr1(new MyClass());
    ptr1->sayHello();  // Using arrow operator

    // Move ownership of ptr1 to ptr2
    MyUniquePtr<MyClass> ptr2 = std::move(ptr1);
    ptr2->sayHello();  // Using arrow operator

    // ptr1 is now null, so accessing ptr1 will not work
    // ptr1->sayHello();  // Error: ptr1 is null after move

    // Reset ptr2 to point to a new object
    ptr2.reset(new MyClass());
    ptr2->sayHello();  // Using arrow operator

    return 0;
}
