#include <iostream>
#include <map>
using namespace std;

int main() {
    // 1. Creating a multimap and initializing with some key-value pairs
    multimap<int, string> myMultimap = {
        {1, "Apple"},
        {2, "Banana"},
        {2, "Blueberry"},
        {3, "Cherry"},
        {4, "Date"},
        {5, "Elderberry"},
        {5, "Fig"}
    };

    // 2. Inserting elements (duplicate keys are allowed)
    myMultimap.insert({2, "Blackberry"});  // Insert another element with key 2
    myMultimap.insert({3, "Grape"});       // Insert an element with key 3

    // 3. Erasing elements by key (removes all occurrences of the key)
    myMultimap.erase(2);  // Removes all elements with key 2

    // 4. Erasing an element by iterator (removes one occurrence of the key)
    auto it = myMultimap.find(3); // Find an element with key 3
    if (it != myMultimap.end()) {
        myMultimap.erase(it);  // Erase the element with key 3
    }

    // 5. Accessing the elements with a specific key
    cout << "Elements with key 5: ";
    auto range = myMultimap.equal_range(5);  // Get the range of elements with key 5
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << " ";  // Print the values
    }
    cout << endl;

    // 6. Iterating through the multimap
    cout << "Iterating through the multimap: ";
    for (const auto& pair : myMultimap) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;

    // 7. Size of the multimap
    cout << "Size of the multimap: " << myMultimap.size() << endl;

    // 8. Checking if the multimap is empty
    if (myMultimap.empty()) {
        cout << "The multimap is empty." << endl;
    } else {
        cout << "The multimap is not empty." << endl;
    }

    // 9. Lower and Upper Bound
    auto lower = myMultimap.lower_bound(3);  // First element not less than key 3
    auto upper = myMultimap.upper_bound(3);  // First element greater than key 3

    cout << "Lower bound for key 3: " << (lower != myMultimap.end() ? to_string(lower->first) + " (" + lower->second + ")" : "Not found") << endl;
    cout << "Upper bound for key 3: " << (upper != myMultimap.end() ? to_string(upper->first) + " (" + upper->second + ")" : "Not found") << endl;

    // 10. Clearing the multimap
    myMultimap.clear();
    cout << "After clearing, the multimap size is: " << myMultimap.size() << endl;

    return 0;
}
