#include <iostream>
#include <list>
#include <algorithm> // For STL algorithms
#include <numeric>   // For accumulate
#include <iterator>  // For std::distance

class Person {
public:
    Person(std::string name, int age) : name(name), age(age) {}

    // Getters
    std::string getName() const { return name; }
    int getAge() const { return age; }

    // Comparison operator for sorting
    bool operator<(const Person& other) const {
        return age < other.age;
    }

    bool operator>(const Person& other) const {
        return age > other.age;
    }

    // Output function
    void print() const {
        std::cout << name << " (" << age << " years old)";
    }

private:
    std::string name;
    int age;
};

int main() {
    // Create a list of Person objects
    std::list<Person> people = {
        Person("Alice", 30),
        Person("Bob", 25),
        Person("Charlie", 35),
        Person("David", 28),
        Person("Eve", 30),
        Person("Frank", 22)
    };

    // Display the original list
    std::cout << "Original List of People:" << std::endl;
    for (const auto& person : people) {
        person.print();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // 1. Sort the list in ascending order of age
    people.sort(); // Uses the < operator for comparison
    std::cout << "Sorted by Age (Ascending):" << std::endl;
    for (const auto& person : people) {
        person.print();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // 2. Reverse the list
    people.reverse();
    std::cout << "Reversed List:" << std::endl;
    for (const auto& person : people) {
        person.print();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // 3. Find the maximum element (person with maximum age)
    auto maxPerson = *std::max_element(people.begin(), people.end(), 
                                        [](const Person& p1, const Person& p2) {
                                            return p1.getAge() < p2.getAge(); 
                                        });
    std::cout << "Person with Maximum Age: ";
    maxPerson.print();
    std::cout << std::endl;

    // 4. Find the minimum element (person with minimum age)
    auto minPerson = *std::min_element(people.begin(), people.end(),
                                        [](const Person& p1, const Person& p2) {
                                            return p1.getAge() < p2.getAge();
                                        });
    std::cout << "Person with Minimum Age: ";
    minPerson.print();
    std::cout << std::endl;

    // 5. Accumulate the ages of all people
    int totalAge = std::accumulate(people.begin(), people.end(), 0,
                                   [](int sum, const Person& p) {
                                       return sum + p.getAge();
                                   });
    std::cout << "Total Age of All People: " << totalAge << std::endl;
    std::cout << std::endl;

    // 6. Count the number of people with age 30
    int count30 = std::count_if(people.begin(), people.end(),
                                [](const Person& p) { return p.getAge() == 30; });
    std::cout << "Number of People with Age 30: " << count30 << std::endl;

    // 7. Find if a person with age 25 exists
    auto foundPerson = std::find_if(people.begin(), people.end(),
                                    [](const Person& p) { return p.getAge() == 25; });
    if (foundPerson != people.end()) {
        std::cout << "Found person with age 25: ";
        foundPerson->print();
        std::cout << std::endl;
    } else {
        std::cout << "No person with age 25 found." << std::endl;
    }

    // 8. Binary search for a person (requires sorted list first)
    people.sort(); // Sort the list by age for binary search
    bool found = std::binary_search(people.begin(), people.end(), Person("", 30),
                                    [](const Person& p1, const Person& p2) {
                                        return p1.getAge() < p2.getAge();
                                    });
    std::cout << "Binary search for a person with age 30: " << (found ? "Found" : "Not Found") << std::endl;

    // 9. Lower bound for age 30
    auto lb = std::lower_bound(people.begin(), people.end(), Person("", 30),
                               [](const Person& p1, const Person& p2) {
                                   return p1.getAge() < p2.getAge();
                               });
    std::cout << "Lower bound for age 30: ";
    if (lb != people.end()) lb->print();
    std::cout << std::endl;

    // 10. Upper bound for age 30
    auto ub = std::upper_bound(people.begin(), people.end(), Person("", 30),
                               [](const Person& p1, const Person& p2) {
                                   return p1.getAge() < p2.getAge();
                               });
    std::cout << "Upper bound for age 30: ";
    if (ub != people.end()) ub->print();
    std::cout << std::endl;

    return 0;
}
