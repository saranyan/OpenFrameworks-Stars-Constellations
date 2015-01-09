//
//  star.h
//  starChart
//
//  Created by Vigraham, Saranyan on 1/6/15.
//
//

#ifndef starChart_star_h
#define starChart_star_h

#include "ofMain.h"

class Star {
public:
    //constructor
    
    Star(float, float, float, int, vector<string>);
    
    //Methods
    void draw();
    
    
    
    //properties
    float x;
    float y;
    float brightness;
    int hd;
    vector<string> names;
    
    ofColor color;
};


#endif
