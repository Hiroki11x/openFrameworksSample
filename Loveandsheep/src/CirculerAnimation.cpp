//
//  CirculerAnimation.cpp
//  Loveandsheep
//
//  Created by HirokiNaganuma on 12/28/16.
//
//

#include "CirculerAnimation.hpp"

CirculerAnimation::CirculerAnimation(){

}

void CirculerAnimation::init(){
    radius = 100;
    radian = 0;
    vertex_angle = 0;
    line_color_alpha = 200;
    shape_color_alpha = 100;
    line_color.set(ofColor(255,255,255));
    shape_color.set(ofColor(255,255,255));
    position = ofVec2f(0,0);
    vertex_angle_offset = 0;
}

bool CirculerAnimation::update(){
    radian +=0.1;
    vertex_angle += .7f;
    if(radian>PI*3){
        radian=0;
        return true;
    }
    if(vertex_angle>PI*3+vertex_angle_offset){
        vertex_angle=0;
        return true;
    }
    return false;
}

void CirculerAnimation::setPosition(ofVec2f vec){
    this->position = vec;
}

void CirculerAnimation::setRadius(float rad){
    this->radius = rad;
}

void CirculerAnimation::setVertexAngleOffset(float offset){
    this->vertex_angle_offset = offset;
}

void CirculerAnimation::draw(){

}

void CirculerAnimation::drawFill(){
    ofPushMatrix();
    ofTranslate(position);
    ofSetColor(line_color,line_color_alpha);
    ofDrawLine(0, 0, radius*sin(radian), radius*cos(radian));

    ofSetColor(shape_color,shape_color_alpha);
    ofFill();
    ofBeginShape();
    ofVertex(0, 0);
    for(float i = 0; i<vertex_angle; i+=0.01f){
        ofVertex(radius*sin(radian+i), radius*cos(radian+i));
    }
    ofEndShape();
    ofPopMatrix();
}

void CirculerAnimation::drawNoFill(){
    ofPushMatrix();
    ofTranslate(position);
    ofSetColor(shape_color,shape_color_alpha);
    ofNoFill();
    ofBeginShape();
    for(float i = 0; i<vertex_angle; i+=0.01f){
        ofVertex(radius*sin(radian+i), radius*cos(radian+i));
    }
    ofEndShape();
    ofPopMatrix();
}
