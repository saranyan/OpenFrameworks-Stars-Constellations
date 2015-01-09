#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    //enable smoothing
    ofEnableSmoothing();
    
    //Fixed framerate
    ofSetFrameRate(30);
    
    //set datapath
    //ofSetDataPathRoot("./data");
    
    gui = new ofxUICanvas();
    gui->addLabelButton("LOAD CONSTELLATIONS", false);
    ofAddListener(gui->newGUIEvent,this,&ofApp::guiEvent);
       
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //the color of night sky
    ofBackground(ofColor::black);
    
    
    //draw stars
    stars.draw();
    if(constellation) stars.plotConstellations();
}

void ofApp::guiEvent(ofxUIEventArgs &e)
{
    
    string name = e.widget->getName();
    int kind = e.widget->getKind();
    if(kind == OFX_UI_WIDGET_LABELBUTTON)
    {
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        constellation = true;
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
