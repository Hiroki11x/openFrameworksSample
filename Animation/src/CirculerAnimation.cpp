//
//  CirculerAnimation.cpp
//  Animation
//
//  Created by HirokiNaganuma on 12/29/16.
//
//

#include "CirculerAnimation.hpp"

//-------------------------------------------
void CirculerAnimation::reset(){
    setup();
    center_position = ofVec2f(ofRandom(-position_offset,position_offset),ofRandom(-position_offset,position_offset));
}

//-------------------------------------------
void CirculerAnimation::setup(){
    center_position = ofVec2f(0,0);
    radius = 100;
    radian = 0;
    duration = 1.f;
    is_appear = true;
}

//-------------------------------------------
void CirculerAnimation::update(){
    radian += 0.2;

    if(radian>PI*2){
        radian = 0;
        is_appear = false;
    }
    endTime =initTime+duration;
    now =ofGetElapsedTimef();
    vertex_angle=ofxeasing::map_clamp(now,initTime,endTime,0, 2*PI, &ofxeasing::quint::easeOut);
}

//-------------------------------------------
void CirculerAnimation::draw(){
    if(!is_appear)return;
    ofPushMatrix();
    ofTranslate(center_position);
    ofNoFill();
    ofBeginShape();
    for(float i = 0; i<vertex_angle; i+=0.01f){
        ofVertex(radius*sin(radian+i), radius*cos(radian+i));
    }
    ofEndShape();
    ofPopMatrix();
}

//-------------------------------------------
void CirculerAnimation::startAnimation(){
    reset();
    initTime = ofGetElapsedTimef();
}

//-------------------------------------------
void CirculerAnimation::keyPressed(int key){

}