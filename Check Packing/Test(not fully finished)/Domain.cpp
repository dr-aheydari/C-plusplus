//
// First Attempt attempt for HW3: Domain.cpp
//
// Also on my github: https://github.com/dr-aheydari/C-plusplus
// Ali Heydari
// SID: 914 353 432
//
//
//


#include <stdio.h>
#include "Domain.h"
#include "Shape.h"

Domain::Domain(void):sizex(600),sizey(500)
{
    std::cout<<"<?xml version=\"1.0\" encoding=\"utf-8\"  standalone=\"no\"?>" << std::endl;
    std::cout<<"<svg width=\"700\" height=\"600\"" << std::endl;
    std::cout<<"xmlns=\"http://www.w3.org/2000/svg\">"<<std::endl;
    std::cout<<"<g transform=\"matrix(1,0,0,-1,50,550)\""<<std::endl;
    std::cout<<"fill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">"<<std::endl;
    std::cout<<"<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"600\" height=\"500\"/>"<<std::endl;}

Domain::~Domain(void)
{
    
}

void Domain::addShape(const Shape* p)
{
    s.push_back(p);
    p -> draw();
}

void Domain::draw(void)
{
    
    //draw();
    //std::cout<< "<rect fill=\"lightgrey\" x=\"300\" y=\"200\" width=\"100\" height=\"50\"/>" <<std::endl;
    //draw();
    std::cout<<"</g>"<<std::endl;
    std::cout<<"<g transform=\"matrix(1,0,0,1,50,590)\""<<std::endl;
    std::cout<<"font-family=\"Arial\" font-size=\"32\">"<<std::endl;
    
    
     Point p(0,0);
    Rectangle r(p,sizex,sizey);
    
    //std::cout<<std::boolalpha<<r.fits_in(r);
    
    if (r.fits_in(r))
    {
        if (r.overlaps(r) == false)
        {
            r.draw();
            std::cout<<"<text x=\"0\" y=\"0\">ok </text>"<<std::endl;
            
        }
        else if (r.overlaps(r))
        {   r.draw();
            std::cout<<"<text x=\"0\" y=\"0\">overlap overlap</text>"<<std::endl;
                   }
    }
    
    else
        {
            r.draw();
            std::cout<<"<text x=\"0\" y=\"0\">does not fit " << std::endl;
            
        }
    
    std::cout<<"</g>"<<std::endl;
    std::cout<<"</svg>"<<std::endl;
}











