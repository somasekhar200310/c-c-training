#include <iostream>
using namespace std;

class Printer {
public:
    void print(int i) {
        cout << "Printing integer: " << i << endl;
    }

    void print(int i, double d) {
        cout << "Printing integer and double: " << i << ", " << d << endl;
    }

    void print(int i, double d, const char* str) {
        cout << "Printing integer, double, and string: " << i << ", " << d << ", " << str << endl;
    }
};

int main() {
    Printer p;
    p.print(10);                  // Calls the first version
    p.print(10, 20.5);             // Calls the second version
    p.print(10, 20.5, "Hello!");   // Calls the third version

    return 0;
}
