//
//  DebugModeDrawer.cpp
//  ofxOSXChromaKeyShaderSample
//
//  Created by HirokiNaganuma on 5/17/17.
//
//

#include "DebugModeDrawer.hpp"

void DebugModeDrawer::setup(ofxChromaKeyShader* chromakey, int camW, int camH){
    this->camW = camW;
    this->camH = camH;
    //GUI
    mGuiManager.setup(chromakey,camW);
}

void DebugModeDrawer::draw(ofxChromaKeyShader* chromakey, ofImage img){
    // draw Cam mask
    chromakey->drawFinalImage(camW/2, 0, camW, camH);
    DrawerUtil::drawDebugMasks(camW, camH, chromakey, img);

    // GUI
    mGuiManager.draw(chromakey,camW);

}

void DebugModeDrawer::exit(){
    mGuiManager.exit();
}

void DebugModeDrawer::keyPressed(int key){
    mGuiManager.keyPressed(key);
}