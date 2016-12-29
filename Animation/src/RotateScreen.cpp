//
//  RotateScreen.cpp
//  Animation
//
//  Created by HirokiNaganuma on 12/29/16.
//
//

#include "RotateScreen.hpp"

//-------------------------------------------
void RotateScreen::reset(){
    angle = 0;
}

//-------------------------------------------
void RotateScreen::setup(){
    center_position = ofVec2f(ofRandom(-position_offset,position_offset),ofRandom(-position_offset,position_offset));
    duration = .8f;
    rect_w = 2000;
    rect_h = 2000;
    angle = 0;
    angle_offset = ofRandom(180);
}

//-------------------------------------------
void RotateScreen::update(){
    endTime =initTime+duration;
    now =ofGetElapsedTimef();
    angle=ofxeasing::map_clamp(now,initTime,endTime,0,200,&ofxeasing::bounce::easeOut);
}

//-------------------------------------------
void RotateScreen::draw(){
    ofFill();
    ofPushMatrix();
    ofTranslate(center_position);
    ofRotateZ(angle+angle_offset);
    ofTranslate(rect_w/2, rect_w/2);
    ofRotateZ(45);
    ofTranslate(-(sqrt(2)-1)/2*rect_h,0);
    ofDrawRectangle(-rect_w/2,-rect_h/2,rect_w,rect_h);
    ofPopMatrix();
}

//-------------------------------------------
void RotateScreen::startAnimation(){
    reset();
    this->initTime = ofGetElapsedTimef();
}

//-------------------------------------------
void RotateScreen::keyPressed(int key){

}