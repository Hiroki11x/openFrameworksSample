//
//  CropImage.cpp
//  IMageCropSample
//
//  Created by HirokiNaganuma on 4/27/17.
//
//

#include "CropImage.hpp"

//--------------------------------------------------------------
void CropImage::setup(){
    ofSetCircleResolution(64);
    ratio_x = 1;
    ratio_y = 1;
}

//--------------------------------------------------------------
void CropImage::load(string path){
    img.load(path);
    fbo.allocate(img.getWidth(), img.getHeight(),GL_RGBA);
    rad = min(img.getWidth(), img.getHeight());
    setup();
}

//--------------------------------------------------------------
void CropImage::update(){
    center_x = img.getWidth()/2;
    center_y = img.getHeight()/2;
    fbo.begin();
    {
        ofClear(0,0,0,0);
        ofSetColor(255);
        ofDrawTriangle(center_x+rad*cos(0), center_y+rad*sin(0),
                       center_x+rad*cos(2*PI/3), center_y+rad*sin(2*PI/3),
                       center_x+rad*cos(4*PI/3), center_y+rad*sin(4*PI/3));
    }
    fbo.end();
    img.getTexture().setAlphaMask(fbo.getTexture());
}

//--------------------------------------------------------------
void CropImage::draw(){
    img.draw(-img.getWidth()/2,-img.getHeight()/2,img.getWidth(),img.getHeight());
}

void CropImage::draw(float x, float y, float size){
    float scale = size/rad;
    ofPushMatrix();
    ofTranslate(x, y);
    ofScale(scale,scale);
    img.draw(-img.getWidth()/2,-img.getHeight()/2,img.getWidth(),img.getHeight());
    ofPopMatrix();
}

//--------------------------------------------------------------
void CropImage::draw(float x, float y, float w, float h){
    ratio_x = w/img.getWidth();
    ratio_y = h/img.getHeight();
    ofPushMatrix();
    ofTranslate(x, y);
    ofScale(ratio_x,ratio_y);
    img.draw(-img.getWidth()/2,-img.getHeight()/2,img.getWidth(),img.getHeight());
    ofPopMatrix();
}