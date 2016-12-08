#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    output.setName("Main");
    r=10;
    add=10;
}

//--------------------------------------------------------------
void ofApp::update(){
    if(r==200)add=-10;
    if(r==10)add=10;
    r=r+add;
}

//--------------------------------------------------------------
void ofApp::draw(){
    //丸が大きくなったり、小さくなったりするだけのアニメーション

    ofSetColor(200, 0, 0);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, r);
    //ここで送信している
    output.publishScreen();
}