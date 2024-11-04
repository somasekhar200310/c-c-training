Deep Copy

#include <iostream>
#include <cstring>

class Person {
private:
    char *name;
    int age;

public:
    Person(const char *name, int age) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
    }

    Person(const Person &other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        age = other.age;
    }

    Person& operator=(const Person &other) {
        if (this != &other) {
            delete[] name;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            age = other.age;
        }
        return *this;
    }

    ~Person() {
        delete[] name;
    }

    void print() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    Person person1("Alice", 30);
    Person person2 = person1;
    person2 = Person("Bob", 25);

    person1.print();
    person2.print();

    return 0;
}


Output:
Name: Alice, Age:30
Name: Bob, Age:25