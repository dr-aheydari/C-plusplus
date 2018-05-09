//
// Restaurant.h
//
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "Table.h"
class Restaurant
{
  public:
  Restaurant(int nLarge, int nMedium, int nSmall);
  void addGuests(int nGuests);
  void printSummary(void);

  private:
  const int size;
  Table** tableList;
};
#endif
