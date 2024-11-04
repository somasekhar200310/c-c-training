copy constructor by explicit

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

    explicit Box(const Box &other) {
        label = new char[strlen(other.label) + 1];
        strcpy(label, other.label);
        size = other.size;
    }

    Box getBox() const {
        return Box(*this); // Explicit call to the copy constructor
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
    Box box2(box1.getBox()); // Explicitly calling the copy constructor

    box1.print();
    box2.print();

    return 0;
}


OUTPUT:
Label: Large, Size:10
Label: Large, Size:10