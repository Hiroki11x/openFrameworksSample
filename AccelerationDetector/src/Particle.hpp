//
//  Particles.hpp
//  mySketch
//
//  Created by HirokiNaganuma on 2016/08/06.
//
//

#ifndef Particle_hpp
#define Particle_hpp

#include "ofMain.h"

class Particle{
private:
    int alpha;
    ofVec2f mPosition;
    ofVec2f mSpeed;
    float radius;
    float startTime;
    float entireTime;
public:
    void init();
    void setPosition(const float x, const float y);
    void setPosition(const ofVec2f pos);
    void setSpeed(const float x,const float y);
    void setSpeed(const ofVec2f speed);
    void update();
    void draw();
    void draw(const ofColor &color);
    bool isEntire();
};
#endif /* Particle_hpp */
