#include <iostream>

class A {
public:
    A() { std::cout << "A's constructor\n"; }
    void show() { std::cout << "A's show()\n"; }
};

class B : virtual public A {
public:
    B() { std::cout << "B's constructor\n"; }
};

class C : virtual public A {
public:
    C() { std::cout << "C's constructor\n"; }
};

class D : public B, public C {
public:
    D() { std::cout << "D's constructor\n"; }
};

int main() {
    D d;
    d.show();  // No ambiguity now, A's show() will be called.
    return 0;
}
