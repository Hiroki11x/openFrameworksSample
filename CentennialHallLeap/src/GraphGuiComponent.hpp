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

class GraphGuiComponent{

private:
    ofColor graphBackColor = ofColor(255,50,120,220);
    ofColor graphStringColor = ofColor(10,255,200,180);
    ofColor graphBarColor = ofColor(10,255,255,200);

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
