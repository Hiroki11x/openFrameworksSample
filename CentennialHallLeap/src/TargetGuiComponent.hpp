//
//  TargetGuiComponent.hpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#ifndef TargetGuiComponent_hpp
#define TargetGuiComponent_hpp

#include "ofMain.h"
#include "ColorManager.hpp"

#define SCALE_RATE 1.4

class TargetGuiComponent{
public:
    enum Mode{
        ROTATE,
        STOP,
        ROTATE_REVERSE,
        STOP2,
        END
    };

    static TargetGuiComponent sharedTargetGuiComponent;

    int frameCount;
    int modeFrames[5];
    float insideSpeed = 5.0;
    float outsideSpeed = -3.0;
    float insideDeg;
    float outsideDeg;
    ofColor targetColor = ofColor(ColorManager::maincolor.x,
                                  ColorManager::maincolor.y,
                                  ColorManager::maincolor.z,
                                  ColorManager::maincolor.w);
    ofVboMesh insideDrawer;
    ofVboMesh outsideDrawer;
    ofVec2f position;
    Mode mode = ROTATE;

    void init(const float &radius);
    void update();
    void draw();
    void restart();
};

#endif /* TargetGuiComponent_hpp */
