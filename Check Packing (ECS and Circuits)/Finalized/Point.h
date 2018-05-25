//
// Point.h
//
#ifndef POINT_H
#define POINT_H
#include<iostream>

class Point
{
  public:
  Point(void) : x(0), y(0) {}
  Point(int xin, int yin) : x(xin), y(yin) {}
  int norm2(void) const { return x*x + y*y; }
  Point operator+(const Point& rhs) const;
  Point operator-(const Point& rhs) const;
  int x, y;
};

std::ostream& operator<<(std::ostream& os, const Point& p);
std::istream& operator>>(std::istream& is, Point& p);
#endif
