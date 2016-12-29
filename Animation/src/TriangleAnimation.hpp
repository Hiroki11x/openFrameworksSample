//
//  TriangleAnimation.hpp
//  Animation
//
//  Created by HirokiNaganuma on 12/29/16.
//
//

#ifndef TriangleAnimation_hpp
#define TriangleAnimation_hpp

#include "ofMain.h"
#include "BaseAnimation.hpp"

class TriangleAnimation :public BaseAnimation{
public:
    void reset() override;
    void setup() override;
    void update() override;
    void draw() override;

    void startAnimation() override;
    void keyPressed(int key) override;

    float size;
};

#endif /* TriangleAnimation_hpp */
