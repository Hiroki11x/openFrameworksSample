#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(32);
    ofBackground(0,10);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,30);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotate(ofGetFrameNum());

    ofPushMatrix();
    ofSetColor(red);
    ofDrawCircle(250,0,300);
    ofDrawCircle(250,0,10);
    ofDrawBitmapString("RED", 250,-10);

    ofRotate(120);
    ofSetColor(green);
    ofDrawCircle(250,0,300);
    ofDrawCircle(250,0,10);
    ofDrawBitmapString("GREEN", 250,-10);

    ofRotate(120);
    ofSetColor(blue);
    ofDrawCircle(250,0,300);
    ofDrawCircle(250,0,10);
    ofDrawBitmapString("BLUE", 250,-10);
    ofPopMatrix();

    ofPopMatrix();
    ofDrawBitmapStringHighlight("BlendMode: "+ofToString(blend_mode), ofGetWidth()-300,50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '1'){
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
        blend_mode = "OF_BLENDMODE_ALPHA";
    }
    if(key == '2'){
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        blend_mode = "OF_BLENDMODE_ADD";
    }
    if(key == '3'){
        ofEnableBlendMode(OF_BLENDMODE_SCREEN);
        blend_mode = "OF_BLENDMODE_SCREEN";
    }
    if(key == '4'){
        ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
        blend_mode = "OF_BLENDMODE_MULTIPLY";
    }
    if(key == '5'){
        ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
        blend_mode = "OF_BLENDMODE_SUBTRACT";
    }
    if(key == '9'){
        ofSetBackgroundAuto(true);
    }
    if(key == '0'){
        ofSetBackgroundAuto(false);
    }
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
