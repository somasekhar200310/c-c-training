#include <iostream>
#include <set>
#include <string>

// Define a user-defined type (e.g., Person)
class Person {
public:
    std::string name;
    int age;

    // Constructor
    Person(std::string n, int a) : name(n), age(a) {}

    // For printing Person details
    void print() const {
        std::cout << name << " (" << age << " years old)";
    }
};

// Comparator for Person to define the order in the set
struct ComparePersons {
    bool operator()(const Person& p1, const Person& p2) const {
        // Custom comparison logic: sort by age
        return p1.age < p2.age;
    }
};

int main() {
    // Create a set of Person objects, using the custom comparator
    std::set<Person, ComparePersons> personSet;

    // Insert some Person objects into the set
    personSet.insert(Person("Alice", 30));
    personSet.insert(Person("Bob", 25));
    personSet.insert(Person("Charlie", 35));
    personSet.insert(Person("Alice", 30)); // Duplicate, will be ignored

    // Display elements in the set
    std::cout << "Persons in the set (sorted by age): \n";
    for (const Person& p : personSet) {
        p.print();
        std::cout << std::endl;
    }

    return 0;
}
