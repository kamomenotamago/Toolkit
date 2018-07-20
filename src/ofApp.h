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
    
    void txtsend(ofxTLSwitchEventArgs & args);//Switch入力値処理
    string text1;
    string text2;
    string text3;
    string text4;
    string text5;
    string text6;
    string text7;
    string text8;
    string text9;
    string text10;
    string text11;
    string text12;
    unsigned char num1;
    unsigned char num2;
    unsigned char num3;
    unsigned char num4;
    unsigned char num5;
    unsigned char num6;
    unsigned char num7;
    unsigned char num8;
    unsigned char num9;
    unsigned char num10;
    unsigned char num11;
    unsigned char num12;
    
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
    
    //int currentamount;
};
