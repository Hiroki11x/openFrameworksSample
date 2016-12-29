#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    ofSetFrameRate(30);
    for(int i = 0; i< num; i++){
        sleep(ofRandom(1));
        circulerAnimations.push_back(new CirculerAnimation());
        circulerAnimations.back()->init();
    }
    isAutoLoop = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    for(auto circle : circulerAnimations){
        if(circle->update() && isAutoLoop){
            circle->setPosition(ranposgen::generateVec2f(-500, -500, 500, 500));
            circle->setRadius(ofRandom(50,200));
            circle->setVertexAngleOffset(ofRandom(0,2*PI));
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    for(int i = 0; i< num; i++){
        if(i%2==1){
            circulerAnimations.at(i)->drawFill();
        }else{
            circulerAnimations.at(i)->drawNoFill();
        }
    }
    ofPopMatrix();
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
