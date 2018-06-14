//
//  SquareConstruction.cpp
//  Toolkit2
//
//  Created by Risa Murakami on 2017/11/29.
//

#include "SquareConstruction.hpp"
void SquareConstruction::setup(){
    squareP1.set(445,110);
    squareP2.set(545,115);
    squareP3.set(545,205);
    squareP4.set(545,295);
    squareP5.set(445,300);
    squareP6.set(345,295);
    squareP7.set(345,205);
    squareP8.set(345,115);
    
    bsquareP1= false;
    bsquareP2= false;
    bsquareP3= false;
    bsquareP4= false;
    bsquareP5= false;
    bsquareP6= false;
    bsquareP7= false;
    bsquareP8= false;
    radius = 25;

}

void SquareConstruction::draw(){
    ofSetColor(47);
    ofDrawRectangle(150,50,570,310);
    ofDrawRectangle(730,50,570,310);
    
    ofSetColor(ofColor::darkCyan);
    
    ofCircle(squareP1, radius);
    ofCircle(squareP2, radius);
    ofCircle(squareP3, radius);
    ofCircle(squareP4, radius);
    ofCircle(squareP5, radius);
    ofCircle(squareP6, radius);
    ofCircle(squareP7, radius);
    ofCircle(squareP8, radius);
    
}

void SquareConstruction::mousePressed(int x, int y, int button){
    
}
