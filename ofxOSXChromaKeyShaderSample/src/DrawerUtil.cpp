//
//  DrawerUtil.cpp
//  ofxOSXChromaKeyShaderSample
//
//  Created by HirokiNaganuma on 5/15/17.
//
//

#include "DrawerUtil.hpp"

ofFbo DrawerUtil::checkerboardTex;

//--------------------------------------------------------------
void DrawerUtil::setupCheckerboard(int width, int height, int size){
    if (!checkerboardTex.isAllocated()) {
        checkerboardTex.allocate(width, height);
        ofPushStyle();
        checkerboardTex.begin();
        ofClear(255, 255, 255, 255);
        int numWidth = width/size;
        int numHeight = height/size;
        for(int h=0; h<numHeight; h++) {
            for(int w=0; w<numWidth; w++) {
                if ((h+w)%2 == 0) {
                    ofSetColor(ofColor::black);
                    ofDrawRectangle(w*size, h*size, size, size);
                }
            }
        }
        checkerboardTex.end();
        ofPopStyle();
    }
}

//--------------------------------------------------------------
void DrawerUtil::drawDebugMasks(int camW, int camH, ofxChromaKeyShader *chromakey,  ofImage img) {
    ofSetColor(255);
    int previewW = camW/2, previewH = camH/2, labelOffset = 10;

    chromakey->drawBaseMask(camW + previewW, 0, previewW, previewH);
    ofDrawBitmapStringHighlight("Base mask", camW + previewW, labelOffset, ofColor(0, 125), ofColor::green);

    chromakey->drawDetailMask(camW + previewW, previewH, previewW, previewH);
    ofDrawBitmapStringHighlight("Detailed mask", camW + previewW, previewH + labelOffset, ofColor(0, 125), ofColor::green);

    chromakey->drawChromaMask(previewW, camH, previewW, previewH);
    ofDrawBitmapStringHighlight("Chroma mask", previewW, camH + labelOffset, ofColor(0, 125), ofColor::green
                                );

    drawCheckerboard(camW, camH, previewW, previewH, 5);
    chromakey->drawFinalMask(camW, camH, previewW, previewH);
    ofDrawBitmapStringHighlight("Final mask", camW, camH + labelOffset, ofColor(0, 125), ofColor::green);

    img.draw(camW + previewW, camH, previewW, previewH);
    ofDrawBitmapStringHighlight("RGB image", camW + previewW, camH + labelOffset, ofColor(0, 125), ofColor::green);
}

//--------------------------------------------------------------
void DrawerUtil::drawCheckerboard(float x, float y, int width, int height, int size) {
    ofSetColor(255, 255);
    checkerboardTex.draw(x, y);
}