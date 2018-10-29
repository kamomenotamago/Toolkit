#include "ofApp.h"

ofTrueTypeFont font;
ofVec2f location;
//Webカメラ
ofVideoGrabber vidGrabber;
ofImage img;
int camWidth, camHeight;

//スイッチイベント定義
ofxTLSwitchEventArgs args;
//--------------------------------------------------------------

void ofApp::setup(){

    //機能ボタン
    circleButton_loop.set(1375,350);
    circleButton_save.set(1375,470);
    circleButton_load.set(1375,590);
    circleButton_clear.set(1375,725);
    loopCircleButton = false;
    clearCircleButton = false;
    saveCircleButton = false;
    radius = 40;
    
    //構造選択ボタン
    circle.set(70,100);
    square.set(70,200);
    line.set(70,300);
    circlebutton = true;
    squarebutton = false;
    linebutton = false;
    radius2 = 40;
    
    //アクチュエーター選定ボタン
    actuator_power.set(1080,50);
    actuator_speed.set(1080,165);
    actuator_length.set(1250,50);
    actuator_color.set(1250,165);
    actuator_powersenter.set(1150,100);
    actuator_speedsenter.set(1150,235);
    actuator_lengthsenter.set(1320,100);
    actuator_colorsenter.set(1320,235);
    actuatorpowerButton = 0;
    actuatorspeedButton = 0;
    actuatorlengthButton = 0;
    actuatorcolorButton = 0;
    
    //Webカメラ
    ofEnableSmoothing();
    ofSetFrameRate(10);
    //キャプチャする画像のサイズを指定
    camWidth = 300;
    camHeight = 200;
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(camWidth, camHeight);
    
    //移動番号ボタン
    circle1.set(xPos1,yPos1);
    circle2.set(xPos2,yPos2);
    circle3.set(xPos3,yPos3);
    circle4.set(xPos4,yPos4);
    circle5.set(xPos5,yPos5);
    circle6.set(xPos6,yPos6);
    radius3 = 15;
    circle1Button=false;
    circle2Button=false;
    circle3Button=false;
    circle4Button=false;
    circle5Button=false;
    circle6Button=false;
    
    //セットアップ
    ofxTimeline::removeCocoaMenusFromGlut("Toolkit2");
    ofSetWindowShape(1500, 1000);
    ofBackground(50);
    ofSetVerticalSync(false);
    timeline.setup();
    timeline.setFrameRate(50);
    timeline.setDurationInFrames(4000);
    timeline.setPageName("1");
    location = ofVec2f(10,300); //画面の中心に
    timeline.setOffset(location);
    timeline.setWidth(1300);
    timeline.setHeight(900);
    
    //音楽
    timeline.addAudioTrack("audio2","proto3.wav");
    
    //ビデオ再生
    smarthairmoving1.load("movies/smarthair1.mov");
    smarthairmoving1.play();
    smarthairmoving2.load("movies/smarthair2.mov");
    smarthairmoving2.play();
    smarthairmoving3.load("movies/smarthair3.mov");
    smarthairmoving3.play();
    
    //スイッチ
    timeline.addSwitches("No1");//pwm3
    timeline.addSwitches("No2");//pem5
    timeline.addSwitches("No3");//pem6
    timeline.addSwitches("No4");//pem9
    timeline.addSwitches("No5");//pem10
    timeline.addSwitches("No6");//pem11
    
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
    /*timeline.addPage("2");
    timeline.addAudioTrack("audio2","proto3.wav");
    timeline.addSwitches("SmartHair 5");
    timeline.addSwitches("SmartHair 6");
    //timeline.addSwitches("SmartHair 7");
    //timeline.addSwitches("SmartHair 8");
    
    //3ページ目
    timeline.addPage("3");
    timeline.addAudioTrack("audio2","proto3.wav");
    timeline.addSwitches("SmartHair 9");
    timeline.addSwitches("SmartHair 10");
    timeline.addSwitches("SmartHair 11");
    timeline.addSwitches("SmartHair 12");*/
    
    
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
    //キャプチャする
    vidGrabber.update();
    
    //ビデオアップデート
    smarthairmoving1.update();
    smarthairmoving2.update();
    smarthairmoving3.update();
    
    //移動番号ボタン位置アップデート
    circle1.set(xPos1,yPos1);
    circle2.set(xPos2,yPos2);
    circle3.set(xPos3,yPos3);
    circle4.set(xPos4,yPos4);
    circle5.set(xPos5,yPos5);
    circle6.set(xPos6,yPos6);
}

