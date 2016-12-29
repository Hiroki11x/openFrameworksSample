//
//  CirculerAnimation.hpp
//  Loveandsheep
//
//  Created by HirokiNaganuma on 12/28/16.
//
//

#ifndef CirculerAnimation_hpp
#define CirculerAnimation_hpp

#include "ofMain.h"

class CirculerAnimation{
public:
    CirculerAnimation();
    void init();
    bool update();
    void draw();
    void drawFill();
    void drawNoFill();
    void setPosition(ofVec2f vec);
    void setRadius(float rad);
    void setVertexAngleOffset(float offset);
private:
    float radius;
    float radian;
    float vertex_angle;
    float vertex_angle_offset;
    float line_color_alpha;
    float shape_color_alpha;
    ofColor line_color;
    ofColor shape_color;
    ofVec2f position;
};

#endif /* CirculerAnimation_hpp */
