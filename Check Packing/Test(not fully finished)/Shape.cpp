//
// First Attempt attempt for HW3: Shape.cpp
//
// Also on my github: https://github.com/dr-aheydari/C-plusplus
// Ali Heydari
// SID: 914 353 432
//
//
//

#include <stdio.h>
#include "Shape.h"
#include <cstdlib>

/* All the Rectangle member functions */

Rectangle::~Rectangle(void)
{
    
}
bool Rectangle::overlaps(const Shape& r) const
{
    return false;
}
bool Rectangle::overlaps(const Circle& c) const
{
    return c.overlaps(c);
}
bool Rectangle::overlaps(const Rectangle& r) const
{
    return false;
}

bool Rectangle::fits_in(const Rectangle& r) const
{
    return true;
}


void Rectangle::draw() const
{
    
    std::cout<<"<rect x=\""<<position.x<<"\" y=\""<<position.y<<"\" width=\""<<width<<"\" height=\""<<height<<"\"/> "<< std::endl;
    
//    for (int i = 0; i < this->size(); i++) {
//        cout << "<rect fill=\""<<this-> color() <<"\" stroke=\"black\" x=\""<< this->x[i]*40 << "\" y=\""<< this -> y[i]*40 <<"\" width=\"40\" height=\"40\"/>" << endl;
//    }
    
}



/* All the Circle member functions */

Circle::~Circle(void)
{
    
}
bool Circle::overlaps(const Shape& s) const
{
    return false;
}
bool Circle::overlaps(const Circle& r) const
{
    return true;
}

bool Circle::overlaps(const Rectangle& r) const
{
    Point lgr(0,0);
    
    // doing the algorithm to find (xn, yn)
    if (center.x <= r.position.x)
    {
        if (r.position.x <= r.position.x + r.width)
            
        {
            lgr.x = r.position.x + r.width;
        }
        else
        {
            lgr.x = r.position.x;
        }
    
    }
    else
    {
        if (center.x <= r.position.x + r.width)
            
        {
            lgr.x = r.position.x + r.width;
        }
        else
        {
            lgr.x = center.x;
        }

      
    }
    
    if (center.y <= r.position.y)
    {
        if (r.position.y <= r.position.y + r.height)
            
        {
            lgr.y = r.position.y + r.height;
        }
        else
        {
            lgr.y = r.position.y;
        }
        
    }
    else
    {
        if (center.y <= r.position.y + r.height)
            
        {
            lgr.y = r.position.y + r.height;
        }
        else
        {
            lgr.y = center.y;
        }
    
    }
    
    // determining overlap
    int dist = (lgr - center).norm2();
    if (dist < (radius * radius))
    {
        return true;
 
    }
    else
    {
        return false;
    }
    
    return false;
}

bool Circle::fits_in(const Rectangle& r) const
{
    return true;
    
}

void Circle::draw(void) const
{   
    std::cout<< "<circle cx=\""<<center.x<<"\" cy=\""<<center.y<<"\" r=\""<<radius<<"\"/> " << std::endl;
}




























