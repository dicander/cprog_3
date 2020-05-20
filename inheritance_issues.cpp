//
// Created by Marcus Dicander on 2020-05-18.
//

#include <iostream>
using namespace std;

struct base{
    base& operator=(const base& rhs) {
        cout << "base::operator=" << endl;
        return *this;
    }
};


struct derived : public base {
    derived& operator=(const base& rhs) {
        cout << "derived::operator=" << endl;
        return *this;
    }

    void foo(base* p) {}

    void goo(base& ref) {}
};


int main() {
    base b;
    derived d;
    cout << "A) ";
    b = b;
    cout << "B) ";
    b = d;
    cout << "C) ";
    d = b;
    cout << "D) ";
    d = d;
    void* dp;
    d.foo((base*)dp);
    derived& d2 = d;
    d.goo(d2);
}