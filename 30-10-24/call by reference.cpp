call by reference

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
        return *this;
    }

    void print() const {
        std::cout << "Label: " << label << ", Size: " << size << std::endl;
    }

    ~Box() {
        delete[] label;
    }
};

int main() {
    Box box1("Small", 3);
    Box box2 = box1.getBox();

    box1.print();
    box2.print();

    return 0;
}

OUTPUT:
Label: Small,Size:3
Label: Small,Size:3