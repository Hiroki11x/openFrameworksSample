//
//  VJDelaunay.cpp
//  ofxDelaunayCvSample
//
//  Created by HirokiNaganuma on 2016/05/26.
//
//

#include "VJDelaunay.hpp"


//--------------------------------------------------------------
void VJDelaunay::setup(){
    ofSetFrameRate(60);
    ofBackground(0);

    ofSetWindowShape(1920, 1080); //ウインドウのサイズ

    //    ofEnableDepthTest();
    //    ofEnableAlphaBlending();
    bDrawLenna = false;
    bShowHelp  = true;

    fbo.allocate(1920, 1080);
    myGlitch.setup(&fbo);
    lenna.load("a.png");

    video.load("11.mov");
    video.play();
}

//--------------------------------------------------------------
void VJDelaunay::update(){
    video.update();

    if (ofGetFrameNum() % 60 == 0) flow.resetFeaturesToTrack();
    if (ofGetFrameNum() > 10) {
        if(video.isFrameNew()){
            flow.calcOpticalFlow(video.getPixelsRef());
        }

    }

    pts.clear();
    pts = flow.getFeatures();

    delaunay.reset();
    if (pts.size() > 20) {
        for (int i = 0; i < pts.size(); i+=5) {
            delaunay.addPoint(ofPoint(pts[i]));
        }
        delaunay.triangulate();
    }

    fbo.begin();
    ofClear(0, 0, 0, 255);

//    video.draw(0,0);

    if (!bDrawLenna){
        for (int i = 0;i < 100;i++){
            if		(i % 5 == 0)ofSetColor(50 , 255, 100);
            else if (i % 9 == 0)ofSetColor(255, 50, 100);
            else				ofSetColor(255, 255, 255);

        }
    }
    else{
        ofSetColor(255);
        lenna.draw(0, 0);
    }
    if(video.isFrameNew())video.draw(0, 0);

    ofSetColor(255,100);
    delaunay.draw();
    fbo.end();
}

//--------------------------------------------------------------
void VJDelaunay::draw(){
    myGlitch.generateFx();
    ofSetColor(255);
    fbo.draw(0, 0);
}

//--------------------------------------------------------------
void VJDelaunay::keyPressed(int key){
    if (key == '1') myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, true);
    if (key == '2') myGlitch.setFx(OFXPOSTGLITCH_GLOW			, true);
    if (key == '3') myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, true);
    if (key == '4') myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, true);
    if (key == '5') myGlitch.setFx(OFXPOSTGLITCH_TWIST			, true);
    if (key == '6') myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, true);
    if (key == '7') myGlitch.setFx(OFXPOSTGLITCH_NOISE			, true);
    if (key == '8') myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, true);
    if (key == '9') myGlitch.setFx(OFXPOSTGLITCH_SWELL			, true);
    if (key == '0') myGlitch.setFx(OFXPOSTGLITCH_INVERT			, true);

    if (key == 'q') myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
    if (key == 'w') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, true);
    if (key == 'e') myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, true);
    if (key == 'r') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, true);
    if (key == 't') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, true);
    if (key == 'y') myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, true);
    if (key == 'u') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, true);
}

//--------------------------------------------------------------
void VJDelaunay::keyReleased(int key){
    if (key == '1') myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
    if (key == '2') myGlitch.setFx(OFXPOSTGLITCH_GLOW			, false);
    if (key == '3') myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
    if (key == '4') myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
    if (key == '5') myGlitch.setFx(OFXPOSTGLITCH_TWIST			, false);
    if (key == '6') myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, false);
    if (key == '7') myGlitch.setFx(OFXPOSTGLITCH_NOISE			, false);
    if (key == '8') myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
    if (key == '9') myGlitch.setFx(OFXPOSTGLITCH_SWELL			, false);
    if (key == '0') myGlitch.setFx(OFXPOSTGLITCH_INVERT			, false);

    if (key == 'q') myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
    if (key == 'w') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
    if (key == 'e') myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
    if (key == 'r') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
    if (key == 't') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
    if (key == 'y') myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
    if (key == 'u') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);
}

//--------------------------------------------------------------
void VJDelaunay::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void VJDelaunay::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void VJDelaunay::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void VJDelaunay::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void VJDelaunay::windowResized(int w, int h){

}

//--------------------------------------------------------------
void VJDelaunay::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void VJDelaunay::dragEvent(ofDragInfo dragInfo){
    
}
