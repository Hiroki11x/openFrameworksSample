//
//  GuiManager.hpp
//  ofxOSXChromaKeyShaderSample
//
//  Created by HirokiNaganuma on 5/17/17.
//
//

#ifndef GuiManager_hpp
#define GuiManager_hpp

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxChromaKeyShader.h"

class GuiManager : public ofBaseApp{
public:
    void setup(ofxChromaKeyShader *chromakey, int camW);
    void draw(ofxChromaKeyShader *chromakey,int camW, bool bUpdateBgColor);
    void exit();
    void keyPressed(int key);

    ofxPanel chromaGui;
    bool bShowGui;
};
#endif /* GuiManager_hpp */
