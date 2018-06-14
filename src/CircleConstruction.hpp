//

//  CircleConstruction.hpp

//  Toolkit2

//

//  Created by Risa Murakami on 2017/11/29.

//



#ifndef CircleConstruction_hpp
#define CircleConstruction_hpp
#include <stdio.h>
#include "ofMain.h"

class CircleConstruction{
public:
    void setup();
    void draw();
    void mousePressed(int x, int y, int button);
    
    ofPoint circleP1,circleP2,circleP3,circleP4,circleP5,circleP6,circleP7,circleP8;
    bool bcircleP1,bcircleP2,bcircleP3,bcircleP4,bcircleP5,bcircleP6,bcircleP7,bcircleP8;
    int radius;
    
};



#endif /* CircleConstruction_hpp */


