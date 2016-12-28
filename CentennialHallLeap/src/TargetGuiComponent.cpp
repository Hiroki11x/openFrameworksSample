//
//  TargetGuiComponent.cpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#include "TargetGuiComponent.hpp"

TargetGuiComponent TargetGuiComponent::sharedTargetGuiComponent;

void TargetGuiComponent::init(const float &radius){
    if(modeFrames[0]!=0)return;
    for(int i = 0; i < 3; i++){
        insideDrawer.addVertex(ofVec3f( radius * cos(i * 120 / 180.0 * PI), radius * sin(i * 120 / 180.0 * PI), 0));
        for(float deg = 0; deg < 60; deg += 0.5){
            insideDrawer.addVertex(ofVec3f(radius * cos((float(i * 120) + deg) / 180.0 * PI),
                                           radius * sin((float(i * 120) + deg) / 180.0 * PI), 0));
            insideDrawer.addVertex(ofVec3f(radius * cos((float(i * 120) + deg) / 180.0 * PI),
                                           radius * sin((float(i * 120) + deg) / 180.0 * PI), 0));
        }
        insideDrawer.addVertex(ofVec3f(radius * cos((i * 120 + 60) / 180.0 * PI),
                                       radius * sin((i * 120 + 60) / 180.0 * PI), 0));
    }
    for(int i = 0; i < 3; i++){
        outsideDrawer.addVertex(ofVec3f( radius * SCALE_RATE * cos((i * 120) / 180.0 * PI), radius * SCALE_RATE * sin((i * 120) / 180.0 * PI), 0));
        for(float deg = 0; deg < 90; deg += 0.5){
            outsideDrawer.addVertex(ofVec3f(radius * SCALE_RATE * cos((float(i * 120) + deg) / 180.0 * PI),
                                            radius * SCALE_RATE * sin((float(i * 120) + deg) / 180.0 * PI), 0));
            outsideDrawer.addVertex(ofVec3f(radius * SCALE_RATE * cos((float(i * 120) + deg) / 180.0 * PI),
                                            radius * SCALE_RATE * sin((float(i * 120) + deg) / 180.0 * PI), 0));
        }
        outsideDrawer.addVertex(ofVec3f(radius * SCALE_RATE * cos((i * 120 + 90)/ 180.0 * PI),
                                        radius * SCALE_RATE * sin((i * 120 + 90)/ 180.0 * PI), 0));
    }
    insideDrawer.setMode(OF_PRIMITIVE_LINES);
    outsideDrawer.setMode(OF_PRIMITIVE_LINES);
    position = ofVec2f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    for(int i = 0; i < 5; i++){
        modeFrames[i] = ofRandom(8, 5 + 30 * ((i + 1) % 2));
    }
}

void TargetGuiComponent::update(){
    switch (mode) {
        case ROTATE:
            insideDeg += insideSpeed;
            outsideDeg += outsideSpeed;
            break;
        case ROTATE_REVERSE:
            insideDeg -= insideSpeed;
            outsideDeg -= outsideSpeed;
            break;
        default:
            break;
    }

    frameCount++;
    if(frameCount > modeFrames[int(mode)]){
        if((int)mode + 1 == 5){
            restart();
            return;
        }
        mode = Mode((int)mode + 1);
        frameCount = 0;
    }
}

void TargetGuiComponent::restart(){
    mode = ROTATE;
    frameCount = 0;
    float insideDeg = 0;
    float outsideDeg = 0;
    position = ofVec2f(ofRandom(100,ofGetWidth() -100),ofRandom(90,ofGetHeight() - 90));
    for(int i = 0; i < 5; i++){
        modeFrames[i] = ofRandom(8, 5 + 30 * ((i + 1) % 2));
    }
}

void TargetGuiComponent::draw(){
    if(mode == END) return;

    ofPushStyle();

    ofPushMatrix();
    ofTranslate(position);
    ofSetColor(ofColor(ColorManager::maincolor.x,
                       ColorManager::maincolor.y,
                       ColorManager::maincolor.z,
                       ColorManager::maincolor.w), 180);
    ofSetLineWidth(8);
    ofRotateZ(insideDeg);
    insideDrawer.draw();
    ofPopMatrix();

    ofPushMatrix();
    ofTranslate(position);
    ofRotateZ(outsideDeg);
    ofSetLineWidth(16);
    ofSetColor(ofColor(ColorManager::maincolor.x,
                       ColorManager::maincolor.y,
                       ColorManager::maincolor.z,
                       ColorManager::maincolor.w),150);
    outsideDrawer.draw();
    ofPopMatrix();

    ofSetLineWidth(2);
    ofSetColor(ColorManager::maincolor.x,
               ColorManager::maincolor.y,
               ColorManager::maincolor.z,
               ColorManager::maincolor.w);
    ofDrawLine(0, position.y, ofGetWidth(), position.y);
    ofDrawLine(position.x, 0, position.x, ofGetHeight());

    ofPopStyle();
}