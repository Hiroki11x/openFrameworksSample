//
//  snow.cpp
//  snow_sample
//
//  Created by HirokiNaganuma on 3/28/17.
//
//

#include "snow.hpp"

void Snow::draw(){
    ofDrawCircle(pos, radius);
}

void Snow::update(){
    pos += speed;
}

bool Snow::is_expired(){
    if(duration < ofGetElapsedTimef() - starttime){
        return true;
    }
    return false;
}

void Snow::setup(float x, float y){
    this->pos = ofVec2f(x,y);
    this->setup();
}

void Snow::setup(ofVec2f pos){
    this->pos = pos;
    this->setup();
}

void Snow::setup(){
    radius = ofRandom(3,5);
    duration = ofRandom(3,5);
    starttime = ofGetElapsedTimef();
    speed = ofVec2f(ofRandom(-1,1), ofRandom(5,10));
}