#include<bits/stdc++.h>
using namespace std;

#include <iostream>
#include <type_traits>
#include <string>

// Basic template function
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Template with multiple parameters
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

// Template with deduction guides
template<typename T>
class Container {
    T value;
public:
    Container(T val) : value(val) {}
    T getValue() const { return value; }
};

// CTAD (Class Template Argument Deduction) - C++17 feature
Container(const char*) -> Container<string>;

int main() {
    // Automatic type deduction
    cout << maximum(10, 20) << endl;        // T is int
    cout << maximum(10.5, 20.7) << endl;    // T is double
    cout << maximum('a', 'b') << endl;      // T is char

    // Mixed type deduction
    auto result = add(10, 20.5);                  // result type is double
    cout << "Mixed type result: " << result << endl;

    // Class template deduction
    Container c1(42);                             // Container<int>
    Container c2("Hello");                        // Container<string>

    cout << "Container values: " << c1.getValue() << ", " << c2.getValue() << endl;

    return 0;
}
