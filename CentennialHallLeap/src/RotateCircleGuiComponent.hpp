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
#include "ColorManager.hpp"

class RotateCircleGuiComponent{
private:
    float clockDeg;
    ofVec2f mPosition;
    ofColor clockDegColor = ofColor(ColorManager::maincolor.x,
                                    ColorManager::maincolor.y,
                                    ColorManager::maincolor.z,
                                    ColorManager::maincolor.w);
    ofColor clockCircleColor = ofColor(ColorManager::maincolor.x,
                                       ColorManager::maincolor.y,
                                       ColorManager::maincolor.z,
                                       ColorManager::maincolor.w);
    ofColor clockLineColor = ofColor(ColorManager::maincolor.x,
                                     ColorManager::maincolor.y,
                                     ColorManager::maincolor.z,
                                     ColorManager::maincolor.w);
public:
    void setPosition(const float &x,const float &y);
    void setPosition(const ofVec2f &pos);
    void init();
    void update();
    void draw();
};

#endif /* RotateCircleGuiComponent_hpp */
