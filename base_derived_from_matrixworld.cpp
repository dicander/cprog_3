#include <iostream>
using namespace std;
struct base {
  virtual base foo() {
    cout << "base::foo() "; return *this;
  }
};
struct derived : base {
  virtual base foo() {
    cout << "derived::foo() "; return *this;
  }
};
int main() {
  derived derived_object;
  base base_object = derived_object;
  base & ref = derived_object;
  cout << endl << "a) "; derived_object.foo();
  cout << endl << "b) "; base_object.foo();
  cout << endl << "c) "; ref.foo();
  cout << endl << "d) "; ref.foo().foo(); cout << endl;
}
