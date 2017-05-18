#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(CAM_W*2, CAM_H*1.5f);


    test_imege.load("e.jpg");
   
    mChromakeyManager.setup(CAM_W,CAM_H);
    mDebugModeDrawer.setup(mChromakeyManager.getChromaKey(),CAM_W,CAM_H);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    if(test_imege.isAllocated()){
        mChromakeyManager.update(&test_imege);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofBackground(0);
//    mChromakeyManager.draw();
    mDebugModeDrawer.draw(mChromakeyManager.getChromaKey(), test_imege);
}


//--------------------------------------------------------------
void ofApp::exit() {
    mChromakeyManager.exit();
    mDebugModeDrawer.exit();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    mDebugModeDrawer.keyPressed(key);
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
