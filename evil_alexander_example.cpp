#include<iostream>
using namespace std;
struct TheMatrix{
  virtual TheMatrix foo() 
    {
      cout<<"TheMatrix::foo()";return *this;
    }
};
struct TheWorld:TheMatrix{
  virtual TheMatrix foo(){
    cout<<"TheWorld::foo()";return *this;
  }
};
int main(){
  TheWorld world;
  TheMatrix matrix=world;
  TheMatrix& ref=world;
  cout<<endl<<"a)";world.foo();
  cout<<endl<<"b)";matrix.foo();
  cout<<endl<<"c)";ref.foo();
  cout<<endl<<"d)";ref.foo().foo();cout<<endl;
}
