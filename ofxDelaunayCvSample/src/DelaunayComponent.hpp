//
//  DelaunayComponent.hpp
//  ofxDelaunayCvSample
//
//  Created by HirokiNaganuma on 2016/05/26.
//
//

#ifndef DelaunayComponent_hpp
#define DelaunayComponent_hpp

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxDelaunay.h"
//#include "ofxKinect.h"
//#include "ofxPostGlitch.h"
//#include "ofxSyphon.h"

class DelaunayComponent{

public:
    void setup();
    void update();
    void draw();

    ofxCv::FlowPyrLK flow;
    ofxDelaunay delaunay;

    vector<ofVec3f> pts;

    ofFbo fbo;
    ofVideoPlayer video;

    int precision = 2;
};

#endif /* DelaunayComponent_hpp */
