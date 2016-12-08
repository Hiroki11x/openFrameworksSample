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

class CenterCircleGuiComponent{
private:
    float centerDeg;
    ofVboMesh mVboMesh;
    ofFloatColor mVboMeshColor = ofFloatColor(1,.2,.47,0.86);
    ofColor centerCircleColor = ofColor(255,50,120,220);
    CircularTriangleComponent mCircularTriangle;
    ClockWiseFrameGui mClockWiseFrame;
public:
    void init();
    void update();
    void draw();
};

#endif /* CenterCircleGuiComponent_hpp */
