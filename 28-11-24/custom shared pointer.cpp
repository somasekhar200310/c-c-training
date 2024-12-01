#include <iostream>

template <typename T>
class MySharedPtr {
private:
    T* ptr;              // Raw pointer to the object
    int* ref_count;      // Pointer to the reference count

public:
    // Constructor: Initializes the smart pointer with a raw pointer
    explicit MySharedPtr(T* p = nullptr) : ptr(p), ref_count(new int(1)) {
        std::cout << "Constructor: Object created with reference count = " << *ref_count << std::endl;
    }

    // Destructor: Decreases the reference count and deletes the object if count reaches zero
    ~MySharedPtr() {
        release();
    }

    // Copy constructor: Increases the reference count for the new shared pointer
    MySharedPtr(const MySharedPtr& other) : ptr(other.ptr), ref_count(other.ref_count) {
        (*ref_count)++;
        std::cout << "Copy constructor: Object copied, reference count = " << *ref_count << std::endl;
    }

    // Copy assignment operator: Increases the reference count for the new shared pointer
    MySharedPtr& operator=(const MySharedPtr& other) {
        if (this != &other) {
            release();  // Release the current object

            ptr = other.ptr;
            ref_count = other.ref_count;
            (*ref_count)++;  // Increment reference count
            std::cout << "Copy assignment: Object assigned, reference count = " << *ref_count << std::endl;
        }
        return *this;
    }

    // Dereference operator: Provides access to the object
    T& operator*() const {
        return *ptr;
    }

    // Arrow operator: Provides access to the object's members
    T* operator->() const {
        return ptr;
    }

    // Get the raw pointer
    T* get() const {
        return ptr;
    }

private:
    // Releases the current object (decreases reference count and deletes the object if needed)
    void release() {
        if (ptr != nullptr && --(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
            std::cout << "Destructor: Object deleted, reference count = " << *ref_count << std::endl;
        }
    }
};

// Example class to be used with custom shared pointer
class MyClass {
public:
    void sayHello() const {
        std::cout << "Hello from MyClass!" << std::endl;
    }
};

int main() {
    // Create a shared pointer to a MyClass object
    MySharedPtr<MyClass> ptr1(new MyClass());
    ptr1->sayHello();

    // Create another shared pointer that shares ownership of the same object
    MySharedPtr<MyClass> ptr2 = ptr1;
    ptr2->sayHello();

    // Create another shared pointer using the copy assignment operator
    MySharedPtr<MyClass> ptr3;
    ptr3 = ptr1;
    ptr3->sayHello();

    // Reset ptr1, ptr2, and ptr3 will still have shared ownership
    ptr1 = MySharedPtr<MyClass>();  // Release ownership of ptr1
    ptr3->sayHello();

    return 0;
}
