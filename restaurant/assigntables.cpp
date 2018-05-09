//
// assigntables.cpp
//

#include <iostream>
#include "Restaurant.h"
using namespace std;

int main(void)
{
  // create a Restaurant with 1 large table, 2 medium tables and 3 small tables
  Restaurant restaurant(1,2,3);

  do
  {
    try
    {
      int party_size = 0;
      cin >> party_size;
      if ( cin )
      {
        cout << "Trying to seat party of " << party_size << endl;
        restaurant.addGuests(party_size);
      }
    }
    catch( invalid_argument &e )
    {
      cout << "Invalid party size: " << e.what() << " (skipped)" << endl;
    }
  }
  while ( cin );

  restaurant.printSummary();
}
