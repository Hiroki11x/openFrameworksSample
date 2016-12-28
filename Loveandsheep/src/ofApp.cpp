#include "ofApp.h"

float radius;
float radian;
float vertex_angle;
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(30);
    radius = 100;
    radian = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    radian +=0.1;
    vertex_angle += 0.2;
    if(radian>PI*2){
        radian=0;
    }
    if(vertex_angle>PI*2){
        vertex_angle=0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,200);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    ofDrawLine(0, 0, radius*sin(radian), radius*cos(radian));

    ofSetColor(255,50);


    ofBeginShape();
    ofVertex(0, 0);
    for(float i = 0; i<vertex_angle; i+=0.01f){
        ofVertex(radius*sin(radian+i), radius*cos(radian+i));
    }
    ofEndShape();

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
