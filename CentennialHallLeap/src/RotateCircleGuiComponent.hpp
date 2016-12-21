//
//  RotateCircleGuiComponent.hpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#ifndef RotateCircleGuiComponent_hpp
#define RotateCircleGuiComponent_hpp


#include "ofMain.h"
#include "FontManager.hpp"

class RotateCircleGuiComponent{
private:
    float clockDeg;
    ofVec2f mPosition;
    ofColor clockDegColor = ofColor(255,50,120,220);
    ofColor clockCircleColor = ofColor(255,50,120,220);
    ofColor clockLineColor = ofColor(255,50,120,220);
public:
    void setPosition(const float &x,const float &y);
    void setPosition(const ofVec2f &pos);
    void init();
    void update();
    void draw();
};

#endif /* RotateCircleGuiComponent_hpp */
