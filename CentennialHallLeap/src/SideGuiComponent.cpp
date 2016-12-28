//
//  SideGuiComponent.cpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#include "SideGuiComponent.hpp"


void SideGuiComponent::load(string path){
    mPDF.load(path);
}

void SideGuiComponent::init(){
    mPath.setFilled(false);
    mPath.setStrokeWidth(2.5);
    mPath.setStrokeColor(ofColor(ColorManager::maincolor.x,
                                 ColorManager::maincolor.y,
                                 ColorManager::maincolor.z,
                                 ColorManager::maincolor.w));
    for (int i = 0; i < mPDF.getNumPath(); i++){
        ofPath& path = mPDF.getPathAt(i);
        mPath.append(path);
    }
    mPath.close();
}

void SideGuiComponent::update(){

}

void SideGuiComponent::draw(){
    float scale = ofGetWidth() / mPDF.getWidth();
    ofPushMatrix();

    ofScale(scale, scale);
    mPath.draw();
    ofPopMatrix();
}