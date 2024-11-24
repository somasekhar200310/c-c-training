#include <iostream>
#include <set>
using namespace std;

int main() {
    // 1. Creating a multiset and initializing with some values
    multiset<int> myMultiset = {10, 20, 20, 30, 40, 50, 50, 50};

    // 2. Inserting elements (duplicates are allowed)
    myMultiset.insert(60);  // Insert a new element
    myMultiset.insert(20);  // Insert another 20 (duplicate)

    // 3. Erasing elements by value (removes all occurrences of the value)
    myMultiset.erase(50);  // Removes all occurrences of 50

    // 4. Accessing the number of occurrences of an element using count()
    cout << "Number of occurrences of 20: " << myMultiset.count(20) << endl; // Should be 3

    // 5. Checking if an element exists using find()
    auto it = myMultiset.find(30);  // Find element with value 30
    if (it != myMultiset.end()) {
        cout << "Found element 30." << endl;
    } else {
        cout << "Element 30 not found." << endl;
    }

    // 6. Iterating through the multiset
    cout << "Iterating through the multiset: ";
    for (const auto& value : myMultiset) {
        cout << value << " ";
    }
    cout << endl;

    // 7. Size of the multiset
    cout << "Size of the multiset: " << myMultiset.size() << endl;

    // 8. Checking if the multiset is empty
    if (myMultiset.empty()) {
        cout << "The multiset is empty." << endl;
    } else {
        cout << "The multiset is not empty." << endl;
    }

    // 9. Lower and Upper Bound
    auto lower = myMultiset.lower_bound(20);  // First element not less than key 20
    auto upper = myMultiset.upper_bound(20);  // First element greater than key 20

    cout << "Lower bound for 20: " << (lower != myMultiset.end() ? to_string(*lower) : "Not found") << endl;
    cout << "Upper bound for 20: " << (upper != myMultiset.end() ? to_string(*upper) : "Not found") << endl;

    // 10. Clearing the multiset
    myMultiset.clear();
    cout << "After clearing, the multiset size is: " << myMultiset.size() << endl;

    return 0;
}
