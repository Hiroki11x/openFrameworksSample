//
//  DrawerUtil.hpp
//  ofxOSXChromaKeyShaderSample
//
//  Created by HirokiNaganuma on 5/15/17.
//
//

#ifndef DrawerUtil_hpp
#define DrawerUtil_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxChromaKeyShader.h"

class DrawerUtil{
public:
    static void setupCheckerboard(int width, int height, int size);
    static void drawDebugMasks(int camW, int camH, ofxChromaKeyShader *chromakey, ofVideoGrabber webcam);
    static void drawCheckerboard(float x, float y, int width, int height, int size);
    static ofFbo checkerboardTex;
};

#endif /* DrawerUtil_hpp */
