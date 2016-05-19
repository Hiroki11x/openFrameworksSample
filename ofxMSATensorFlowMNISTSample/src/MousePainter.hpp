//
//  MousePainter.hpp
//  ofxMSATensorFlowMNISTSample
//
//  Created by HirokiNaganuma on 2016/03/28.
//
//

#ifndef MousePainter_hpp
#define MousePainter_hpp

#include "ofMain.h"

class MousePainter {
protected:
    ofVec2f last_point;
    ofFbo fbo;
    ofPixels pixels;
public:
    ofColor paint_color = ofColor::white;
    ofColor erase_color = ofColor::black;
    float radius = 7;
    void setup(int size = 256);
    void clear();
    void penDown(ofVec2f p, bool do_erase = false);
    void penDrag(ofVec2f p, bool do_erase = false);
    void penUp();
    void draw();
    const ofPixels& get_pixels();
    int getWidth();
    int getHeight();
};

#endif /* MousePainter_hpp */
