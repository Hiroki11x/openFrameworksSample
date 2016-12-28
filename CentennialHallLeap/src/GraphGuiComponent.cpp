//
//  GraphGuiComponent.cpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#include "GraphGuiComponent.hpp"

void GraphGuiComponent::init(){
    graphNum = 10;
    for(int i = 0; i < graphNum; i++){
        graphParamatar[i] += ofRandom(0,100);
    }
}

void GraphGuiComponent::update(){
    for(int i = 0; i < graphNum; i++){
        graphParamatar[i] += ofRandom(-10.0, 10.0);
        if(graphParamatar[i] < 0){
            graphParamatar[i] = 0;
        }else if (graphParamatar[i] > 280){
            graphParamatar[i] = 280;
        }
    }
}

void GraphGuiComponent::draw(){
    ofPushMatrix();
    ofTranslate(mPosition);
    ofDisableDepthTest();

    for(int i = 0; i < graphNum; i++){
        ofSetColor(ColorManager::maincolor.x,
                           ColorManager::maincolor.y,
                           ColorManager::maincolor.z,
                           ColorManager::maincolor.w);
        ofFill();
        ofDrawRectangle(10,-92.3 + 20.6 * i, graphParamatar[i], 18);
        ofSetColor(255);
        FontManager::drawSmallString(ofToString(i + 1) + ofToString(graphParamatar[i]),12, -90+14 + 20.6 * i );
    }
    ofPopMatrix();
}

void GraphGuiComponent::setPosition(const ofVec2f &pos){
    mPosition = pos;
}

void GraphGuiComponent::setPosition(const float &x,const float &y){
    setPosition(ofVec2f(x,y));
}

