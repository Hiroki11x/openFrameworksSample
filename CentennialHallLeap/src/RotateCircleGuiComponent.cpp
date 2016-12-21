//
//  RotateCircleGuiComponent.cpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#include "RotateCircleGuiComponent.hpp"

void RotateCircleGuiComponent::setPosition(const float &x,const float &y){
    mPosition = ofVec2f(x,y);
}
void RotateCircleGuiComponent::setPosition(const ofVec2f &pos){
    mPosition = pos;
}

void RotateCircleGuiComponent::init(){
    FontManager::init();
}

void RotateCircleGuiComponent::update(){
    clockDeg += ofRandom(0, 10);
}

void RotateCircleGuiComponent::draw(){
    ofPushMatrix();
    ofPushStyle();

    ofTranslate(mPosition);
    ofSetLineWidth(5);
    ofTranslate(50, 50);

    ofPushMatrix();
    ofSetColor(clockDegColor);
    FontManager::drawGuiString(ofToString(clockDeg), -22, -33);


    ofSetLineWidth(2);
    ofNoFill();
    ofSetColor(clockCircleColor);
    ofDrawCircle(0, 0, 25);
    ofRotateZ(clockDeg);
    ofSetColor(clockLineColor);
    ofSetLineWidth(3);
    ofDrawLine(0, 0, 30, 0);
    ofPopMatrix();

    ofPopMatrix();
    ofPopStyle();
}