//Eric Feng
//921306906
#include "Domain.h"
#include<iostream>
#include<vector>
#include<stdio.h>
#include <string>
using namespace std;

Domain::Domain()    {
    sizex = 600;
    sizey = 500;
}

Domain::~Domain()   {
}

void Domain::addShape(const Shape* p)   {
    s.push_back(p);
}

void Domain::draw(void) {
    Rectangle Big_Square(Point(0, 0), sizex, sizey);
    string output;
    bool overlap = false;
    bool fit = false;
    vector<const Shape*>::iterator iter;
    vector<const Shape*>::iterator iter2;
    cout << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>" << endl;
    cout << "<svg width=\"700\" height=\"600\"" << endl;
    cout << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    cout << "<g transform=\"matrix(1,0,0,-1,50,550)\"" << endl;
    cout << "fill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">" << endl;
    cout << "<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\""<< sizex << "\" height=\"" << sizey << "\"/>" << endl;
    for (iter = s.begin(); iter != s.end(); iter++)  {
        (**iter).draw();
        for (iter2 = s.begin(); iter2 != s.end(); iter2++)  {
            if (iter2 != iter && (**iter2).overlaps(**iter))   {
                overlap = true;   
            }
        }
        if ((**iter).fits_in(Big_Square) == false)  {
            fit = true;
        }
    }
    cout << "</g>" << endl;
    cout << "<g transform=\"matrix(1,0,0,1,50,590)\"" << endl;
    cout << " font-family=\"Arial\" font-size=\"32\">" << endl;
    if (fit)    {
        output = "does not fit";
    }   else if (overlap)  {
        output = "overlap";
    } else  {
        output = "ok";
    }
    cout << "<text x=\"0\" y=\"0\">" << output << "</text>" << endl;
    cout << "</g>" << endl;
    cout << "</svg>" << endl;

}