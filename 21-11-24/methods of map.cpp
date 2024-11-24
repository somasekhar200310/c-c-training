#include <iostream>
#include <map>
using namespace std;

int main() {
    // 1. Creating a map with key-value pairs
    map<int, string> myMap = {
        {1, "Apple"},
        {2, "Banana"},
        {3, "Cherry"},
        {4, "Date"}
    };

    // 2. Inserting elements into the map
    myMap[5] = "Elderberry";  // Inserting a new key-value pair
    myMap.insert({6, "Fig"});  // Another way to insert

    // 3. Erasing an element by key
    myMap.erase(2);  // Remove the element with key 2 (Banana)

    // 4. Accessing an element using the key
    cout << "Element with key 3: " << myMap[3] << endl;  // Cherry

    // 5. Checking if a key exists using find()
    auto it = myMap.find(4);  // Find element with key 4
    if (it != myMap.end()) {
        cout << "Found element with key 4: " << it->second << endl;  // Date
    } else {
        cout << "Key 4 not found." << endl;
    }

    // 6. Iterating through the map
    cout << "Iterating through the map: ";
    for (const auto& pair : myMap) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;

    // 7. Checking the size of the map
    cout << "Size of the map: " << myMap.size() << endl;

    // 8. Checking if the map is empty
    if (myMap.empty()) {
        cout << "The map is empty." << endl;
    } else {
        cout << "The map is not empty." << endl;
    }

    // 9. Lower and Upper Bound
    auto lower = myMap.lower_bound(3);  // First element not less than key 3
    auto upper = myMap.upper_bound(3);  // First element greater than key 3

    cout << "Lower bound for key 3: " << (lower != myMap.end() ? to_string(lower->first) + " (" + lower->second + ")" : "Not found") << endl;
    cout << "Upper bound for key 3: " << (upper != myMap.end() ? to_string(upper->first) + " (" + upper->second + ")" : "Not found") << endl;

    // 10. Clearing the map
    myMap.clear();
    cout << "After clearing, the map size is: " << myMap.size() << endl;

    return 0;
}
