//
//  GraphGuiComponent.hpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#ifndef GraphGuiComponent_hpp
#define GraphGuiComponent_hpp

#include "ofMain.h"
#include "FontManager.hpp"
#include "ColorManager.hpp"

class GraphGuiComponent{

private:
    ofColor graphBackColor = ofColor(ColorManager::maincolor.x,
                                     ColorManager::maincolor.y,
                                     ColorManager::maincolor.z,
                                     ColorManager::maincolor.w);

    int graphNum;
    float graphParamatar[10];

    ofShader graphBack;
    ofVec2f mPosition;
    ofxTrueTypeFontUL2 mSmallTrueTypeFontUL2;

public:
    void init();
    void draw();
    void update();
    void setPosition(const ofVec2f &pos);
    void setPosition(const float &x,const float &y);
};

#endif /* GraphGuiComponent_hpp */
