//
//  star.cpp
//  starChart
//
//  Created by Vigraham, Saranyan on 1/6/15.
//
//


#include "star.h"

Star::Star(float x1, float y1, float brightness1, int hd1, vector<string> names1){
    //map x,y from star data (-1,1) to window units
    
    x = ((x1+1)/2)*ofGetWidth();
    y = ((y1+1)/2)*ofGetHeight();
    brightness = brightness1;
    hd = hd1;
    names = names1;
    //ofLog(OF_LOG_NOTICE) << "x " << x << " y " << y;
    
}


void Star::draw(){
}
