#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    _depth =0;
}

//--------------------------------------------------------------
void ofApp::update(){
    _depth = ((int)ofGetElapsedTimef())%10;
}

//--------------------------------------------------------------
void ofApp::draw(){
    DrawKoch(ofVec2f(ofGetWidth()-200,540),ofVec2f(200,540),_depth);
    DrawKoch(ofVec2f(ofGetWidth()/2,0),ofVec2f(ofGetWidth()-200,540),_depth);
    DrawKoch(ofVec2f(200,540),ofVec2f(ofGetWidth()/2,0),_depth);
    
    ofDrawBitmapString("FrameNum"+ofToString(ofGetElapsedTimef()), 30,45);
    ofDrawBitmapString("Depth"+ofToString(_depth), 30,30);
}

//--------------------------------------------------------------
void ofApp::DrawKoch(ofVec2f start,ofVec2f end, int depth){
    if(depth < 10){
        
        ofVec2f mid1 = start + (end-start) / 3.0f;
        ofVec2f mid3 = start + (end-start) / 3.0f * 2;
        
        ofVec2f mid2_temp = (start+end) / 2.0f;
        float dist = ofDist(start.x, start.y, end.x, end.y);
        
        //片方マイナスにしないとおかしくなる
        ofVec2f mid2 = ofVec2f(
                               mid2_temp.x - (end.y - start.y) / 3.0f *(sqrt(3.0)/2),
                               mid2_temp.y + (end.x - start.x) / 3.0f *(sqrt(3.0)/2));
        
        
        depth++;
        
        DrawKoch(start, mid1, depth);
        DrawKoch(mid1, mid2, depth);
        DrawKoch(mid2, mid3, depth);
        DrawKoch(mid3, end, depth);
        
    }else{
        ofDrawLine(start, end);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_UP){
        _depth++;
    }else if(key == OF_KEY_DOWN){
        _depth--;
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
