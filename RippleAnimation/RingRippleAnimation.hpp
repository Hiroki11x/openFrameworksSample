//
//  RingRippleAnimation.hpp
//  ofxVJComponent
//
//  Created by HirokiNaganuma on 2016/04/04.
//
//

#ifndef RingRippleAnimation_hpp
#define RingRippleAnimation_hpp

#include "ofMain.h"

class RingRippleAnimation{
private:
    float alpha;
    ofVec2f mPosition;
    ofVec2f mSpeed;
    float radius;
    float startTime;
    float entireTime;
public:
    void init();
    void setPosition(float x, float y);
    void setPosition(ofVec2f pos);
    void setSpeed(float x, float y);
    void setSpeed(ofVec2f speed);
    void update();
    void draw();
    bool isEntire();
};

#endif /* RingRippleAnimation_hpp */
