//
//  fireworks.cpp
//  fireworks_sample
//
//  Created by HirokiNaganuma on 3/28/17.
//
//

#include "fireworks.hpp"

void Fireworks::draw(){
    ofDrawCircle(pos, radius);
}

void Fireworks::update(){
    pos += speed;
    speed *= 0.99;
}

bool Fireworks::is_expired(){
    if(duration < ofGetElapsedTimef() - starttime){
        return true;
    }
    return false;
}

void Fireworks::setup(float x, float y){
    this->pos = ofVec2f(x,y);
    this->setup();
}

void Fireworks::setup(ofVec2f pos){
    this->pos = pos;
    this->setup();
}

void Fireworks::setup(){
    radius = ofRandom(1,3);
    duration = ofRandom(3,5);
    starttime = ofGetElapsedTimef();
    float phi = ofRandom(2*PI);
    speed = 2*ofVec2f(cos(phi),sin(phi));
}