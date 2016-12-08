//
//  CenterCircleGuiComponent.cpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#include "CenterCircleGuiComponent.hpp"

void CenterCircleGuiComponent::init(){
    float radius = 260;
    mVboMesh.clear();
    mVboMesh.setMode(OF_PRIMITIVE_LINES);
    for(int i = 0; i < 3; i++){
        mVboMesh.addVertex(ofVec3f( radius * cos(i * 120 / 180.0 * PI),
                                   radius * sin(i * 120 / 180.0 * PI),
                                   0));
        mVboMesh.addColor(mVboMeshColor);
        for(float deg = 0; deg < 60; deg += 0.5){
            mVboMesh.addVertex(ofVec3f(radius * cos((float(i * 120) + deg) / 180.0 * PI),
                                       radius * sin((float(i * 120) + deg) / 180.0 * PI),
                                       0));
            mVboMesh.addColor(mVboMeshColor);
            mVboMesh.addVertex(ofVec3f(radius * cos((float(i * 120) + deg) / 180.0 * PI),
                                       radius * sin((float(i * 120) + deg) / 180.0 * PI),
                                       0));
            mVboMesh.addColor(mVboMeshColor);
        }
        mVboMesh.addVertex(ofVec3f(radius * cos((i * 120 + 60) / 180.0 * PI),
                                   radius * sin((i * 120 + 60) / 180.0 * PI),
                                   0));
        mVboMesh.addColor(mVboMeshColor);
    }
    mCircularTriangle.setPosition(0, 0);
    mCircularTriangle.setColor(centerCircleColor);
    mClockWiseFrame.setPosition(0, 0);
    mClockWiseFrame.setColor(centerCircleColor);
}

void CenterCircleGuiComponent::update(){
    centerDeg += 0.2;
}

void CenterCircleGuiComponent::draw(){
    ofPushStyle();
    ofPushMatrix();

    ofSetCircleResolution(30);
    ofNoFill();
    ofSetColor(centerCircleColor);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetLineWidth(8);

    //四つの線
    ofDrawLine(-290,0,-315,0);
    ofDrawLine(290,0,315,0);
    ofDrawLine(0,290,0,315);
    ofDrawLine(0,-290,0,-315);

    ofRotateZ(centerDeg);

    mCircularTriangle.draw();
    mClockWiseFrame.draw();

    ofRotateZ(-2*centerDeg);
    mVboMesh.draw();
    ofScale(1.35,1.35);
    mVboMesh.draw();

    ofPopMatrix();
    ofPopStyle();
}