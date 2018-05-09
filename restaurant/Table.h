//
// Table.h
//
#ifndef TABLE_H
#define TABLE_H
class Table
{
  public:
    Table(int n);
    int maxOccupancy(void);
    int currentOccupancy(void);
    bool addGuests(int n);
  private:
    const int maxGuests;
    int numGuests;
};
#endif
