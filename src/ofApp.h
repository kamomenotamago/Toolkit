#pragma once

#include "ofMain.h"
#include "ofxTimeline.h"
#include "ofxTextInputField.h"
#include "CircleConstruction.hpp"
#include "SquareConstruction.hpp"
#include "LineConstruction.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
      
    ofxTimeline timeline;
    ofSerial serial;
    ofxTextInputField monoLineTextInput;
    void bang(ofxTLBangEventArgs& args);//Band処理メソッド
    void receivedBang(ofxTLBangEventArgs & args);
    int size;
    string text;

    
    //機能ボタン
    ofPoint circleButton_loop,circleButton_clear,circleButton_save;
    bool loopCircleButton,clearCircleButton,saveCircleButton;
    int radius;
    
    //構造選択ボタン
    ofPoint circle,square,line;
    bool circlebutton,squarebutton,linebutton;
    int radius2;
    
    //Circle構造
    CircleConstruction circle_con;
    //Square構造
    SquareConstruction square_con;
    //Line構造
    LineConstruction line_con;
    
    int r,g,b,a;
};
