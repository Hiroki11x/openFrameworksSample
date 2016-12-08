#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    for(int i = 0 ;i < 10 ; i++){
        custombox.push_back(CustomBox());
        custombox.back().init();
    }
}
//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0 ;i < custombox.size() ; i++){
        custombox.at(i).update();
    }
    ofVec3f cam_pos = ofVec3f(sin(ofGetElapsedTimef()),
                              0,
                              cos(ofGetElapsedTimef()));
    cam_pos*= 2000;
    mcam.setPosition(cam_pos+custombox.back().get_position()*3);
    mcam.lookAt(ofVec3f(0,0,0));
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    mcam.begin();
    for(int i = 0 ;i < custombox.size() ;i++){
        custombox[i].draw();
        
        if(i!=0){// Box同士を線で繋ぐ
            ofLine(custombox.at(i-1).get_position(),custombox.at(i).get_position());
        }
    }
    mcam.end();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofSetBackgroundAuto(false);//falseにすると上塗り
    if(key == OF_KEY_RETURN){
        custombox.push_back(CustomBox());//動的配列(vector)の末尾に新しく要素を追加
        custombox.back().init();
    }else if(key ==' ' && custombox.size()>0){
        custombox.pop_back();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    ofSetBackgroundAuto(true);
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
