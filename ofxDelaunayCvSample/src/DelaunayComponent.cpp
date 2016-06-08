//
//  DelaunayComponent.cpp
//  ofxDelaunayCvSample
//
//  Created by HirokiNaganuma on 2016/05/26.
//
//

#include "DelaunayComponent.hpp"



//--------------------------------------------------------------
void DelaunayComponent::setup(){
    ofSetFrameRate(60);
    ofBackground(0);

    ofSetWindowShape(1280,720); //ウインドウのサイズ

    //    ofEnableDepthTest();
    //    ofEnableAlphaBlending();

    fbo.allocate(1280,720);

    video.load("silent_release.mov");
    video.play();

    precision =1;
}

//--------------------------------------------------------------
void DelaunayComponent::update(){
    video.update();

    if (ofGetFrameNum() % 60 == 0) flow.resetFeaturesToTrack();
    if (ofGetFrameNum() > 10) {
        if(video.isFrameNew()){
            flow.calcOpticalFlow(video.getPixels());
        }
    }

    pts.clear();
    pts = flow.getFeatures();

    delaunay.reset();
    if (pts.size() > 20) {
        for (int i = 0; i < pts.size(); i+=precision) {
            delaunay.addPoint(ofPoint(pts[i]));
        }
        delaunay.triangulate();
        for (int i = 0; i < pts.size(); i+=precision) {
            if(ofRandom(1)<0.95f){
                delaunay.triangleMesh.addColor(ofFloatColor(.8,1,1,
                                                            (1.0f+ofSignedNoise(pts.size()*10,i, ofGetElapsedTimef()))*.4f
                                                            )
                                               );
            }else{
                delaunay.triangleMesh.addColor(ofFloatColor(.8,1,1,0.9f)
                                               );
            }

        }

    }

    fbo.begin();
    ofClear(0, 0, 0, 255);
    ofFill();
    if(video.isFrameNew())video.draw(0, 0);

    ofNoFill();
    for(auto v: pts){
        ofDrawCircle(v, 4);
    }

    ofFill();
    delaunay.draw();
//
    ofNoFill();
    delaunay.draw();

    fbo.end();
}

//--------------------------------------------------------------
void DelaunayComponent::draw(){
    ofSetColor(255);
    fbo.draw(0, 0,ofGetWidth(),ofGetHeight());
}