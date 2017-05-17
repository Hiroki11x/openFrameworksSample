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
    chromaGui.setup(chromakey->generalParams, "chromaSettings.xml");
    chromaGui.loadFromFile("chromaSettings.xml");
    chromaGui.setPosition(0, 0);
}

void GuiManager::exit(){
    chromaGui.saveToFile("chromaSettings.xml");
}

void GuiManager::draw(ofxChromaKeyShader *chromakey,int camW, bool bUpdateBgColor){
    if(!bShowGui)return;

    chromaGui.draw();
    // 背景色選択のリファレンス用の四角を表示
    if(bUpdateBgColor) {
        ofPushStyle();
        ofNoFill();
        ofSetLineWidth(3);
        ofSetColor(255);
        ofVec2f bgColorPos = chromakey->bgColorPos.get();
        ofDrawRectangle(bgColorPos.x + camW/2, bgColorPos.y, chromakey->bgColorSize.get(), chromakey->bgColorSize.get());
        ofDrawBitmapString("bgColor", bgColorPos.x + camW/2, bgColorPos.y - 5);
        ofPopStyle();
    }
}

void GuiManager::keyPressed(int key){
    bShowGui = !bShowGui;
}