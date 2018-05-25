//
// Final Attempt attempt for HW3: Shape.cpp
//
// Also on my github: https://github.com/dr-aheydari/C-plusplus
// Ali Heydari
// SID: 914 353 432
//
//
//

#include <cstdlib>
#include <stdio.h>
#include "Shape.h"


/* All the Rectangle member functions */

Rectangle::~Rectangle(void)
{
    
}

bool Rectangle::overlaps(const Shape& r) const
{
    return r.overlaps(*this);
    
}

bool Rectangle::overlaps(const Rectangle& r) const


{
    
    bool horizontal = (position.x < r.position.x + r.width) && (position.x + this->width > r.position.x);
    bool vertical = (position.y < r.position.y + r.height) && (position.y + this->height > r.position.y);
    
    if (horizontal && vertical)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    /* another that I found online for debugging
     //return x_overlap && y_overlap;
     
     //    // ANOTHER ONE
     //    // return !(x_1 > x_2+width_2 || x_1+width_1 < x_2 || y_1 > y_2+height_2 || y_1+height_1 < y_2);
     //
     //
     //    bool result1 = r.position.x >= position.x && r.position.y >= position.y && r.position.x <= (position.x + width) && r.position.y <= (position.y + height); // other's top left falls within this area
     //
     //
     //    // if x coordinate is the same this tells it's overlap (thinks that hights intersect )
     //
     //    //    bool result2 = r.position.x >= this -> position.x && r.position.y <= this -> position.y && r.position.x <= (this -> position.x + width) && (r.position.y + r.height) <= (this -> position.y + height); // other's bottom left falls within this area
     //    bool result2 = false;
     //
     //    // when y coordinate is the same this tells it's overlap (thinks that widths intersect )
     //    //    bool result3 = r.position.x <= position.x && r.position.y >= position.y && (r.position.x + r.width) <= (position.x + width) && r.position.y <= (position.y + height); // other's top right falls within this area
     //
     //    bool result3 = false;
     //
     //    bool result4 = r.position.x <= position.x && r.position.y <= position.y && (r.position.x + r.width) >= position.x && (r.position.y + r.height) >= position.y; // other's bottom right falls within this area
     //
     //    // DEBUG
     //    //std:: cout << result1  <<  result2  << result3  << result4 << std::endl;
     //
     //    return result1 || result2 || result3 || result4;
     */
    
}

bool Rectangle::overlaps(const Circle& r) const
{
    
    // or if want to do it from the cirlce function
    
    //    return r.overlaps(*this);
    
    // given algorithm in the homework
    
    int x_n = std::min(std::max(r.center.x, this->position.x),this->position.x+this->width);
    int y_n = std::min(std::max(r.center.y, this->position.y),this->position.y+this->height);
    
    int x_dist = x_n - r.center.x;
    int y_dist = y_n - r.center.y;
    
    int dist = (x_dist * x_dist) + (y_dist * y_dist);
    
    bool overlap = dist < (r.radius * r.radius);
    return overlap;
    
    
    
}




bool Rectangle::fits_in(const Rectangle& r) const
{
    /*DEBUG
     std::cout<<"RECT CALLED : " << r.position.x << std::endl;
     std::cout<<"SHIT SHIT SHIT: " << r.position.y << std::endl; */
    
    // check in two direction if they fit
    bool horizontal = this->position.x >= r.position.x && this->position.x + this->width <= r.position.x + r.width;
    bool vertical = this->position.y >= r.position.y && this->position.y + this->height <= r.position.y + r.height;
    
    if(horizontal && vertical)
    {
        return true;
    }
    else
    {
        return false;
    }
    // return true;
}


void Rectangle::draw() const
{
    // cout the the svg code for the shape
    std::cout<<"<rect x=\""<<position.x<<"\" y=\""<<position.y<<"\" width=\""<<width<<"\" height=\""<<height<<"\"/>"<< std::endl;
    
}





/* All the Circle member functions */


Circle::~Circle(void)
{
    
}
bool Circle::overlaps(const Shape& s) const
{
    return s.overlaps(*this);
}
bool Circle::overlaps(const Circle& r) const
{
    
    // found this technique from https://www.geeksforgeeks.org/check-two-given-circles-touch-intersect/
    // but the code is mine
    int x1 = this -> center.x ; ///<<std::endl;
    int x2 = r.center.x; /// <<std::endl;
    int y1 = this -> center.y;
    int y2 = r.center.y;
    int r1 = this -> radius;
    int r2 = r.radius;
    
    //    int distSq = ((this -> center.x) - r.center.x) * ((this -> center.x) - r.center.x) +
    //    ((this -> center.y) - r.center.y) * ((this -> center.y) - r.center.y);
    //    int radSumSq = ((this -> radius) + r.radius) * ((this -> radius) + r.radius);
    
    int dist = (x1 - x2) * (x1 - x2) +
    (y1 - y2) * (y1 - y2);
    int radius_mult = (r1 + r2) * (r1 + r2);
    
    if (dist == radius_mult)
    {
        return false;
    }
    
    else if (dist > radius_mult)
        
    {   // intersect
        return false;
    }
    
    else
        
    {
        return true;
    }
}

bool Circle::overlaps(const Rectangle& r) const
{
    
    return r.overlaps(*this);
    
    /* had one test case that didn't work with this one
     //     Point lgr(0,0);
     //
     //     // doing the algorithm to find (xn, yn)
     //     if (center.x <= r.position.x)
     //     {
     //     if (r.position.x <= r.position.x + r.width)
     //
     //     {
     //     lgr.x = r.position.x + r.width;
     //     }
     //     else
     //     {
     //     lgr.x = r.position.x;
     //     }
     //
     //     }
     //     else
     //     {
     //     if (center.x <= r.position.x + r.width)
     //
     //     {
     //     lgr.x = r.position.x + r.width;
     //     }
     //     else
     //     {
     //     lgr.x = center.x;
     //     }
     //
     //
     //     }
     //
     //     if (center.y <= r.position.y)
     //     {
     //     if (r.position.y <= r.position.y + r.height)
     //
     //     {
     //     lgr.y = r.position.y + r.height;
     //     }
     //     else
     //     {
     //     lgr.y = r.position.y;
     //     }
     //
     //     }
     //     else
     //     {
     //     if (center.y <= r.position.y + r.height)
     //
     //     {
     //     lgr.y = r.position.y + r.height;
     //     }
     //     else
     //     {
     //     lgr.y = center.y;
     //     }
     //
     //     }
     //
     //     // determining overlap
     //     int dist = (lgr - center).norm2();
     //
     //     if (dist < (radius * radius))
     //     {
     //     return true;
     //
     //     }
     //     else
     //     {
     //     return false;
     //     }
     //
     */
    
    
}

bool Circle::fits_in(const Rectangle& r) const
{
    bool horizontal = center.x+radius >= r.position.x && center.x+radius <= r.position.x + r.width;
    bool vertical = center.y+radius >= r.position.y && center.y+radius <= r.position.y + r.height;
    
    return horizontal && vertical;
    
}

void Circle::draw(void) const
{       // cout the the svg code for the shape
    std::cout<< "<circle cx=\""<<center.x<<"\" cy=\""<<center.y<<"\" r=\""<<radius<<"\"/>" << std::endl;
}
