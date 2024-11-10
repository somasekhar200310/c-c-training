#include <iostream>
using namespace std;

class Printer {
public:
    void print(int& i) {     // Function that takes a reference to int
        cout << "Printing integer by reference: " << i << endl;
    }

    void print(int* i) {     // Function that takes a pointer to int
        cout << "Printing integer by pointer: " << *i << endl;
    }
};

int main() {
    Printer p;
    int x = 10;
    p.print(x);      // Calls print(int&) because 'x' is passed by reference

    p.print(&x);     // Calls print(int*) because '&x' is passed as a pointer

    return 0;
}
