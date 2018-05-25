//
// testPoint.cpp
//

#include "Point.h"
#include <iostream>
using namespace std;

int main()
{
  Point a(1,2);
  Point b(3,4);

  cout << a << endl;
  cout << b << endl;
  cout << a+b << endl;
  cout << a-b << endl;
  cout << (a-b).norm2() << endl;
  Point c = a;
  c = c + b - a;
  cout << c << endl;
  cin >> c;
  cout << c << endl;
}
