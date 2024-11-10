#include <iostream>
using namespace std;

class Printer {
public:
    void print(int i) {
        cout << "Printing integer: " << i << endl;
    }

    void print(double d) {
        cout << "Printing double: " << d << endl;
    }

    void print(const char* str) {
        cout << "Printing string: " << str << endl;
    }
};

int main() {
    Printer p;
    p.print(10);           // Calls print(int)
    p.print(3.14);         // Calls print(double)
    p.print("Hello!");     // Calls print(const char*)

    return 0;
}
