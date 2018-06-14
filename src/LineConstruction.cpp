//
//  LineConstruction.cpp
//  Toolkit2
//
//  Created by Risa Murakami on 2017/11/29.
//

#include "LineConstruction.hpp"
void LineConstruction::setup(){
    lineP1.set(190,330);
    lineP2.set(260,300);
    lineP3.set(333,266);
    lineP4.set(400,230);
    lineP5.set(470,195);
    lineP6.set(540,160);
    lineP7.set(608,124);
    lineP8.set(680,90);
    
    blineP1= false;
    blineP2= false;
    blineP3= false;
    blineP4= false;
    blineP5= false;
    blineP6= false;
    blineP7= false;
    blineP8= false;
    radius = 25;
}

void LineConstruction::draw(){
    ofSetColor(47);
    ofDrawRectangle(150,50,570,310);
    ofDrawRectangle(730,50,570,310);
    
    ofSetColor(ofColor::darkCyan);
    
    ofCircle(lineP1, radius);
    ofCircle(lineP2, radius);
    ofCircle(lineP3, radius);
    ofCircle(lineP4, radius);
    ofCircle(lineP5, radius);
    ofCircle(lineP6, radius);
    ofCircle(lineP7, radius);
    ofCircle(lineP8, radius);
}

void LineConstruction::mousePressed(int x, int y, int button){
    
}
