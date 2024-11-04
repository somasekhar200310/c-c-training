structures


#include <stdio.h>

struct Book {
    char title[100];
    char author[50];
    int year;
    float price;
};

void printBookInfo(struct Book b) {
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Year: %d\n", b.year);
    printf("Price: %.2f\n", b.price);
}

int main() {
    struct Book book1;

    snprintf(book1.title, sizeof(book1.title), "The Great Gatsby");
    snprintf(book1.author, sizeof(book1.author), "F. Scott Fitzgerald");
    book1.year = 1925;
    book1.price = 10.99;

    printBookInfo(book1);

    return 0;
}

OUTPUT:
Year:1925
Price:10.99

UNIONS

#include <stdio.h>

union Data {
    int intValue;
    float floatValue;
    char charValue;
};

int main() {
    union Data data;

    data.intValue = 10;
    printf("Integer: %d\n", data.intValue);

    data.floatValue = 3.14;
    printf("Float: %.2f\n", data.floatValue);

    data.charValue = 'A';
    printf("Character: %c\n", data.charValue);

    printf("Integer after assigning char: %d\n", data.intValue);
    printf("Float after assigning char: %.2f\n", data.floatValue);

    return 0;
}

OUTPUT:
Integer after assigning char:1078523201
Float after assigning char: 3.14