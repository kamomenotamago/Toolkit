//
//  LineConstruction.hpp
//  Toolkit2
//
//  Created by Risa Murakami on 2017/11/29.
//

#ifndef LineConstruction_hpp
#define LineConstruction_hpp

#include <stdio.h>
#include "ofMain.h"

class LineConstruction{
public:
    void setup();
    void draw();
    void mousePressed(int x, int y, int button);
    
    ofPoint lineP1,lineP2,lineP3,lineP4,lineP5,lineP6,lineP7,lineP8;
    bool blineP1,blineP2,blineP3,blineP4,blineP5,blineP6,blineP7,blineP8;
    int radius;
};
#endif /* LineConstruction_hpp */
