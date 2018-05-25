//
// Final Attempt attempt for HW3: Domain.cpp
//
// Also on my github: https://github.com/dr-aheydari/C-plusplus
// Ali Heydari
// SID: 914 353 432
//
//
//


#include <stdio.h>
#include <vector>
#include "Domain.h"
#include "Shape.h"


Domain::Domain(void):sizex(600),sizey(500)
{
    std::cout<<"<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>" << std::endl;
    std::cout<<"<svg width=\"700\" height=\"600\"" << std::endl;
    std::cout<<"xmlns=\"http://www.w3.org/2000/svg\">"<<std::endl;
    std::cout<<"<g transform=\"matrix(1,0,0,-1,50,550)\""<<std::endl;
    std::cout<<"fill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">"<<std::endl;
    std::cout<<"<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"600\" height=\"500\"/>"<<std::endl;}

Domain::~Domain(void)
{
//    s.clear();
//    std::vector<const Shape*>(s).swap(s);
    
    std::vector<const Shape*>::iterator i;
    for(i = s.begin(); i != s.end(); ++i)
    {
        delete (*i);//delete data that was pointed
        *i = 0;
    }
    s.clear();
    //std::vector<const Shape*>().swap(s);
    
    
}

void Domain::addShape(const Shape* p)
{
    s.push_back(p);
    /* did not work well at all
     //    for ( int  i = 0; i < s.size(); i ++)
     //    {
     //std:: cout << *s[i] << std:: endl;
     //std::cout<< std::boolalpha << (*s[i]) << std::endl;
     //        if (p -> overlaps(*s[i]))
     //        {
     //            std::cout<<"<text x=\"0\" y=\"0\">ok </text>"<<std::endl;
     //        }
     //        else
     //        {
     //            std::cout<<"BULLCRAP"<<std::endl;
     //
     //        }
     //    }
     */
    p -> draw();
}

void Domain::draw(void)

{
    std::cout<<"</g>"<<std::endl;
    std::cout<<"<g transform=\"matrix(1,0,0,1,50,590)\""<<std::endl;
    std::cout<<" font-family=\"Arial\" font-size=\"32\">"<<std::endl;
    
    Point p(0,0);
    
    Rectangle* r = new Rectangle(p,sizex,sizey);
    
    int counter = 0 ;
    int bounter = 0;
    for ( unsigned int  i = 0; i < s.size(); i ++)
    {
        if(s[i] -> fits_in(*r))
        {
            //std::cout << " FUCK YES" << std::endl;
            // DO NOTHING FOR NOW
        }
        
        else
        {
            counter++;
        }
        
        for (unsigned int j = 0; j < s.size() ; j++)
        {
            if (i != j && s[i] -> overlaps(*s[j]))
            {
                bounter ++;
                //  std::cout<< " bounter: " << bounter;
            }
        }
    }
    
    if (counter > 0)
    {
        std::cout<<"<text x=\"0\" y=\"0\">does not fit</text>" << std::endl;
        
    }
    else if (counter == 0 && bounter == 0 )
    {
        
        std::cout<<"<text x=\"0\" y=\"0\">ok</text>"<<std::endl;
        
    }
    
    else if (counter == 0 && bounter > 0)
        
    {
        std::cout<<"<text x=\"0\" y=\"0\">overlap</text>"<<std::endl;
        
    }
    
    std::cout<<"</g>"<<std::endl;
    std::cout<<"</svg>"<<std::endl;
    
    delete r;
    
}
