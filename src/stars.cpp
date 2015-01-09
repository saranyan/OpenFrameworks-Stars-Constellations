//
//  stars.cpp
//  starChart
//
//  Created by Vigraham, Saranyan on 1/6/15.
//
//

#include "stars.h"


Stars::Stars(){
    
    //populate the collection array
    parseFromSimpleStarchart_Stanford();
    ofLog(OF_LOG_NOTICE) << "parsed data for " << collection.size() << " stars...";
}

//this method parses data from simple starchart - stanford univ project
//The project is located at http://nifty.stanford.edu/2009/reid-starmap/starmap.html

void Stars::parseFromSimpleStarchart_Stanford() {
    
    ifstream fin; //declare a file stream
    fin.open( ofToDataPath("stars.txt").c_str() ); //open your text file
    
    //vector<string> data; //declare a vector of strings to store data
    
    while(fin!=NULL) //as long as theres still text to be read
    {
        string str; //declare a string for storage
        getline(fin, str); //get a line from the file, put it in the string
        //data.push_back(str); //push the string onto a vector of strings
        
        vector<string>result;
        result = ofSplitString(str, " ");
        
        if(result.size() == 6){
            //no names
            vector<string>names;
            Star s = Star(ofToFloat(result[0]),ofToFloat(result[1]),ofToFloat(result[4]),ofToInt(result[3]),names);
            collection.push_back(s);
            
        }
        else if(result.size() > 6) {
            //names
            vector<string>names;
            names = ofSplitString(str,";");
            //ofLog(OF_LOG_NOTICE) << " test:  " << names[0];
            if(names.size() == 1){
                //there are no semis. it has only one name
                //concat the names first
                string temp_name = "";
                for(int i = 6; i < result.size(); i++){
                    temp_name += result[i] + " ";
                }
                names[0] = temp_name;

            }
            //corner case, names might be empty. currently not handling that.
            else {
                //there are multiple names
                vector<string> temp_names = ofSplitString(names[0]," ");
                string temp_name = "";
                for(int i = 6; i < temp_names.size(); i++){
                    temp_name += temp_names[i] + " ";
                }
                names[0] = temp_name;
            }
            
            //eliminate leading and trailing whitespaces
            for(int i = 0; i < names.size(); i++){
                string value = names[i];
                //leading white space
                value.erase(value.begin(), std::find_if(value.begin(), value.end(), std::bind1st(std::not_equal_to<char>(), ' ')));
                //trailing white space
                value.erase(std::find_if(value.rbegin(), value.rend(), std::bind1st(std::not_equal_to<char>(), ' ')).base(), value.end());
                names[i] = value;
            }
            

            //create the star and add it to the collection
            
            Star s = Star(ofToFloat(result[0]),ofToFloat(result[1]),ofToFloat(result[4]),ofToInt(result[3]),names);
            collection.push_back(s);
            
            //hash map of names to index for plotting
            
            for(int i = 0; i < names.size(); i++){
                stars_ni[names[i]] = collection.size()-1;
                //ofLog(OF_LOG_NOTICE) << " name:  " << names[i] << " val " << stars_ni[names[i]];
            }
        }
        
        
    }
}

void Stars::draw(){
    
    int frame_number = (ofGetFrameNum()%60);
    
    //to make things twinkle a bit
    //int twinkle = 1;
    //int twinkle_factor_color = frame_number/2;
    //int twinkle_factor_size = frame_number/100;
    
    //ofLog(OF_LOG_NOTICE) << "current frame number is " << frame_number;
    
    //draw all stars from the collection
    for (auto coll = collection.begin(); coll != collection.end(); ++coll)
    {
        //set the star's brightness using HSB - max values (360,100,100)
        color.setHsb(360,0, 100*coll->brightness);
        
        
        ofSetColor(color);
        ofFill();
        
        //star is a circle with radius 1
        //ofCircle(coll->x,coll->y,1);
        float star_size = round(10.0 / (coll->brightness + 2));
        ofRect(coll->x, coll->y,star_size,star_size);
        
    }
    
}

void Stars::plotConstellations(){
    //load constellation files the directory
    //ofLogNotice(ofToDataPath("stars.txt").c_str());
    
    //data/constellations
    ofDirectory dir(ofToDataPath("constellations"));
    
    //only show txt files
    dir.allowExt("txt");
    
    //populate the directory object
    dir.listDir();
    
    //go through and print out all the paths
    for(int i = 0; i < dir.numFiles(); i++){
        //ofLogNotice(dir.getPath(i));
        //read constellation here and do a draw
        drawConstellation(dir.getPath(i));
    }
}

void Stars::drawConstellation(string path) {
    
    //print the map for debugging
    
//    for(map<string, int >::const_iterator it = stars_ni.begin();
//        it != stars_ni.end(); ++it)
//    {
//        std::cout << it->first << "," << it->second << "\n";
//    }
    
    ifstream fin; //declare a file stream
    fin.open(path.c_str()); //open your text file
    while(fin!=NULL) //as long as theres still text to be read
    {
        string str; //declare a string for storage
        getline(fin, str); //get a line from the file, put it in the string
        //ofLog(OF_LOG_NOTICE) << str << " " << str.length();
        if(str.length() > 0){
            vector<string> stemp = ofSplitString(str, ",");
//            ofLog(OF_LOG_NOTICE) << stemp[0] << " " << stemp[1];
//            ofLog(OF_LOG_NOTICE) << stars_ni[stemp[0]] << " " << stars_ni[stemp[1]];
            
            Star star1 = collection[stars_ni[stemp[0]]];
            Star star2 = collection[stars_ni[stemp[1]]];
            
            //ofLog(OF_LOG_NOTICE) << star1.x << " " << star1.y;
            
            ofLine(star1.x,star1.y,star2.x,star2.y);
            //ofCircle(star1.x, star1.y, 50);
        }
       

    }

    
}