//
//  LinearAnimation.cpp
//  Animation
//
//  Created by HirokiNaganuma on 12/29/16.
//
//

#include "LinearAnimation.hpp"

//-------------------------------------------
void LinearAnimation::reset(){
    setup();
    center_position = ofVec2f(ofRandom(-position_offset,position_offset),ofRandom(-position_offset,position_offset));
}

//-------------------------------------------
void LinearAnimation::setup(){
    center_position = ofVec2f(0,0);
    duration = 1.f;
    dist_x =1;
    dist_y =1;
}

//-------------------------------------------
void LinearAnimation::update(){
    endTime =initTime+duration;
    now =ofGetElapsedTimef();
    multiple=ofxeasing::map_clamp(now,initTime,endTime,1,200,&ofxeasing::quint::easeOut);
    dist_x=multiple*dist_x/30;
    dist_y=multiple*dist_y/30;
}

//-------------------------------------------
void LinearAnimation::draw(){
    ofPushMatrix();
    ofTranslate(center_position);
    ofDrawLine(middle_x-dist_x,middle_x-dist_y,middle_x+dist_x,middle_y+dist_y);
    ofPopMatrix();
}

//-------------------------------------------
void LinearAnimation::startAnimation(){
    reset();
    initTime = ofGetElapsedTimef();
}

//-------------------------------------------
void LinearAnimation::keyPressed(int key){

}