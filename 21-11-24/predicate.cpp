#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    // 1. Creating a set of integers
    set<int> mySet = {10, 20, 30, 40, 50, 60, 70};

    // 2. Define a threshold value
    int threshold = 30;

    // 3. Using a predicate (lambda function) to find elements greater than the threshold
    cout << "Elements greater than " << threshold << ": ";
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        if (*it > threshold) {
            cout << *it << " ";
        }
    }
    cout << endl;

    // 4. Using `std::find_if` with a predicate to find the first element greater than the threshold
    auto it = find_if(mySet.begin(), mySet.end(), [threshold](int value) {
        return value > threshold;
    });

    if (it != mySet.end()) {
        cout << "First element greater than " << threshold << ": " << *it << endl;
    } else {
        cout << "No elements greater than " << threshold << endl;
    }

    return 0;
}
