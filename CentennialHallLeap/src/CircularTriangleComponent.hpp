//
//  CircularTriangleComponent.hpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#ifndef CircularTriangleComponent_hpp
#define CircularTriangleComponent_hpp

#include "ofMain.h"

class CircularTriangleComponent{
private:
    ofVec2f mPosition;
    ofColor mColor;
    void drawTriangle();
public:
    void init();
    void update();
    void draw();
    void setPosition(const float &x,const float &y);
    void setPosition(const ofVec2f &pos);
    void setColor(const ofColor &color);
};

#endif /* CircularTriangleComponent_hpp */
