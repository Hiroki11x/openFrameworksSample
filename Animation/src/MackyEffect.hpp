//
//  MackyEffect.hpp
//  Animation
//
//  Created by HirokiNaganuma on 12/30/16.
//
//

#ifndef MackyEffect_hpp
#define MackyEffect_hpp

#include "ofMain.h"
#include "BaseAnimation.hpp"

class MackyEffect:public BaseAnimation{
public:
    void reset() override;
    void setup() override;
    void update() override;
    void draw() override;

    void startAnimation() override;
    void keyPressed(int key) override;

    float length;
    float length_max;
    float width;
    bool is_appear;
};

#endif /* MackyEffect_hpp */
