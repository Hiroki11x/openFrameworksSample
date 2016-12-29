//
//  BaseAnimation.hpp
//  Animation
//
//  Created by HirokiNaganuma on 12/29/16.
//
//

#ifndef BaseAnimation_hpp
#define BaseAnimation_hpp

#include "ofMain.h"
#include "ofxEasing.h"

class BaseAnimation{
public:
    virtual void reset(){};
    virtual void setup(){};
    virtual void update(){};
    virtual void draw(){};

    virtual void startAnimation(){};
    virtual void keyPressed(int key){};

    float initTime;
    float endTime;
    float now;
    float duration;
    ofVec2f center_position;
    const float position_offset = 300;
};

#endif /* BaseAnimation_hpp */
