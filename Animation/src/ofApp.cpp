#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);

    baseAnimations.push_back(new LinearAnimation());
    baseAnimations.push_back(new TriangleAnimation());
    baseAnimations.push_back(new RotateScreen());
    baseAnimations.push_back(new RotateScreen());
    baseAnimations.push_back(new CirculerAnimation());

    for(BaseAnimation* anim : baseAnimations){
        anim->setup();
    }

    player.load("FLASH.mp4");
    player.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    player.update();
    for(BaseAnimation* anim : baseAnimations){
        anim->update();
    }
    if(baseAnimations.size()>ANIM_MAX){
        cout << "baseAnimations.size()" << baseAnimations.size() <<endl;
        baseAnimations.erase(baseAnimations.begin()+0);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255);
    player.draw(0, 0, ofGetWidth(),ofGetHeight());

    ofSetColor(255,50);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    for(BaseAnimation* anim : baseAnimations){
        anim->draw();
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for(BaseAnimation* anim : baseAnimations){
        anim->keyPressed(key);
    }
    if(key == ' '){
        for(BaseAnimation* anim : baseAnimations){
            anim->startAnimation();
        }
    }
    if('1' <= key  && key <= '9'){
        int index = key - '0';
        cout << "key - '0'" << index << endl;
        if(key - '0' < baseAnimations.size()){
            baseAnimations.at(index-1)->startAnimation();
        }
    }
    if(key == 'r'){
        baseAnimations.push_back(new RotateScreen());
        baseAnimations.back()->setup();
    }
    if(key == 'l'){
        baseAnimations.push_back(new LinearAnimation());
        baseAnimations.back()->setup();
    }
    if(key == 'c'){
        baseAnimations.push_back(new CirculerAnimation());
        baseAnimations.back()->setup();
    }
    if(key == 't'){
        baseAnimations.push_back(new TriangleAnimation());
        baseAnimations.back()->setup();
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

