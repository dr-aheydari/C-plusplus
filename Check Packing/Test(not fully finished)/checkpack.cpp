//
// checkpack.cpp
//

#include "Domain.h"
#include<iostream>
using namespace std;

int main()
{
  Domain d;
  char type;
  int x,y,w,h,r;

  cin >> type;
  while (cin)
  {
    if ( type == 'C' )
    {
      cin >> x >> y >> r;
      Shape* p = new Circle(Point(x,y),r);
      d.addShape(p);
    }
    else if ( type == 'R' )
    {
      cin >> x >> y >> w >> h;
      Shape* p = new Rectangle(Point(x,y),w,h);
      d.addShape(p);
    }
    cin >> type;
  }
  d.draw();
}
