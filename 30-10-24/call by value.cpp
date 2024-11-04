call by value

#include <iostream>
#include <cstring>

class Box {
private:
    char *label;
    int size;

public:
    Box(const char *label, int size) {
        this->label = new char[strlen(label) + 1];
        strcpy(this->label, label);
        this->size = size;
    }

    Box(const Box &other) {
        label = new char[strlen(other.label) + 1];
        strcpy(label, other.label);
        size = other.size;
    }

    Box getBox() const {
        return *this; // Returns a copy of the current object
    }

    void print() const {
        std::cout << "Label: " << label << ", Size: " << size << std::endl;
    }

    ~Box() {
        delete[] label;
    }
};

int main() {
    Box box1("Large", 10);
    Box box2 = box1.getBox(); // Calls copy constructor

    box1.print();
    box2.print();

    return 0;
}

OUTPUT:
Label: Large, Size :10
Label: Large, Size :10