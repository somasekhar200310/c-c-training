#include <iostream>
using namespace std;

class Base {
public:
    void show() {
        cout << "Base class show function" << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived class show function" << endl;
    }

    void callBaseShow() {
        Base::show();
    }
};

int main() {
    Derived obj;
    obj.show();
    obj.callBaseShow();
    return 0;
}
