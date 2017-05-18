//
//  GuiManager.cpp
//  ofxOSXChromaKeyShaderSample
//
//  Created by HirokiNaganuma on 5/17/17.
//
//

#include "GuiManager.hpp"

void GuiManager::setup(ofxChromaKeyShader *chromakey,int camW){
    bShowGui = true;

    // GUI
    chromaGui.setDefaultHeight(18);
    chromaGui.setDefaultWidth(camW/2);
    chromaGui.setFillColor(ofColor::black);
    chromaGui.setTextColor(ofColor::white);
    chromaGui.setBackgroundColor(ofColor::black);
    chromaGui.setHeaderBackgroundColor(ofColor::fromHex(0x000066));
    chromaGui.setBorderColor(ofColor::fromHex(0x000044));
    chromaGui.setDefaultBackgroundColor(ofColor::black);
    chromaGui.setDefaultFillColor(ofColor::fromHex(0x000066));
    chromaGui.setDefaultTextColor(ofColor::white);
    chromaGui.setDefaultHeaderBackgroundColor(ofColor::fromHex(0x000022));
    chromaGui.setDefaultBorderColor(ofColor::fromHex(0x000044));
    chromaGui.setDefaultWidth(300);
    chromaGui.setup(chromakey->generalParams, "chromaSettings.xml");
    chromaGui.add(chromakey->positionParams);
    chromaGui.loadFromFile("chromaSettings.xml");
    chromaGui.setPosition(0, 0);
}

void GuiManager::exit(){
    chromaGui.saveToFile("chromaSettings.xml");
}

void GuiManager::draw(ofxChromaKeyShader *chromakey,int camW){
    if(!bShowGui)return;
    
    chromaGui.draw();
    // 背景色選択のリファレンス用の四角を表示

    ofPushStyle();
    ofNoFill();
    ofSetLineWidth(3);
    ofSetColor(255);
    ofVec2f bgColorPos = chromakey->bgColorPos.get();
    ofDrawRectangle(bgColorPos.x + camW/2, bgColorPos.y, chromakey->bgColorSize.get(), chromakey->bgColorSize.get());
    ofDrawBitmapString("bgColor", bgColorPos.x + camW/2, bgColorPos.y - 5);
    ofPopStyle();
}

void GuiManager::keyPressed(int key){
    bShowGui = !bShowGui;
}