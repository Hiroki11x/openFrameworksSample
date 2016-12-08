//
//  GUI.h
//  abebirthday
//
//  Created by HirokiNaganuma on 2015/09/18.
//
#ifndef __emptyExample__GUI__
#define __emptyExample__GUI__

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxInkSim.h"

class GUI
{
public:
    
    void setup(ofPtr<UniformInfos> uniforms);
    void draw();
    void toggleVisible();
    void resetToDefault();
    
private:
    
    bool bGUIHide;
    
    ofxPanel gui;
    ofXml settings;
    ofPtr<UniformInfos> uniforms;
};

#endif /* defined(__emptyExample__GUI__) */
