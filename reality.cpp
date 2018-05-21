#include <string>
#include <iostream>
struct A {
    A() : a(this) {}
    virtual void foo() { std::cout << "a "; }
    A * a;
};
struct B : public A {
    B() : b(this) {}
    virtual void foo() { std::cout << "b "; }
    B * b;
};
struct C : public B {
    virtual void foo() { std::cout << "c "; }
};
int main() {
    C c;
    B b = c; // copy
    B & b1 = c;
    B & b2 = b;
    A & a1 = b1;
    A & a2 = b2;
    a1.foo();
    a2.foo();
    std::cout << std::endl;
    a1.a->foo();
    a2.a->foo();
    std::cout << std::endl;
    b1.b->foo();
    b2.b->foo();
    std::cout << std::endl;
}
