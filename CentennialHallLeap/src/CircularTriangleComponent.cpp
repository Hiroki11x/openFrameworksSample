//
//  CircularTriangleComponent.cpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#include "CircularTriangleComponent.hpp"

void CircularTriangleComponent::init(){

}

void CircularTriangleComponent::update(){

}

void CircularTriangleComponent::draw(){
    ofPushMatrix();
    ofTranslate(mPosition);
    drawTriangle();
    ofPopMatrix();
}

void CircularTriangleComponent::drawTriangle(){
    ofPushStyle();
    ofSetCircleResolution(3);
    ofSetColor(mColor);
    ofPushMatrix();
    for(int i = 0 ; i < 4  ; i ++){
        ofRotateZ(i*90);
        ofDrawCircle(210, 0, -10);
    }
    ofPopMatrix();
    ofPopStyle();
}

void CircularTriangleComponent::setPosition(const float &x,const float &y){
    setPosition(ofVec2f(x,y));
}

void CircularTriangleComponent::setPosition(const ofVec2f &pos){
    mPosition = pos;
}

void CircularTriangleComponent::setColor(const ofColor &color){
    mColor = color;
}
