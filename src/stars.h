//
//  stars.h
//  starChart
//
//  Created by Vigraham, Saranyan on 1/6/15.
//
//

#ifndef __starChart__stars__
#define __starChart__stars__

#include "ofMain.h"
#include "star.h"
#include <fstream>

class Stars {
public:
    //constructor
    
    Stars();
    
    //Methods
    void draw();
    //stanford prj
    void parseFromSimpleStarchart_Stanford();
    void plotConstellations();
    void drawConstellation(string);
    
    
    //properties to support stanford DS
    vector<Star> collection; //star collection
    map<string, int>stars_ni; //star name and index
    
    
    ofColor color;
};


#endif /* defined(__starChart__stars__) */
