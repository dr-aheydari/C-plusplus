//
// Shape.h
//
#ifndef SHAPE_H
#define SHAPE_H
#include "Point.h"
#include <iostream>

class Circle;
class Rectangle;

class Shape
{
  public:
  virtual ~Shape(void) {}
  virtual bool overlaps(const Shape& s) const = 0;
  virtual bool overlaps(const Circle& r) const = 0;
  virtual bool overlaps(const Rectangle& r) const = 0;
  virtual bool fits_in(const Rectangle& r) const = 0;
  virtual void draw(void) const = 0;
};

class Rectangle : public Shape
{
  public:
  Rectangle(void): position(Point(0,0)), width(0), height(0) {}
  Rectangle(Point p, int w, int h) :
    position(p), width(w), height(h) {}
  virtual ~Rectangle(void);
  virtual bool overlaps(const Shape& r) const;
  virtual bool overlaps(const Circle& r) const;
  virtual bool overlaps(const Rectangle& r) const;
  virtual bool fits_in(const Rectangle& r) const;
  virtual void draw(void) const;

  const Point position;    // position of the lower left corner
  const int width, height;
};

class Circle : public Shape
{
  public:
  Circle(void): center(Point(0,0)), radius(0) {}
  Circle(Point c, int r) : center(c),radius(r) {}
  virtual ~Circle(void);
  virtual bool overlaps(const Shape& s) const;
  virtual bool overlaps(const Circle& r) const;
  virtual bool overlaps(const Rectangle& r) const;
  virtual bool fits_in(const Rectangle& r) const;
  virtual void draw(void) const;

  Point center;
  int radius;
};
#endif
