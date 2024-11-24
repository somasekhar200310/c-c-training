#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <forward_list>

using namespace std;

int main() {
    // Vector - Dynamic array
    // Using fill constructor
    vector<int> vec1(5, 10);  // Creates vector with 5 elements, all set to 10
    
    // Using iterator constructor
    vector<int> vec2(vec1.begin(), vec1.end());
    
    // Using size constructor
    vector<int> vec3(5);  // Creates vector with 5 elements, all set to 0
    
    // Using copy constructor
    vector<int> vec4(vec2);
    
    // Using move constructor
    vector<int> vec5 = std::move(vec4);
    
    // Using initializer list (original way)
    vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);
    // Deque - Double-ended queue
    deque<int> deq = {10, 20, 30};
    deq.push_front(5);
    deq.push_back(40);

    // List - Doubly linked list
    list<int> lst = {100, 200, 300};
    lst.push_front(50);
    lst.push_back(400);

    // Array - Fixed-size array
    array<int, 5> arr = {1, 2, 3, 4, 5};

    // Forward List - Singly linked list
    forward_list<int> fwd_lst = {1000, 2000, 3000};
    fwd_lst.push_front(500);

    // Printing vector
    cout << "Vector elements: ";
    for(const auto& element : vec) {
        cout << element << " ";
    }
    cout << "\n";

    // Printing deque
    cout << "Deque elements: ";
    for(const auto& element : deq) {
        cout << element << " ";
    }
    cout << "\n";

    // Printing list
    cout << "List elements: ";
    for(const auto& element : lst) {
        cout << element << " ";
    }
    cout << "\n";

    // Printing array
    cout << "Array elements: ";
    for(const auto& element : arr) {
        cout << element << " ";
    }
    cout << "\n";

    // Printing forward list
    cout << "Forward list elements: ";
    for(const auto& element : fwd_lst) {
        cout << element << " ";
    }
    cout << "\n";

    return 0;
}
