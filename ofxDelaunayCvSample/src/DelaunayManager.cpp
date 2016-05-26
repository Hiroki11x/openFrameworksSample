//
//  DelaunayManagerr.cpp
//  ofxDelaunayCvSample
//
//  Created by HirokiNaganuma on 2016/05/26.
//
//

#include "DelaunayManager.hpp"


//--------------------------------------------------------------
void DelaunayManager::setup(){
    ofSetWindowShape(1920, 1080);
    mDelaunay.setup();
}

//--------------------------------------------------------------
void DelaunayManager::update(){
    mDelaunay.update();
}

//--------------------------------------------------------------
void DelaunayManager::draw(){
    mDelaunay.draw();
    ofSetWindowTitle("[FPS: "+ofToString(ofGetFrameRate())+"]");
}

//--------------------------------------------------------------
void DelaunayManager::keyPressed(int key){

}

//--------------------------------------------------------------
void DelaunayManager::keyReleased(int key){

}

//--------------------------------------------------------------
void DelaunayManager::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void DelaunayManager::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void DelaunayManager::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void DelaunayManager::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void DelaunayManager::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void DelaunayManager::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void DelaunayManager::windowResized(int w, int h){

}

//--------------------------------------------------------------
void DelaunayManager::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void DelaunayManager::dragEvent(ofDragInfo dragInfo){ 
    
}
