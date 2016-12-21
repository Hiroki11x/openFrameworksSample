//
//  GridGuiComponent.cpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#include "GridGuiComponent.hpp"

void GridGuiComponent::draw(){
    ofSetLineWidth(1);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(.1, 0x000F);
    ofSetColor(backCrossColor);
    for(int w = 0; w < ofGetWidth(); w+= 60)ofDrawLine(w , 0, w, ofGetHeight());
    for(int h = 0; h < ofGetHeight(); h += 60)ofDrawLine(0, h , ofGetWidth(), h);
    glDisable(GL_LINE_STIPPLE);
}