//--------------------------------------------------------------
void ofApp::draw(){
    //色
    r = timeline.getColor("color").r;
    g = timeline.getColor("color").g;
    b = timeline.getColor("color").b;
    a = timeline.getColor("color").a;
    
    bool byteWasWritten1 = serial.writeByte(14);
    bool byteWasWritten2 = serial.writeByte(r);
    bool byteWasWritten3 = serial.writeByte(g);
    bool byteWasWritten4 = serial.writeByte(b);
    //ofSetColor(ofColor::white);
    //ofDrawBitmapString(r,1300,550);
    
    ofSetColor(ofColor(r,g,b,a));
    //ofBox(290,700,10);
    
    
    ofSetColor(47);
    ofDrawRectangle(20,20,670,265);
    ofDrawRectangle(710,20,710,265);
    
    //アクチュエーター選定ボタン
    if(actuatorpowerButton==0){
        ofSetColor(ofColor::lightPink);
        ofDrawRectangle(actuator_power,150,100);
        ofSetColor(ofColor::white);
        font.drawString("Level 1",1115,130);
        //ビデオ再生
        smarthairmoving1.draw(750, 80, 300, 200);
    }else if(actuatorpowerButton==1){
        ofSetColor(ofColor::hotPink);
        ofDrawRectangle(actuator_power,150,100);
        ofSetColor(ofColor::white);
        font.drawString("Level 2",1115,130);
        //ビデオ再生
        smarthairmoving2.draw(750, 80, 300, 200);
    }else{
        ofSetColor(ofColor::deepPink);
        ofDrawRectangle(actuator_power,150,100);
        ofSetColor(ofColor::white);
        font.drawString("Level 3",1115,130);
        //ビデオ再生
        smarthairmoving3.draw(750, 80, 300, 200);
    }
    
    if(actuatorspeedButton==0){
        ofSetColor(ofColor::lightPink);
        ofDrawRectangle(actuator_speed,150,100);
        ofSetColor(ofColor::white);
        font.drawString("Level 1",1115,245);
    }else if(actuatorspeedButton==1){
        ofSetColor(ofColor::hotPink);
        ofDrawRectangle(actuator_speed,150,100);
        ofSetColor(ofColor::white);
        font.drawString("Level 2",1115,245);
    }else{
        ofSetColor(ofColor::deepPink);
        ofDrawRectangle(actuator_speed,150,100);
        ofSetColor(ofColor::white);
        font.drawString("Level 3",1115,245);
    }
    
    if(actuatorlengthButton==0){
        ofSetColor(ofColor::lightPink);
        ofDrawRectangle(actuator_length,150,100);
        ofSetColor(ofColor::white);
        font.drawString("Level 1",1285,130);
    }else if(actuatorlengthButton==1){
        ofSetColor(ofColor::hotPink);
        ofDrawRectangle(actuator_length,150,100);
        ofSetColor(ofColor::white);
        font.drawString("Level 2",1285,130);
    }else{
        ofSetColor(ofColor::deepPink);
        ofDrawRectangle(actuator_length,150,100);
        ofSetColor(ofColor::white);
        font.drawString("Level 3",1285,130);
    }
    
    if(actuatorcolorButton==0){
        ofSetColor(ofColor::lightPink);
        ofDrawRectangle(actuator_color,150,100);
        ofSetColor(ofColor::white);
        font.drawString("Level 1",1290,245);
    }else if(actuatorcolorButton==1){
        ofSetColor(ofColor::hotPink);
        ofDrawRectangle(actuator_color,150,100);
        ofSetColor(ofColor::white);
        font.drawString("Level 2",1290,245);
    }else{
        ofSetColor(ofColor::deepPink);
        ofDrawRectangle(actuator_color,150,100);
        ofSetColor(ofColor::white);
        font.drawString("Level 3",1290,245);
    }
  
    
    //Webカメラ
    ofSetColor(0xFFFFFF);
    vidGrabber.draw(70,80);
    
    //機能ボタン
    ofSetColor(ofColor::whiteSmoke);
    font.drawString("Loop",1347,300);
    font.drawString("Save",1349,420);
    font.drawString("Load",1347,540);
    font.drawString("Clear",1346,670);
    font.drawString("Actuator",720,50);
    font.drawString("Power",1120,100);
    font.drawString("Speed",1120,215);
    font.drawString("Length",1290,100);
    font.drawString("Color",1295,215);
    font.drawString("Viewing",30,50);
    
    //構造選択ボタン
    //font.drawString("Construction",10,40);
    
    //移動番号ボタン
    ofSetColor(ofColor::darkCyan);
    ofCircle(xPos1,yPos1, radius3);
    ofCircle(xPos2,yPos2, radius3);
    ofCircle(xPos3,yPos3, radius3);
    ofCircle(xPos4,yPos4, radius3);
    ofCircle(xPos5,yPos5, radius3);
    ofCircle(xPos6,yPos6, radius3);
    ofSetColor(ofColor::white);
    font.drawString("1",xPos1-6,yPos1+8);
    font.drawString("2",xPos2-6,yPos2+8);
    font.drawString("3",xPos3-6,yPos3+8);
    font.drawString("4",xPos4-6,yPos4+8);
    font.drawString("5",xPos5-6,yPos5+8);
    font.drawString("6",xPos6-6,yPos6+8);
    
    //ループボタン詳細
    if(loopCircleButton){
        timeline.setLoopType(OF_LOOP_NORMAL);
        ofSetColor(ofColor::sandyBrown);
        ofCircle(circleButton_loop, radius);
        ofSetColor(ofColor::whiteSmoke);
        font.drawString("OFF",1352,360);
    }else{
        timeline.setLoopType(OF_LOOP_NONE);
        ofSetColor(ofColor::dimGray);
        ofCircle(circleButton_loop, radius);
        ofSetColor(ofColor::whiteSmoke);
        font.drawString("ON",1357,360);
    }
  
    //クリアボタン詳細
    if (clearCircleButton){
        ofSetColor(ofColor::sandyBrown);
        timeline.clear();
    }else{
       ofSetColor(ofColor::dimGray);
    }
    ofCircle(circleButton_clear, radius);
    
    //ロードボタン詳細
    if (loadCircleButton){
        ofSetColor(ofColor::sandyBrown);
        timeline.loadTracksFromFolder("project/");//フォルダー指定！！
    }else{
        ofSetColor(ofColor::dimGray);
    }
    ofCircle(circleButton_load, radius);
    
    
    //セーブボタン詳細
    if (saveCircleButton){
        ofSetColor(ofColor::sandyBrown);
        timeline.saveTracksToFolder("project");//なんかフォルダーに保存できる
    }else{
        ofSetColor(ofColor::dimGray);
    }
    ofCircle(circleButton_save, radius);
    
    /*
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
     */
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
    if(timeline.isSwitchOn("No1")){
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
    if(timeline.isSwitchOn("No2")){
        bool byteWasWritten1 = serial.writeByte(5);
        bool byteWasWritten2 = serial.writeByte(num5);
    }else{
        bool byteWasWritten1 = serial.writeByte(5);
        bool byteWasWritten2 = serial.writeByte(0);
    }
    //switch6 &　6番pin
    if(timeline.isSwitchOn("No3")){
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
    if(timeline.isSwitchOn("No4")){
        bool byteWasWritten1 = serial.writeByte(9);
        bool byteWasWritten2 = serial.writeByte(num9);
    }else{
        bool byteWasWritten1 = serial.writeByte(9);
        bool byteWasWritten2 = serial.writeByte(0);
    }
    //switch10 &　10番pin
    if(timeline.isSwitchOn("No5")){
        bool byteWasWritten1 = serial.writeByte(10);
        bool byteWasWritten2 = serial.writeByte(num10);
    }else{
        bool byteWasWritten1 = serial.writeByte(10);
        bool byteWasWritten2 = serial.writeByte(0);
    }
    
    //switch11 &　11番pin
    if(timeline.isSwitchOn("No6")){
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
    }else if(args.track->getName() == "No1"){
        text3 = args.switchName;
        num3 = atoi(text3.c_str());
    }else if(args.track->getName() == "SmartHair 4"){
        text4 = args.switchName;
        num4 = atoi(text4.c_str());
    }else if(args.track->getName() == "No2"){
        text5 = args.switchName;
        num5 = atoi(text5.c_str());
    }else if(args.track->getName() == "No3"){
        text6 = args.switchName;
        num6 = atoi(text6.c_str());
    }else if(args.track->getName() == "SmartHair 7"){
        text7 = args.switchName;
        num7 = atoi(text7.c_str());
    }else if(args.track->getName() == "SmartHair 8"){
        text8 = args.switchName;
        num8 = atoi(text8.c_str());
    }else if(args.track->getName() == "No4"){
        text9 = args.switchName;
        num9 = atoi(text9.c_str());
    }else if(args.track->getName() == "No5"){
        text10 = args.switchName;
        num10 = atoi(text10.c_str());
    }else if(args.track->getName() == "No6"){
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
    if(circle1Button==true){
        xPos1 = x;
        yPos1 = y;
    }
    if(circle2Button==true){
        xPos2 = x;
        yPos2 = y;
    }
    if(circle3Button==true){
        xPos3 = x;
        yPos3 = y;
    }
    if(circle4Button==true){
        xPos4 = x;
        yPos4 = y;
    }
    if(circle5Button==true){
        xPos5 = x;
        yPos5 = y;
    }
    if(circle6Button==true){
        xPos6 = x;
        yPos6 = y;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //円の中心をマウス位置に
    if (circle1.distance(ofPoint(x,y)) < radius3) {
       circle1Button=true;
    }
    if (circle2.distance(ofPoint(x,y)) < radius3) {
        circle2Button=true;
    }
    if (circle3.distance(ofPoint(x,y)) < radius3) {
        circle3Button=true;
    }
    if (circle4.distance(ofPoint(x,y)) < radius3) {
        circle4Button=true;
    }
    if (circle5.distance(ofPoint(x,y)) < radius3) {
        circle5Button=true;
    }
    if(circle6.distance(ofPoint(x,y)) < radius3) {
        circle6Button=true;
    }
    //機能ボタン押されたか
    if (circleButton_loop.distance(ofPoint(x,y)) < radius) {
        loopCircleButton = !loopCircleButton;
    }
    
    if (circleButton_clear.distance(ofPoint(x,y)) < radius) {
        clearCircleButton = !clearCircleButton;
    }
    
    if (circleButton_load.distance(ofPoint(x,y)) < radius) {
        loadCircleButton = !loadCircleButton;
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
    
    //アクチュエーター選択ボタンが押されたか
    if(actuator_powersenter.distance(ofPoint(x,y))< 60){
        if(actuatorpowerButton<2){
            actuatorpowerButton = actuatorpowerButton+1;
        }else{
            actuatorpowerButton = 0;
        }
    }
    if(actuator_speedsenter.distance(ofPoint(x,y))< 60){
        if(actuatorspeedButton<2){
            actuatorspeedButton = actuatorspeedButton+1;
        }else{
            actuatorspeedButton = 0;
        }
    }
    if(actuator_lengthsenter.distance(ofPoint(x,y))< 60){
        if(actuatorlengthButton<2){
            actuatorlengthButton = actuatorlengthButton+1;
        }else{
            actuatorlengthButton = 0;
        }
    }
    if(actuator_colorsenter.distance(ofPoint(x,y))< 60){
        if(actuatorcolorButton<2){
            actuatorcolorButton = actuatorcolorButton+1;
        }else{
            actuatorcolorButton = 0;
        }
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (circle1.distance(ofPoint(x,y)) < radius3) {
        circle1Button=false;
    }
    if (circle2.distance(ofPoint(x,y)) < radius3) {
        circle2Button=false;
    }
    if (circle3.distance(ofPoint(x,y)) < radius3) {
        circle3Button=false;
    }
    if (circle4.distance(ofPoint(x,y)) < radius3) {
        circle4Button=false;
    }
    if (circle5.distance(ofPoint(x,y)) < radius3) {
        circle5Button=false;
    }
    if (circle6.distance(ofPoint(x,y)) < radius3) {
        circle6Button=false;
    }
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
