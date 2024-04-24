// main.cpp (Roland Teodorowitsch; 12 abr. 2022)

#include <iostream>
#include "Complex.hpp"

using namespace std;

int main() {
  Complex a(1,2),b(3,4);
  cout << "a.str()=" << a.str() << endl;
  cout << "b.str()=" << b.str() << endl;
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;
  cout << "a.getReal()      = " << a.getReal() << endl;
  cout << "a.getImaginary() = " << a.getImaginary() << endl;
  cout << endl;

  Complex c;
  c = a.sum(b);
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;
  cout << "c=a.sum(b)=" << c << endl;
  cout << endl;

  Complex d(5,6),e(7,8),f;
  f = d + e;
  cout << "d=" << d << endl;
  cout << "e=" << e << endl;
  cout << "f=d+e=" << f << endl;
  cout << endl;

  f = d - e;
  cout << "d=" << d << endl;
  cout << "e=" << e << endl;
  cout << "f=d-e=" << f << endl;
  cout << endl;

  cout << "a=" << a << endl;
  cout << "b=" << b << endl;
  c = a * b;
  cout << "c=a*b=" << c << endl;
  cout << endl;

  cout << "a=" << a << endl;
  c = -a;
  cout << "c=-a=" << c << endl;
  cout << endl;

  d = a;
  cout << "a=" << a << endl;
  cout << "c=" << c << endl;
  cout << "d=" << d << endl;
  if ( a == c )
     cout << "a == c" << endl;
  else
     cout << "a != c" << endl;
  if ( a == d )
     cout << "a == d" << endl;
  else
     cout << "a != d" << endl;
  if ( a != c )
     cout << "a != c" << endl;
  else
     cout << "a == c" << endl;
  if ( a != d )
     cout << "a != d" << endl;
  else
     cout << "a == d" << endl;
  cout << endl;

  cout << "e=" << e << endl;
  cout << "e:" << endl;
  cin >> e;
  cout << "e=" << e << endl;

  return 0;
}
