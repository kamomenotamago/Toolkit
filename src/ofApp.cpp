#include "ofApp.h"

ofTrueTypeFont font;
ofVec2f location;

//スイッチイベント定義
ofxTLSwitchEventArgs args;
//--------------------------------------------------------------

void ofApp::setup(){
    
    //機能ボタン
    circleButton_loop.set(1375,450);
    circleButton_clear.set(1375,725);
    circleButton_save.set(1375,588);
    loopCircleButton = false;
    clearCircleButton = false;
    saveCircleButton = false;
    radius = 50;
    
    //構造選択ボタン
    circle.set(70,100);
    square.set(70,200);
    line.set(70,300);
    circlebutton = true;
    squarebutton = false;
    linebutton = false;
    radius2 = 40;
    
    //セットアップ
    ofxTimeline::removeCocoaMenusFromGlut("Toolkit2");
    ofSetWindowShape(1500, 1000);
    ofBackground(50);
    ofSetVerticalSync(false);
    timeline.setup();
    timeline.setFrameRate(50);
    timeline.setDurationInFrames(2000);
    timeline.setPageName("1");
    timeline.saveTracksToFolder("/Users/Risa/Desktop/oF");//なんかフォルダーに保存できる
    location = ofVec2f(10,360); //画面の中心に
    timeline.setOffset(location);
    timeline.setWidth(1300);
    timeline.setHeight(900);
    
    //音楽
    timeline.addAudioTrack("audio2","ele.wav");
    
    //スイッチ
    timeline.addSwitches("SmartHair 1");
    timeline.addSwitches("SmartHair 2");
    timeline.addSwitches("SmartHair 3");
    timeline.addSwitches("SmartHair 4");
    //timeline.addFlags("bang");
    
    //色
    timeline.addColors("color");
    //ofBackground(timeline.getColor("color"));
    //ofBackground(timeline.getColorAtMillis("color",10000));
    //ofColor now;
    //now.r=timeline.getColor("color").r;
    //cout<<"[red]"<<now.r;
    
     /*r = timeline.getColor("color").r;
     g = timeline.getColor("color").g;
     b = timeline.getColor("color").b;
     a = timeline.getColor("color").a;*/
    
    
    //2ページ目
    timeline.addPage("2");
    timeline.addAudioTrack("audio2","ele.wav");
    timeline.addSwitches("SmartHair 5");
    timeline.addSwitches("SmartHair 6");
    timeline.addSwitches("SmartHair 7");
    timeline.addSwitches("SmartHair 8");
    
    //3ページ目
    timeline.addPage("3");
    timeline.addAudioTrack("audio2","ele.wav");
    timeline.addSwitches("SmartHair 9");
    timeline.addSwitches("SmartHair 10");
    timeline.addSwitches("SmartHair 11");
    timeline.addSwitches("SmartHair 12");
    
    
    //テキスト
    monoLineTextInput.setup();
    monoLineTextInput.text ="";
    monoLineTextInput.bounds.x = 30;
    monoLineTextInput.bounds.y = 280;
    monoLineTextInput.bounds.height = 40;
    monoLineTextInput.bounds.width = 188;
    ofSetColor(0);
    font.loadFont(OF_TTF_SERIF, 18);
    monoLineTextInput.setFont(font);
    
    //シリアルセット
    serial.setup("/dev/cu.usbmodem1411",115200);
    
    //Switch数字反映メソッドリスナー登録
    ofAddListener(timeline.events().switched, this,&ofApp::txtsend);//Switchが発生する度にこのメソッドが呼ばれる

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    r = timeline.getColor("color").r;
    g = timeline.getColor("color").g;
    b = timeline.getColor("color").b;
    a = timeline.getColor("color").a;
    ofSetColor(ofColor(r,g,b,a));
    ofBox(290,700,10);
    
   
    //機能ボタン
    ofSetColor(ofColor::whiteSmoke);
    font.drawString("Loop",1347,390);
    font.drawString("Save",1349,533);
    font.drawString("Clear",1346,670);
    
    //構造選択ボタン
    font.drawString("Construction",10,40);

    
    //ループボタン詳細
    if(loopCircleButton){
        timeline.setLoopType(OF_LOOP_NORMAL);
        ofSetColor(ofColor::sandyBrown);
        ofCircle(circleButton_loop, radius);
        ofSetColor(ofColor::whiteSmoke);
        font.drawString("OFF",1352,460);
    }else{
        timeline.setLoopType(OF_LOOP_NONE);
        ofSetColor(ofColor::dimGray);
        ofCircle(circleButton_loop, radius);
        ofSetColor(ofColor::whiteSmoke);
        font.drawString("ON",1357,460);
    }
  
    //クリアボタン詳細
    if (clearCircleButton){
        ofSetColor(ofColor::sandyBrown);
        timeline.clear();
    }else{
       ofSetColor(ofColor::dimGray);
    }
    ofCircle(circleButton_clear, radius);
    
    
    //セーブボタン詳細
    if (saveCircleButton){
        ofSetColor(ofColor::sandyBrown);
        timeline.save();
    }else{
        ofSetColor(ofColor::dimGray);
    }
    ofCircle(circleButton_save, radius);
    
    
    //Circleボタン詳細
    if (circlebutton){
        ofSetColor(ofColor::hotPink);
         ofCircle(circle, radius2);
        //circlewindow
        circle_con.setup();
        circle_con.draw();
    }else{
        ofSetColor(ofColor::dimGray);
         ofCircle(circle, radius2);
    }
    ofSetColor(ofColor::whiteSmoke);
    font.drawString("Circle",40,107);
    
    //Squareボタン詳細
    if (squarebutton){
        ofSetColor(ofColor::hotPink);
        ofCircle(square, radius2);
        //squarewindow
        square_con.setup();
        square_con.draw();
    }else{
        ofSetColor(ofColor::dimGray);
        ofCircle(square, radius2);
    }
    ofSetColor(ofColor::whiteSmoke);
    font.drawString("Square",37,205);
    
    //Lineボタン詳細
    if (linebutton){
        ofSetColor(ofColor::hotPink);
        ofCircle(line, radius2);
        //linewindow
        line_con.setup();
        line_con.draw();
    }else{
        ofSetColor(ofColor::dimGray);
        ofCircle(line, radius2);
    }
  
    ofSetColor(ofColor::whiteSmoke);
    font.drawString("Line",50,307);
    
　　//テキスト
    //ofRect(monoLineTextInput.bounds);
    //ofNoFill();
    //monoLineTextInput.draw();
    //monoLineTextInput.beginEditing();
    
    //タイムライン
    timeline.draw();

    //スイッチイベント定義
    ofxTLSwitchEventArgs args;
    
    //スイッチからシリアル通信
    //switch1 & 1番pin
    if(timeline.isSwitchOn("SmartHair 1")){
        bool byteWasWritten1 = serial.writeByte(1);
        bool byteWasWritten2 = serial.writeByte(num1);
        //Switch数値int型で表示
        ofDrawBitmapString(num1,1300,500);
    }else{
        bool byteWasWritten1 = serial.writeByte(1);
        bool byteWasWritten2 = serial.writeByte(0);
    }
    
    //switch2 &　2番pin
    if(timeline.isSwitchOn("SmartHair 2")){
        bool byteWasWritten1 = serial.writeByte(2);
        bool byteWasWritten2 = serial.writeByte(num2);

        //Switch数値int型で表示
        ofDrawBitmapString(num2,1300,550);
    }else{
        bool byteWasWritten1 = serial.writeByte(2);
        bool byteWasWritten2 = serial.writeByte(0);
    }
    
    //switch3 &　3番pin
    if(timeline.isSwitchOn("SmartHair 3")){
        bool byteWasWritten1 = serial.writeByte(3);
        bool byteWasWritten2 = serial.writeByte(num3);
        //Switch数値int型で表示
        ofDrawBitmapString(num3,1300,600);
    }else{
        bool byteWasWritten1 = serial.writeByte(3);
        bool byteWasWritten2 = serial.writeByte(0);
    }
    
    //switch4 &　4番pin
    if(timeline.isSwitchOn("SmartHair 4")){
        bool byteWasWritten1 = serial.writeByte(4);
        bool byteWasWritten2 = serial.writeByte(num4);
    }else{
        bool byteWasWritten1 = serial.writeByte(4);
        bool byteWasWritten2 = serial.writeByte(0);
    }
    
    //switch5 & 5番pin
    if(timeline.isSwitchOn("SmartHair 5")){
        bool byteWasWritten1 = serial.writeByte(5);
        bool byteWasWritten2 = serial.writeByte(num5);
    }else{
        bool byteWasWritten1 = serial.writeByte(5);
        bool byteWasWritten2 = serial.writeByte(0);
    }
    //switch6 &　6番pin
    if(timeline.isSwitchOn("SmartHair 6")){
        bool byteWasWritten1 = serial.writeByte(6);
        bool byteWasWritten2 = serial.writeByte(num6);
    }else{
        bool byteWasWritten1 = serial.writeByte(6);
        bool byteWasWritten2 = serial.writeByte(0);
    }
    
    //switch7 &　7番pin
    if(timeline.isSwitchOn("SmartHair 7")){
        bool byteWasWritten1 = serial.writeByte(7);
        bool byteWasWritten2 = serial.writeByte(num7);
    }else{
        bool byteWasWritten1 = serial.writeByte(7);
        bool byteWasWritten2 = serial.writeByte(0);
    }
    
    //switch8 &　8番pin
    if(timeline.isSwitchOn("SmartHair 8")){
        bool byteWasWritten1 = serial.writeByte(8);
        bool byteWasWritten2 = serial.writeByte(num8);
    }else{
        bool byteWasWritten1 = serial.writeByte(8);
        bool byteWasWritten2 = serial.writeByte(0);
    }
    
    //switch9 & 9番pin
    if(timeline.isSwitchOn("SmartHair 9")){
        bool byteWasWritten1 = serial.writeByte(9);
        bool byteWasWritten2 = serial.writeByte(num9);
    }else{
        bool byteWasWritten1 = serial.writeByte(9);
        bool byteWasWritten2 = serial.writeByte(0);
    }
    //switch10 &　10番pin
    if(timeline.isSwitchOn("SmartHair 10")){
        bool byteWasWritten1 = serial.writeByte(10);
        bool byteWasWritten2 = serial.writeByte(num10);
    }else{
        bool byteWasWritten1 = serial.writeByte(10);
        bool byteWasWritten2 = serial.writeByte(0);
    }
    
    //switch11 &　11番pin
    if(timeline.isSwitchOn("SmartHair 11")){
        bool byteWasWritten1 = serial.writeByte(11);
        bool byteWasWritten2 = serial.writeByte(num11);
    }else{
        bool byteWasWritten1 = serial.writeByte(11);
        bool byteWasWritten2 = serial.writeByte(0);

    }
    
    //switch12 &　12番pin
    if(timeline.isSwitchOn("SmartHair 12")){
        bool byteWasWritten1 = serial.writeByte(12);
        bool byteWasWritten2 = serial.writeByte(num12);
    }else{
        bool byteWasWritten1 = serial.writeByte(12);
        bool byteWasWritten2 = serial.writeByte(0);
    }
}

