//
//  ClockWiseFrameGui.hpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#ifndef ClockWiseFrameGui_hpp
#define ClockWiseFrameGui_hpp
#include "ofMain.h"

class ClockWiseFrameGui{
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
#endif /* ClockWiseFrameGui_hpp */
