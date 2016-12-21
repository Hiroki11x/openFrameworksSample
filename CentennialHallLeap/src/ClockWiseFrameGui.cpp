//
//  ClockWiseFrameGui.cpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#include "ClockWiseFrameGui.hpp"
void ClockWiseFrameGui::init(){

}

void ClockWiseFrameGui::update(){

}

void ClockWiseFrameGui::draw(){
    ofPushMatrix();
    ofTranslate(mPosition);
    drawTriangle();
    ofPopMatrix();
}

void ClockWiseFrameGui::drawTriangle(){
    ofPushStyle();
    ofSetLineWidth(3);
    ofSetColor(mColor);
    ofPushMatrix();
    for(int i = 0 ; i < 180  ; i ++){
        ofRotateZ(2);
        if(i%10 == 0){
            ofDrawLine(290, 0, 315, 0);
        }else{
            ofDrawLine(300, 0, 305, 0);
        }
    }
    ofPopMatrix();
    ofPopStyle();
}

void ClockWiseFrameGui::setPosition(const float &x,const float &y){
    setPosition(ofVec2f(x,y));
}

void ClockWiseFrameGui::setPosition(const ofVec2f &pos){
    mPosition = pos;
}

void ClockWiseFrameGui::setColor(const ofColor &color){
    mColor = color;
}