void ofApp::txtsend(ofxTLSwitchEventArgs & args){
    
    if(args.track->getName() == "SmartHair 1"){
        text1 = args.switchName;
        num1 = atoi(text1.c_str());
    }else if(args.track->getName() == "SmartHair 2"){
        text2 = args.switchName;
        num2 = atoi(text2.c_str());
    }else if(args.track->getName() == "SmartHair 3"){
        text3 = args.switchName;
        num3 = atoi(text3.c_str());
    }else if(args.track->getName() == "SmartHair 4"){
        text4 = args.switchName;
        num4 = atoi(text4.c_str());
    }else if(args.track->getName() == "SmartHair 5"){
        text5 = args.switchName;
        num5 = atoi(text5.c_str());
    }else if(args.track->getName() == "SmartHair 6"){
        text6 = args.switchName;
        num6 = atoi(text6.c_str());
    }else if(args.track->getName() == "SmartHair 7"){
        text7 = args.switchName;
        num7 = atoi(text7.c_str());
    }else if(args.track->getName() == "SmartHair 8"){
        text8 = args.switchName;
        num8 = atoi(text8.c_str());
    }else if(args.track->getName() == "SmartHair 9"){
        text9 = args.switchName;
        num9 = atoi(text9.c_str());
    }else if(args.track->getName() == "SmartHair 10"){
        text10 = args.switchName;
        num10 = atoi(text10.c_str());
    }else if(args.track->getName() == "SmartHair 11"){
        text11 = args.switchName;
        num11 = atoi(text11.c_str());
    }else if(args.track->getName() == "SmartHair 12"){
        text12 = args.switchName;
        num12 = atoi(text12.c_str());
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
    //機能ボタン押されたか
    if (circleButton_loop.distance(ofPoint(x,y)) < radius) {
        loopCircleButton = !loopCircleButton;
    }
    
    if (circleButton_clear.distance(ofPoint(x,y)) < radius) {
        clearCircleButton = !clearCircleButton;
    }
    
    if (circleButton_save.distance(ofPoint(x,y)) < radius) {
        saveCircleButton = !saveCircleButton;
    }
    
    //構造ボタン押されたか
    if (circle.distance(ofPoint(x,y)) < radius2) {
        circlebutton = !circlebutton;
    }
    
    if (square.distance(ofPoint(x,y)) < radius2) {
        squarebutton = !squarebutton;
    }
    
    if (line.distance(ofPoint(x,y)) < radius2) {
        linebutton = !linebutton;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
