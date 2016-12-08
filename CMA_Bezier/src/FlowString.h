//
//  FlowString.h
//  Graphics_Sample
//
//  Created by HirokiNaganuma on 2015/08/10.
//
//
#include "ofMain.h"

#ifndef Graphics_Sample_FlowString_h
#define Graphics_Sample_FlowString_h


class FlowString{
public:
    float pos_x;
    float pos_y;
    float sp_x;
    float sp_y;
    string text;
    
    FlowString(){};
    
    void setPosition(float x,float y);
    void setSpeed(float speed_x,float speed_y);
    void setString(string args);
    void update();
    void draw();
};

#endif
