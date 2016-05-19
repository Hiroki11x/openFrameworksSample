//
//  ofxGlobe.hpp
//  ofxGlobeSample
//
//  Created by HirokiNaganuma on 2016/03/19.
//
//

#ifndef ofxGlobe_hpp
#define ofxGlobe_hpp

#include "ofMain.h"
#include "ofxCsv.h"
#include "ofxGpuParticles.h"

class ofxGlobe{
private:
    float radius;
    ofVboMesh mMesh;
    ofxGpuParticles particles;
    wng::ofxCsv csv;
    wng::ofxCsv csvRecorder;
public:
    void draw();
    void update();
    void init();
};

#endif /* ofxGlobe_hpp */
