//
//  SideUIManager.cpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#include "SideUIManager.hpp"

void SideUIManager::init(){
    initCenterCircle();

    mGraphGui.init();
    mGraphGui.setPosition(20, ofGetHeight() - 220);
    TargetGuiComponent::sharedTargetGuiComponent.init(50);
    mCenterCircleGui.init();
    for(int i = 0;i<3;i++){
        mRotateCircleGui[i].init();
        mRotateCircleGui[i].setPosition(ofGetWidth() - 320+100*i, 40);
    }

    mSideGui.load("pdf/uigui.pdf");
    mSideGui.init();
}

void SideUIManager::update(){
    mGraphGui.update();
    TargetGuiComponent::sharedTargetGuiComponent.update();
    mCenterCircleGui.update();
    for(int i = 0;i<3;i++)mRotateCircleGui[i].update();
}

void SideUIManager::drawGui(){

    for(int i = 0;i<3;i++)mRotateCircleGui[i].draw();
    TargetGuiComponent::sharedTargetGuiComponent.draw();
    mGridGui.draw();
    mCenterCircleGui.draw();
    mGraphGui.draw();
    mSideGui.draw();
}

void SideUIManager::initCenterCircle(){
    mCenterCircleGui.init();
}