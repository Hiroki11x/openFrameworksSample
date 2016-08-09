//
//  testApp.cpp
//  mySketch
//
//  Created by HirokiNaganuma on 2016/08/09.
//
//

#include "testApp.hpp"


//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);

    int boxSize = 10;
    for(int i=0; i<100;i++) {
        mBox[i].setPosition(ofRandom(-300,300),ofRandom(-300,300),ofRandom(-300,300));
        mBox[i].set(boxSize);
    }
    b_switch = false;
}
//--------------------------------------------------------------
void testApp::update(){
    ofDisableBlendMode();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0,0,0,10);//透明度のある、黒っぽい長方形を描画

    //方法１
    if(b_switch){
        ofDrawBitmapStringHighlight("1 MULTIPLY & ADD", ofGetWidth()-200,30);
        ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);//重なりあった色の暗い部分を強調する
        ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
        ofEnableBlendMode(OF_BLENDMODE_ADD);//色を重ねるほど明るくなる
    }else{
        //方法２
        ofDrawBitmapStringHighlight("2 ALPHA", ofGetWidth()-200,30);
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);//透明の表現を与えるときに使う
        ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    }
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    ofRotateY(ofGetFrameNum());
    ofSetColor(ofColor::fromHsb(225,225,225),175);
    for(int i=0; i<100; i++){
        mBox[i].draw();
    }
}

void testApp::keyPressed(int key){
    if(key == 'a'){
        b_switch = !b_switch;
    }
}