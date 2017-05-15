#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    ofSetCircleResolution(60);
    center_pos.x = ofGetWidth()/2;
    center_pos.y = ofGetHeight()/2;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    mouse_pos.x = mouseX;
    mouse_pos.y = mouseY;
    
    radius = ofDist(mouse_pos.x,mouse_pos.y, center_pos.x,center_pos.y);
    angle = ofVec2f(1,0).angleRad(center_pos-mouse_pos);
    angle = ofMap(angle,-PI,PI,0,255);
    color.setHsb(angle, 255, 255);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // 方眼紙を書く
    ofSetColor(128);
    ofSetLineWidth(1);
    for(int i = 0 ; i < 30 ; i++){
        ofLine(i*ofGetWidth()/30, 0,i*ofGetWidth()/30, ofGetHeight());
        ofLine(0, i*ofGetWidth()/30,ofGetWidth(), i*ofGetWidth()/30);
    }
    
    // 外側の円を書く
    ofSetColor(color);
    ofSetLineWidth(2);
    ofNoFill();
    ofCircle(center_pos, radius);
    
    // 内側の円を書く
    ofFill();
    ofCircle(center_pos,radius/4);
    
    // マウスと座標系の中心を直線でつなぐ
    ofLine(center_pos, mouse_pos);
    
    // マウスの位置に十字を書く(黒色)
    ofSetColor(0);
    ofLine(mouse_pos.x ,0 ,mouse_pos.x ,ofGetHeight());
    ofLine(0 ,mouse_pos.y ,ofGetWidth() ,mouse_pos.y);
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
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    center_pos.x = ofGetWidth()/2;
    center_pos.y = ofGetHeight()/2;
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
