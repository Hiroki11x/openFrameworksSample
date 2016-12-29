//
//  LinearAnimation.hpp
//  Animation
//
//  Created by HirokiNaganuma on 12/29/16.
//
//

#ifndef LinearAnimation_hpp
#define LinearAnimation_hpp

#include "ofMain.h"
#include "BaseAnimation.hpp"

class LinearAnimation:public BaseAnimation{
public:
    void reset() override;
    void setup() override;
    void update() override;
    void draw() override;

    void startAnimation() override;
    void keyPressed(int key) override;

    float dist_x=-2;
    float dist_y=-2;
    float middle_x;
    float middle_y;
    float multiple;
};

#endif /* LinearAnimation_hpp */
