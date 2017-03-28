//
//  snow.hpp
//  snow_sample
//
//  Created by HirokiNaganuma on 3/28/17.
//
//

#ifndef snow_hpp
#define snow_hpp

#include "ofMain.h"

class Snow{
private:

public:

    Snow(){};

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

#endif /* snow_hpp */
