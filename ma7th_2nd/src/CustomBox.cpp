//
//  CustomBox.cpp
//  ma7th_2nd
//
//  Created by HirokiNaganuma on 2016/02/13.
//
//

#include "CustomBox.hpp"

ofVec3f CustomBox::get_position(){
    return box_position;
}

void CustomBox::init(){
    box_position = ofVec3f(ofRandom(-ofGetWidth(),ofGetWidth()),
                           ofRandom(-ofGetWidth(),ofGetWidth()),
                           ofRandom(-ofGetWidth(),ofGetWidth()));
    box_speed = ofVec3f(ofRandom(-1,1),ofRandom(-1,1),ofRandom(-1,1));
    mbox.setPosition(box_position);
    mbox.setResolution(1);
    mbox.set(10);
    mcolor.setHsb(ofRandom(255), 150, 200);
}

void CustomBox::update(){
    box_position += box_speed;
    mbox.setPosition(box_position);
    if(abs(box_position.x) > ofGetWidth()){
        box_speed.x *= -1;
    }
    if(abs(box_position.y) > ofGetWidth()){
        box_speed.y *= -1;
    }
    if(abs(box_position.z) > ofGetWidth()){
        box_speed.z *= -1;
    }
}

void CustomBox::draw(){
    ofSetColor(mcolor);
    mbox.drawWireframe();
}


