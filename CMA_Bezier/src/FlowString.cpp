//
//  FlowString.cpp
//  Graphics_Sample
//
//  Created by HirokiNaganuma on 2015/08/10.
//
//

#include "FlowString.h"

void FlowString::update(){
    if(pos_x<0||pos_x>ofGetWidth()){
        sp_x*=-1;
    }
    if(pos_y<0||pos_y>ofGetHeight()){
        sp_y*=-1;
    }
    pos_x += sp_x;
    pos_y += sp_y;
}

void FlowString::setSpeed(float speed_x,float speed_y){
    sp_x=speed_x;
    sp_y=speed_y;
}

void FlowString::setPosition(float x,float y){
    pos_x=x;
    pos_y=y;
}

void FlowString::setString(string args){
    text = args;
}
void FlowString::draw(){
    ofSetColor(255);
    ofDrawBitmapString(text,pos_x,pos_y);
    
}