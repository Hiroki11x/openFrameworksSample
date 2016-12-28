//
//  nonLeapApp.cpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/9/16.
//
//

#include "nonLeapApp.hpp"

//--------------------------------------------------------------
void nonLeapApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetLogLevel(OF_LOG_VERBOSE);

    cam.setOrientation(ofPoint(0, 0, 0));

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    ImageManager::loadImages();
    FontManager::init();

    pastHand = ofVec3f(0,0,0);
    mSideUIManager.init();
    mSyphonServer.setName("Main");
}

//--------------------------------------------------------------
void nonLeapApp::update(){
    mSideUIManager.update();
}

//--------------------------------------------------------------
void nonLeapApp::draw(){
    ofBackgroundGradient(ofColor(0), ofColor(0),  OF_GRADIENT_BAR);
    ofSetColor(200);

//    cam.begin();
//    ofPushMatrix();
//
//    {
//        float x,y,z,t;
//        t = ofGetElapsedTimef()/10;
//        x = 1000*ofSignedNoise(t, 0, 0);
//        y = 500*ofSignedNoise(0,t,0);
//        z = 300*ofSignedNoise(0, 0, t);
//        pastHand = ofVec3f(x,y,z);
//    }
//    ofVec3f standardPos;
//    standardPos.x = ofMap(pastHand.x,-1000,1000,-10,10);
//    standardPos.y = ofMap(pastHand.y,-500,500,-10,10);
//    standardPos.z = ofMap(pastHand.z,-300,300,1000,138000);
//
//    ofTranslate(0,0,-standardPos.z);
//    cam.setOrientation(ofPoint(standardPos.x, standardPos.y,0));
//
//
//    ImageManager::drawSequenceImages();
//    ofPopMatrix();
//
//    cam.end();
    if(mode == 0){
        mSideUIManager.drawGui();
    }
    mSyphonServer.publishScreen();
}

//--------------------------------------------------------------
void nonLeapApp::keyPressed(int key){
    if(key == ' '){
        mode = (mode +1)%2;
    }
}

//--------------------------------------------------------------
void nonLeapApp::keyReleased(int key){

}

//--------------------------------------------------------------
void nonLeapApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void nonLeapApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void nonLeapApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void nonLeapApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void nonLeapApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void nonLeapApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void nonLeapApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void nonLeapApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void nonLeapApp::dragEvent(ofDragInfo dragInfo){ 
    
}
