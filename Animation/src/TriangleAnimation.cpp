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
    angle_offset = ofRandom(180);
    size = ofRandom(200);
}

//-------------------------------------------
void TriangleAnimation::update(){
    endTime =initTime+duration;
    now =ofGetElapsedTimef();
    size_ratio=ofxeasing::map_clamp(now,initTime,endTime,0, 1, &ofxeasing::quint::easeOut);
}

//-------------------------------------------
void TriangleAnimation::draw(){
    ofPushMatrix();
    ofTranslate(center_position);
    ofRotateZ(angle_offset);
    ofFill();
    ofSetCircleResolution(3);
    ofDrawCircle(0, 0, size*size_ratio);
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