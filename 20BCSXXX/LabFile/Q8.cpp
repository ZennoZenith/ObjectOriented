#include <iostream>

using namespace std;

class Base
{
public:
  Base()
  {
    cout << "Base constructor" << endl;
  }

  // (c) Virtual Destructor
  virtual ~Base()
  {
    cout << "Base destructor" << endl;
  }

  // (a) Pure virtual function
  virtual void pureVirtualFunc() = 0;
};

class Derived : public Base
{
public:
  Derived()
  {
    cout << "Derived constructor" << endl;
  }
  virtual ~Derived()
  {
    cout << "Derived destructor" << endl;
  }
  void pureVirtualFunc()
  {
    cout << "Pure Virtual Function" << endl;
  }

  // << operator overloading using friend function
  friend ostream &operator<<(ostream &os, const Derived &d);
};
ostream &operator<<(ostream &os, const Derived &d)
{
  os << "Overloading through friend function" << endl;
  return os;
}
int main()
{
  // pure virtual function
  Base *base1 = new Derived();
  base1->pureVirtualFunc();

  // pointer to derived class
  Derived *derived1 = new Derived();
  derived1->pureVirtualFunc();

  // virtual destructor
  Derived *derived2 = new Derived();
  Base *base2 = derived2;
  delete base2;

  // overloading through friend function
  Derived derived3;
  cout << derived3 << endl;
  return 0;
}