//
//  ChromakeyManager.hpp
//  ofxOSXChromaKeyShaderSample
//
//  Created by HirokiNaganuma on 5/17/17.
//
//

#ifndef ChromakeyManager_hpp
#define ChromakeyManager_hpp

#include "ofMain.h"
#include "ofxChromaKeyShader.h"

class ChromakeyManager{
public:
    void setup();
    void setup(int camW, int camH);
    void update();
    void update(ofImage* img);
    void draw();
    void exit();
    void keyPressed(int key);
    ofxChromaKeyShader* getChromaKey();
    ofxChromaKeyShader* chromakey;
    int camW, camH;
    ofImage bk_img;
};

#endif /* ChromakeyManager_hpp */
