//
//  PinHoleManager.cpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#include "PinHoleManager.hpp"

void PinHoleManager::drawCustomView(ofImage &img, string discription){
    ofPushMatrix();
    ofTranslate(-size/2,-size/2);
    ofSetColor(255);
    FontManager::drawString(discription, 0, size);
    ofSetColor(0);
    ofDrawRectangle(0, 0, size, size/6);
    ofSetColor(255);
    img.draw(0,0,size,size);
    ofPopMatrix();
}