//
//  RotateScreen.hpp
//  Animation
//
//  Created by HirokiNaganuma on 12/29/16.
//
//

#ifndef RotateScreen_hpp
#define RotateScreen_hpp

#include "ofMain.h"
#include "BaseAnimation.hpp"

class RotateScreen :public BaseAnimation{
public:

    void reset() override;
    void setup() override;
    void update() override;
    void draw() override;

    void startAnimation() override;
    void keyPressed(int key) override;

    float rect_w;
    float rect_h;
    float angle;
};

#endif /* RotateScreen_hpp */
