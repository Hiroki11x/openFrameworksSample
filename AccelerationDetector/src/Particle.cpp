//
//  Particle.cpp
//  mySketch
//
//  Created by HirokiNaganuma on 2016/08/06.
//
//

#include "Particle.hpp"

void Particle::setSpeed(const float x,const float y){
    mSpeed = ofVec2f(x,y);
}

void Particle::setSpeed(const ofVec2f speed){
    mSpeed = speed;
}

void Particle::init(){
    alpha =255;
    startTime = ofGetElapsedTimef();
    radius = ofRandom(10,30);
    entireTime =ofRandom(1,5);
}

void Particle::setPosition(const float x,const float y){
    mPosition = ofVec2f(x,y);
}

void Particle::setPosition(const ofVec2f pos){
    mPosition = pos;
}

void Particle::update(){
    mPosition += mSpeed;
    alpha-=3;
    radius*=1.02;
}

void Particle::draw(){
    ofPushStyle();
    ofSetColor(255, alpha*ofRandom(1));
    ofDrawCircle(mPosition, radius);
    ofPopStyle();
}

void Particle::draw(const ofColor &color){
    ofPushStyle();
    ofSetColor(color, alpha*ofRandom(1));
    ofDrawCircle(mPosition, radius);
    ofPopStyle();
}


bool Particle::isEntire(){
    if(ofGetElapsedTimef() - startTime > entireTime){
        return true;
    }else{
        return false;
    }
}