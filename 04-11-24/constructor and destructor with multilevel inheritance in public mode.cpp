#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base class constructor" << endl;
    }

    ~Base() {
        cout << "Base class destructor" << endl;
    }
};

class Derived1 : public Base {
public:
    Derived1() {
        cout << "Derived1 class constructor" << endl;
    }

    ~Derived1() {
        cout << "Derived1 class destructor" << endl;
    }
};

class Derived2 : public Derived1 {
public:
    Derived2() {
        cout << "Derived2 class constructor" << endl;
    }

    ~Derived2() {
        cout << "Derived2 class destructor" << endl;
    }
};

int main() {
    Derived2 obj;
    return 0;
}
