//

//  CircleConstruction.cpp

//  Toolkit2

//

//  Created by Risa Murakami on 2017/11/29.

//
#include "CircleConstruction.hpp"

void CircleConstruction::setup(){
    circleP1.set(445,90);
    circleP2.set(535,125);
    circleP3.set(575,205);
    circleP4.set(535,285);
    circleP5.set(445,320);
    circleP6.set(355,285);
    circleP7.set(320,205);
    circleP8.set(355,125);
    
    bcircleP1= false;
    bcircleP2= false;
    bcircleP3= false;
    bcircleP4= false;
    bcircleP5= false;
    bcircleP6= false;
    bcircleP7= false;
    bcircleP8= false;
    radius = 25;
}
void CircleConstruction::draw(){
    ofSetColor(47);
    ofDrawRectangle(150,50,570,310);
    ofDrawRectangle(730,50,570,310);
    
    ofSetColor(ofColor::darkCyan);
    
    ofCircle(circleP1, radius);
    ofCircle(circleP2, radius);
    ofCircle(circleP3, radius);
    ofCircle(circleP4, radius);
    ofCircle(circleP5, radius);
    ofCircle(circleP6, radius);
    ofCircle(circleP7, radius);
    ofCircle(circleP8, radius);
    
    ofSetColor(ofColor::whiteSmoke);
  
}
void CircleConstruction::mousePressed(int x,int y,int button){
    
}
