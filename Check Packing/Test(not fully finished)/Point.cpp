//
// First Attempt attempt for HW3: point.cpp
//
// Also on my github: https://github.com/dr-aheydari/C-plusplus
// Ali Heydari
// SID: 914 353 432
//
//
//

#include <iostream>
#include "Point.h"



Point Point::operator+(const Point& rhs) const
     
     {
         // just add the values already stored with the rhs
         int x_sum =  x + rhs.x ;
         int y_sum =  y + rhs.y;
         //make a new point object and return it!
         const Point new_point(x_sum,y_sum);
         return new_point;
     
     }

     
Point Point::operator-(const Point& rhs) const
     {
         // substract the value by the right hand side of the minus
         int x_diff = x - rhs.x;
         int y_diff = y - rhs.y;
         Point new_point(x_diff,y_diff);
         return new_point;
         
     }


std::ostream& operator<<(std::ostream& os, const Point& p)
{
    // cout in the given format
    os << "("<< p.x << "," << p.y << ")";
    
    return os;
}

std::istream& operator>>(std::istream& is, Point& p)
{
    // to get ints from the use
    int x_val,y_val;
    // dummy character, whether space, comma or whatever
    char space;
    // get the input
    is >> x_val;
    is >> space;
    is >> y_val;
    // initialize a point object
    Point pnt(x_val,y_val);
    // give reference to so it saves it
    p = pnt;
    // bingo
    return is;
}





