//
//  MackyEffect.cpp
//  Animation
//
//  Created by HirokiNaganuma on 12/30/16.
//
//

#include "MackyEffect.hpp"

//-------------------------------------------
void MackyEffect::reset(){
    setup();
}

//-------------------------------------------
void MackyEffect::setup(){
    center_position = ofVec2f(0,0);
    duration = 1.f;
    width = 100;
    length_max = 200;
    is_appear = true;
}

//-------------------------------------------
void MackyEffect::update(){
    endTime =initTime+duration;
    now =ofGetElapsedTimef();
    length=ofxeasing::map_clamp(now,initTime,endTime,1,length_max,&ofxeasing::quint::easeOut);
    if(length> length_max-10){
        is_appear = false;
    }
}

//-------------------------------------------
void MackyEffect::draw(){
    if(!is_appear)return;
    ofSetColor(255,100-ofMap(length, 0, length_max, 0, 100));
    ofPushMatrix();
    ofTranslate(center_position);
    ofDrawRectangle(0, 0, width, length);
    ofPopMatrix();
}

//-------------------------------------------
void MackyEffect::startAnimation(){
    reset();
    initTime = ofGetElapsedTimef();
}

//-------------------------------------------
void MackyEffect::keyPressed(int key){

}