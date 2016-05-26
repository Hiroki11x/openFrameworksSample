//
//  ExtendedScene.hpp
//  ofxDelaunayCvSample
//
//  Created by HirokiNaganuma on 2016/05/26.
//
//

#ifndef ExtendedScene_hpp
#define ExtendedScene_hpp

#pragma once

#include "ofMain.h"
#include "ofxDelaunay.h"

class ExtendedScene : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    ofVideoGrabber cam;
    ofxDelaunay delaunay;
    ofVboMesh mesh;

};

#endif /* ExtendedScene_hpp */
