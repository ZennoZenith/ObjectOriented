#include <iostream>

using namespace std;

class Complex
{
  float real;
  float img;

public:
  Complex(int r = 0, int i = 0) : real(r), img(i) {}

  Complex operator+=(const Complex &c)
  {
    real += c.real;
    img += c.img;
    return *this;
  }
  Complex operator-=(const Complex &c)
  {
    real -= c.real;
    img -= c.img;
    return *this;
  }
  Complex operator*=(const Complex &c)
  {
    int r = real;
    real = real * c.real - img * c.img;
    img = r * c.img + img * c.real;
    return *this;
  }
  Complex operator/=(const Complex &c)
  {
    int r = real;
    real = (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img);
    img = (img * c.real - r * c.img) / (c.real * c.real + c.img * c.img);
    return *this;
  }
  friend ostream &operator<<(ostream &out, Complex &c);
};

ostream &operator<<(ostream &out, Complex &c)
{
  out << c.real;
  if (c.img >= 0)
    cout << " + ";
  else
    cout << " - ";
  cout << abs(c.img) << "i";
  return out;
}

int main()
{
  Complex c1(1, 2), c2(3, -4);
  cout << "c1 = " << c1 << endl;
  cout << "c2 = " << c2 << endl;

  c1 += c2;
  cout << "\nc1 += c2 = " << c1 << endl;
  c1 -= c2;
  cout << "\nc1 -= c2 = " << c1 << endl;
  c1 *= c2;
  cout << "\nc1 *= c2 = " << c1 << endl;
  c1 /= c2;
  cout << "\nc1 /= c2 = " << c1 << endl;
  return 0;
}