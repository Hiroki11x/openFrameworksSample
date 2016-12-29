//
//  TriangleAnimation.cpp
//  Animation
//
//  Created by HirokiNaganuma on 12/29/16.
//
//

#include "TriangleAnimation.hpp"

//-------------------------------------------
void TriangleAnimation::reset(){
    setup();
    center_position = ofVec2f(ofRandom(-position_offset,position_offset),ofRandom(-position_offset,position_offset));
}

//-------------------------------------------
void TriangleAnimation::setup(){
    center_position = ofVec2f(0,0);
    duration = 1.f;
}

//-------------------------------------------
void TriangleAnimation::update(){
    endTime =initTime+duration;
    now =ofGetElapsedTimef();
    size=ofxeasing::map_clamp(now,initTime,endTime,0, 200, &ofxeasing::quint::easeOut);
}

//-------------------------------------------
void TriangleAnimation::draw(){
    ofPushMatrix();
    ofTranslate(center_position);
    ofFill();
    ofSetCircleResolution(3);
    ofDrawCircle(0, 0, size);
    ofSetCircleResolution(32);
    ofPopMatrix();
}

//-------------------------------------------
void TriangleAnimation::startAnimation(){
    reset();
    initTime = ofGetElapsedTimef();
}

//-------------------------------------------
void TriangleAnimation::keyPressed(int key){

}