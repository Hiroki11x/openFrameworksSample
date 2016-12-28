//
//  CenterCircleGuiComponent.hpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#ifndef CenterCircleGuiComponent_hpp
#define CenterCircleGuiComponent_hpp

#include "ofMain.h"
#include "CircularTriangleComponent.hpp"
#include "ClockWiseFrameGui.hpp"
#include "ColorManager.hpp"

class CenterCircleGuiComponent{
private:
    float centerDeg;
    ofVboMesh mVboMesh;
    ofFloatColor mVboMeshColor = ofFloatColor(ColorManager::floatcolor.x,
                                              ColorManager::floatcolor.y,
                                              ColorManager::floatcolor.z,
                                              ColorManager::floatcolor.w);
    ofColor centerCircleColor = ofColor(ColorManager::maincolor.x,
                                        ColorManager::maincolor.y,
                                        ColorManager::maincolor.z,
                                        ColorManager::maincolor.w);
    CircularTriangleComponent mCircularTriangle;
    ClockWiseFrameGui mClockWiseFrame;
public:
    void init();
    void update();
    void draw();
};

#endif /* CenterCircleGuiComponent_hpp */
