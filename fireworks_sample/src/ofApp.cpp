#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i<fireworks.size();i++){
        fireworks.at(i).update();
        if(fireworks.at(i).is_expired()){
            fireworks.erase(fireworks.begin()+i);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0,20);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(255);
    for(auto firework : fireworks){
        firework.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for(int i = 0; i< 30; i++){
        fireworks.push_back(Fireworks());
        fireworks.back().setup(mouseX, mouseY);
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
//    fireworks.push_back(Snow());
//    fireworks.back().setup(x, y);
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
