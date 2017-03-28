//
//  CirculerAnimation.hpp
//  Animation
//
//  Created by HirokiNaganuma on 12/29/16.
//
//

#ifndef CirculerAnimation_hpp
#define CirculerAnimation_hpp

#include "ofMain.h"
#include "BaseAnimation.hpp"

class CirculerAnimation :public BaseAnimation{
public:
    void reset() override;
    void setup() override;
    void update() override;
    void draw() override;

    void startAnimation() override;
    void keyPressed(int key) override;

    float radian;
    float vertex_angle;
    float radius;

    bool is_appear;
};

#endif /* CirculerAnimation_hpp */
