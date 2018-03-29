//
//  RippleDrawer.cpp
//  ofxVJComponent
//
//  Created by HirokiNaganuma on 2016/04/04.
//
//

#include "RippleDrawer.hpp"


void RippleDrawer::init(){
    rings.push_back(new RingRippleAnimation());
    rings.back()->init();
    
    //座標とか、スピードとかは適当
    rings.back()->setPosition(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    rings.back()->setSpeed(ofRandom(-2,2),ofRandom(-2,2));
}

void RippleDrawer::init(ofVec2f pos, ofVec2f speed){
    rings.push_back(new RingRippleAnimation());
    rings.back()->init();
    rings.back()->setPosition(pos);
    rings.back()->setSpeed(speed);
}

void RippleDrawer::update(){
    if(int(ofGetElapsedTimef())%3== 0){
        for(int i =0;i<10;i++){
            init();
        }
    }
    for(int i = 0; i<rings.size();i++){
        rings.at(i)->update();
        if(rings.at(i)->isEntire()){
            rings.erase(rings.begin() + i);
        }
    }
}

void RippleDrawer::draw(){
    ofDrawBitmapStringHighlight("rings.size()"+ofToString(rings.size()), 20,20);
    for(int i = 0; i<rings.size();i++){
        rings.at(i)->draw();
    }
}

void RippleDrawer::keyPressed(int key){
    // reset
    if(key == 'r'){
        for(int i =0;i<10;i++){
            init();
        }
    }
}