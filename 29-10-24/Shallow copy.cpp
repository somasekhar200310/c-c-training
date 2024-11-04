Shallow copy

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
};

void printPerson(struct Person p) {
    printf("Name: %s, Age: %d\n", p.name, p.age);
}

int main() {
    struct Person person1;
    struct Person person2;

    person1.name = (char*)malloc(50 * sizeof(char));
    strcpy(person1.name, "Alice");
    person1.age = 30;

    person2 = person1;

    person2.age = 25;
    person2.name[0] = 'B';

    printPerson(person1);
    printPerson(person2);

    free(person1.name);
    return 0;
}

OUTPUT:
Name: Blice, Age:30
Name: Blice, Age:25