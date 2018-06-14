#include "ofApp.h"
ofTrueTypeFont font;
ofVec2f location;
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
    timeline.setup();
    timeline.setFrameRate(30);
    timeline.setDurationInFrames(2000);
    timeline.setPageName("1");
    timeline.saveTracksToFolder("/Users/Risa/Desktop/oF");//なんかフォルダーに保存できる
    location = ofVec2f(10,360); //画面の中心に
    timeline.setOffset(location);
    timeline.setWidth(1300);
    timeline.setHeight(900);


    
    //音楽
    timeline.addAudioTrack("audio2","futta-fly.wav");
    
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
    timeline.addAudioTrack("audio2","futta-fly.wav");
    timeline.addSwitches("SmartHair 5");
    timeline.addSwitches("SmartHair 6");
    timeline.addSwitches("SmartHair 7");
    timeline.addSwitches("SmartHair 8");
    
    //3ページ目
    timeline.addPage("3");
    timeline.addAudioTrack("audio2","futta-fly.wav");
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
    serial.setup("/dev/cu.usbmodem1411",9600);
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

    //スイッチからシリアル通信
    //switch1 & 13番pin
    if(timeline.isSwitchOn("SmartHair 1")){
        serial.writeByte('1');
    }
    else{
        serial.writeByte('2');
    }
    //switch2 &　12番pin
    if(timeline.isSwitchOn("SmartHair 2")){
        serial.writeByte('3');
    }
    else{
        serial.writeByte('4');
    }
    
    //switch3 &　11番pin
    if(timeline.isSwitchOn("SmartHair 3")){
        serial.writeByte('5');
        
    }
    else{
        serial.writeByte('6');
    }
    
    //switch4 &　10番pin
    if(timeline.isSwitchOn("SmartHair 4")){
        serial.writeByte('7');
    }
    else{
        serial.writeByte('8');
    }
    
    //switch1 & 9番pin
    if(timeline.isSwitchOn("SmartHair 5")){
        serial.writeByte('9');
    }
    else{
        serial.writeByte('a');
    }
    //switch2 &　8番pin
    if(timeline.isSwitchOn("SmartHair 6")){
        serial.writeByte('b');
    }
    else{
        serial.writeByte('c');
    }
    
    //switch3 &　7番pin
    if(timeline.isSwitchOn("SmartHair 7")){
        serial.writeByte('d');
    }
    else{
        serial.writeByte('e');
    }
    
    //switch4 &　6番pin
    if(timeline.isSwitchOn("SmartHair 8")){
        serial.writeByte('f');
    }
    else{
        serial.writeByte('g');
    }
    
    //switch1 & 5番pin
    if(timeline.isSwitchOn("SmartHair 9")){
        serial.writeByte('h');
    }
    else{
        serial.writeByte('i');
    }
    //switch2 &　4番pin
    if(timeline.isSwitchOn("SmartHair 10")){
        serial.writeByte('j');
    }
    else{
        serial.writeByte('k');
    }
    
    //switch3 &　3番pin
    if(timeline.isSwitchOn("SmartHair 11")){
        serial.writeByte('l');
    }
    else{
        serial.writeByte('m');
    }
    
    //switch4 &　2番pin
    if(timeline.isSwitchOn("SmartHair 12")){
        serial.writeByte('n');
    }
    else{
        serial.writeByte('o');
    }
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    /*if(key=='a'){
        serial.writeByte('2');
    }
    
    if(key=='s'){
        serial.writeByte('3');
    }*/
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
