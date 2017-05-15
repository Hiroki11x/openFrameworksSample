#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    crop_image.load("https://cdn.pixabay.com/photo/2017/03/17/04/07/beautiful-2150881_960_720.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){
    crop_image.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    crop_image.draw(ofGetWidth()/2,ofGetHeight()/2,200);
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
