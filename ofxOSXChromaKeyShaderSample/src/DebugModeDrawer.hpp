//
//  DebugModeDrawer.hpp
//  ofxOSXChromaKeyShaderSample
//
//  Created by HirokiNaganuma on 5/17/17.
//
//

#ifndef DebugModeDrawer_hpp
#define DebugModeDrawer_hpp

#include "ofMain.h"
#include "GuiManager.hpp"
#include "DrawerUtil.hpp"

class DebugModeDrawer{
public:
    void setup(ofxChromaKeyShader* chromakey, int camW, int camH);
    void draw(ofxChromaKeyShader* chromakey, ofImage img);
    void exit();
    void keyPressed(int key);

    GuiManager mGuiManager;
    int camW, camH;
};

#endif /* DebugModeDrawer_hpp */
