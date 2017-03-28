//
//  fireworks.hpp
//  fireworks_sample
//
//  Created by HirokiNaganuma on 3/28/17.
//
//

#ifndef fireworks_hpp
#define fireworks_hpp
#include "ofMain.h"

class Fireworks{
private:

public:

    Fireworks(){};

    float radius;
    float starttime;
    float duration;
    ofVec2f pos;
    ofVec2f speed;
    void draw();
    void update();
    bool is_expired();
    void setup();
    void setup(float x, float y);
    void setup(ofVec2f pos);
};

#endif /* fireworks_hpp */
