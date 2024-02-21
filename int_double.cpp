#include <iostream>

using std::cout, std::endl;

struct base {
    void foo(double a) {
        cout << "base::foo(double)" << endl;
    }
};

struct derived : public base {
    void foo(int a) {
        cout << "derived::foo(int)" << endl;
    }
};

int main() {
    derived d;
    d.foo(3);
    d.foo(3.14);
}