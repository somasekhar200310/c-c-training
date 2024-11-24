#include <iostream>
#include <vector>
using namespace std;

// Function that takes a vector and prints its elements
void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    // Passing an initializer list to the function
    printVector({1, 2, 3, 4, 5});

    return 0;
}
