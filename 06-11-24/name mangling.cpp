#include <iostream>
using namespace std;

class MyClass {
public:
    void display(int i) {
        cout << "Display integer: " << i << endl;
    }

    void display(double d) {
        cout << "Display double: " << d << endl;
    }
};

int main() {
    MyClass obj;
    obj.display(5);        // Calls display(int)
    obj.display(3.14);     // Calls display(double)
    return 0;
}
