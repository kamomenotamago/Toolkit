//
//  SquareConstruction.hpp
//  Toolkit2
//
//  Created by Risa Murakami on 2017/11/29.
//

#ifndef SquareConstruction_hpp
#define SquareConstruction_hpp

#include <stdio.h>
#include "ofMain.h"

class SquareConstruction{
public:
    void setup();
    void draw();
    void mousePressed(int x, int y, int button);
    
    ofPoint squareP1,squareP2,squareP3,squareP4,squareP5,squareP6,squareP7,squareP8;
    bool bsquareP1,bsquareP2,bsquareP3,bsquareP4,bsquareP5,bsquareP6,bsquareP7,bsquareP8;
    int radius;
};
#endif /* SquareConstruction_hpp */
