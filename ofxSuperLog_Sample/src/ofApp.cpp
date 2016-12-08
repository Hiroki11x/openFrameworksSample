#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    bool logToConsole = true;
    bool logToScreen = true;
    ofSetLoggerChannel(ofxSuperLog::getLogger(logToConsole, logToScreen, "logs"));//consoleに行くはずのログをScreenに
    ofxSuperLog::getLogger()->setMaximized(true);//画面上に表示
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    ofLogNotice() << "Mouse dragged: " << x << ", " << y;//マウスを動かすとログが出る
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
