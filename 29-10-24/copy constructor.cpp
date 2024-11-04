copy constructor

#include <iostream>
#include <cstring>

class Book {
private:
    char *title;
    int pages;

public:
    Book(const char *title, int pages) {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        this->pages = pages;
    }

    Book(const Book &other) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
        pages = other.pages;
    }

    ~Book() {
        delete[] title;
    }

    void print() const {
        std::cout << "Title: " << title << ", Pages: " << pages << std::endl;
    }
};

int main() {
    Book book1("C++ Programming", 300);
    Book book2 = book1;

    book1.print();
    book2.print();

    return 0;
}

OUTPUT:
Title:C++ Programming,Pages:300
Title:C++ Programming,Pages:300