#include <iostream>
using namespace std;

class Base {
private:
    int x;
protected:
    int y;
public:
    int z;

    Base() : x(10), y(20), z(30) {}

    void show() {
        cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    }
};

class Derived1 : private Base {
public:
    Derived1() {
        // x is not accessible because it's private in Base
        // y is accessible because it's protected in Base
        cout << "Derived1 constructor" << endl;
    }

    void show() {
        // x is not accessible
        // y is accessible
        // z is accessible
        cout << "y = " << y << ", z = " << z << endl;
    }
};

class Derived2 : protected Derived1 {
public:
    Derived2() {
        // x is not accessible
        // y is accessible
        // z is accessible
        cout << "Derived2 constructor" << endl;
    }

    void show() {
        // y is accessible
        // z is accessible
        cout << "y = " << y << ", z = " << z << endl;
    }
};

int main() {
    Derived2 obj;
    obj.show();
    return 0;
}
