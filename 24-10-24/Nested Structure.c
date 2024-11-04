Nested Structure

#include <stdio.h>

struct Address {
    char street[100];
    char city[50];
    char state[30];
    int zipCode;
};

struct Person {
    char name[50];
    int age;
    struct Address address; // Nested structure
};

void printPersonInfo(struct Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Address:\n");
    printf("  Street: %s\n", p.address.street);
    printf("  City: %s\n", p.address.city);
    printf("  State: %s\n", p.address.state);
    printf("  Zip Code: %d\n", p.address.zipCode);
}

int main() {
    struct Person person;

    snprintf(person.name, sizeof(person.name), "Somasekhar");
    person.age = 21;
    snprintf(person.address.street, sizeof(person.address.street), "123 Main St");
    snprintf(person.address.city, sizeof(person.address.city), "Kodur");
    snprintf(person.address.state, sizeof(person.address.state), "AP");
    person.address.zipCode = 516101;

    printPersonInfo(person);

    return 0;
}

Output:

Name: Somasekhar
Age : 21
Address:
    Street: 123 Main st
    City  : Kodur
    State : AP
    Zip Code: 516101