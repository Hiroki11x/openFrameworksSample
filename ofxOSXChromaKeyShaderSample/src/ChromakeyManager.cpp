//
//  ChromakeyManager.cpp
//  ofxOSXChromaKeyShaderSample
//
//  Created by HirokiNaganuma on 5/17/17.
//
//

#include "ChromakeyManager.hpp"

void ChromakeyManager::setup(){

    bk_img.load("black.png");
}


void ChromakeyManager::setup(int camW, int camH){
    this->camH = camH;
    this->camW = camW;
    chromakey = new ofxChromaKeyShader(camW, camH);
    this->setup();
}

void ChromakeyManager::update(){
}

void ChromakeyManager::update(ofImage* img){
    chromakey->updateBgColor(img->getPixels());//Chromakeyに新しいPixelを入れる
    chromakey->updateChromakeyMask(img->getTexture(), bk_img.getTexture());
}

void ChromakeyManager::draw(){
    // draw Cam mask
    chromakey->drawFinalImage(camW/2, 0, camW, camH);
}

void ChromakeyManager::exit(){
    delete this->chromakey;
}

ofxChromaKeyShader* ChromakeyManager::getChromaKey(){
    return this->chromakey;
}