#include <iostream>
#include <vector>
#include <string>

// Define a user-defined struct called Person
struct Person {
    std::string name;
    int age;

    // Constructor to initialize a Person object
    Person(const std::string& n, int a) : name(n), age(a) {}
};

int main() {
    // Create a vector of Person objects
    std::vector<Person> people;

    // Add some Person objects to the vector
    people.push_back(Person("Alice", 30));
    people.push_back(Person("Bob", 25));
    people.push_back(Person("Charlie", 35));

    // Iterate over the vector and print the details of each Person
    for (const auto& person : people) {
        std::cout << "Name: " << person.name << ", Age: " << person.age << std::endl;
    }

    return 0;
}
