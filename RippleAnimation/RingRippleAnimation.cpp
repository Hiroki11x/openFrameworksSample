//
//  RingRippleAnimation.cpp
//  ofxVJComponent
//
//  Created by HirokiNaganuma on 2016/04/04.
//
//

#include "RingRippleAnimation.hpp"


void RingRippleAnimation::setSpeed(float x, float y){
    mSpeed = ofVec2f(x,y);
    alpha =255;
}

void RingRippleAnimation::setSpeed(ofVec2f speed){
    mSpeed = speed;
}

void RingRippleAnimation::init(){
    startTime = ofGetElapsedTimef();
    radius = ofRandom(3,15);
    entireTime =ofRandom(1,5);
}

void RingRippleAnimation::setPosition(float x, float y){
    mPosition = ofVec2f(x,y);
}

void RingRippleAnimation::setPosition(ofVec2f pos){
    mPosition = pos;
}

void RingRippleAnimation::update(){
    mPosition += mSpeed;
    alpha-=1.5;
    radius*=1.01;
}

void RingRippleAnimation::draw(){
    ofPushStyle();
    ofNoFill();
    ofSetLineWidth(1);
    ofSetColor(ofRandom(250),ofRandom(250),ofRandom(250), alpha*ofRandom(.7,1));
    ofDrawCircle(mPosition, radius);
    ofPopStyle();
}

bool RingRippleAnimation::isEntire(){
    if(ofGetElapsedTimef() - startTime > entireTime){
        return true;
    }else{
        return false;
    }
}