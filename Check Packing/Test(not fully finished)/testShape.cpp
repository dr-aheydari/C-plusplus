//
// testShape.cpp
//

#include "Shape.h"
#include <iostream>
using namespace std;

int main()
{
  Point center(10,30);
  const int radius = 50;
  Circle c(center,radius);
  c.draw();

  Point llcorner = Point(50,70);
  const int width = 25;
  const int height = 80;
  Rectangle r1(llcorner,width,height);
  r1.draw();

  Rectangle r2(llcorner+Point(20,30),width,height);
  r2.draw();

  Circle c1(Point(60,160),10);
  c1.draw();
  Circle c2(llcorner-Point(5,-5),100);
  c2.draw();

  cout << boolalpha << r1.overlaps(r2) << endl;
  cout << boolalpha << r2.overlaps(c1) << endl;
  cout << boolalpha << c2.overlaps(r2) << endl;
}
