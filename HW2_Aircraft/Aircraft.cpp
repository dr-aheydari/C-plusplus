//
// Second attempt for HW2: Aircraft.cpp
//
// Ali Heydari
// SID: 914 353 432
//
//
//
#include <iostream>
#include "Aircraft.h"

using namespace std;
/* ctor */

Aircraft::Aircraft(int n, std::string name_str):numEng(n),nm(name_str)
{
    //{   cout<<numEng<<endl;
//    cout <<"Aircraft Ctor is called"<< endl;
    hrs = new int(n);
    
}


const string Aircraft::name(void) const //const
{
    
    return nm;
}



int Aircraft::numEngines(void) const
{
    return numEng;
}

// come back to this
void Aircraft::setHours(int i, int h)
//A member function used to set the current number of hours of use for engine i .
{   i =  i - 1;
    
    hrs[i] = hrs[i] - h;
    
//    cout<<"h: "<< hrs[i] <<endl;
//    cout<< " Set hours i: "<< i << " h: "<< hrs[i] << endl;
}

void Aircraft::print(void) const
{
    //A member function that prints the description of the aircraft on standard output (see first part of the above example).
     {
     cout << "Aircraft: " <<name()<< " type:"<< type() << "has "<< numEngines() << " engines"
     <<endl;
         
         for (int i = 0; i < numEng; i++)
         {
         
             cout<< "engine "<< i+1 << ": " << (750 - hrs[i]) << " hours" << endl;
     
         }

     }
    
    
    
    
}


void Aircraft::printSchedule(void) const
//A member function that prints the maintenance schedule of the aircraft on standard output (see above example)
{
    cout << "Maintenance schedule for "<< name() << endl;
    
    for (int i = 0; i < numEng; i++)
    {
          cout <<"engine " << i+1 <<" maintenance due in "<< hrs[i] <<" hours" <<endl;
    }
}


 Aircraft* Aircraft::makeAircraft(char ch, std::string name_str)
{
    switch (ch)
    {
        case 'A':
        {
            return new A380(name_str);
            break;
        }
            
        case 'B':
        {
            return new B737(name_str);
        }
        default:
        {   throw invalid_argument("invalid type");
            return nullptr;
            break;
    
        }

    }
    
}
/* Dervided Ctors */

A380::A380(std::string name_str):Aircraft(4,name_str)
{
//    cout<<" Calling the A380 Ctor"<<endl;
    maxHours();
    
}

B737::B737(std::string name_str):Aircraft(2,name_str)
{
//    cout<<" Calling the B737 Ctor"<<endl;
    maxHours();
}

Aircraft::~Aircraft() {};



/* Derived Member Function */

////////////////


////////////////
const string A380::type(void) const
{
    return " Airbus A380 ";
}

const string B737::type(void) const
{
    return " Boeing 737 ";
}

const int A380::maxHours(void) const
{
    
    
    hrs[0] = 750;
    hrs[1] = 750;
    hrs[2] = 750;
    hrs[3] = 750;
    
//    for (int i = 0; i < 4;i++)
//    {
//    
//        cout<<"MAX CALLED: "<< hrs[i]<< endl;
//        
//
//    }
    return *hrs;
}

const int B737::maxHours(void) const
{
    hrs[0] = 500;
    hrs[1] = 500;
    return *hrs;
}

/*

A static factory function that creates an Aircraft object of the appropriate type (determined by the character ch) and returns a pointer to it. If ch is ‘A’, an A380 must be created. If ch is ‘B’, a B737 must be created.
*/
