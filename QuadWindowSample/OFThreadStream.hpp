//
//  OFThreadStream.hpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/11.
//
//

/*
 
 並列で動画を読み込み
 メインスレッドでクリマキー合成してる
 
 */

#ifndef OFThreadStream_hpp
#define OFThreadStream_hpp

#define CAM_WIDTH 200
#define CROP_HEIGHT 150

#define MULTISCREEN

#ifdef MULTISCREEN
#define SCREEN_NUM 4
#else
#define SCREEN_NUM 1
#endif

#include "ofMain.h"
#include "MovieThread.hpp"
#include "ofxChromaKeyShader.h"
#include "ofxGui.h"
#include "BlendmodeManager.hpp"


class OFThreadStream : public ofBaseApp{

public:
    ofFbo screenFbo[4];
    MovieThread thread[4];
    ofImage myImage;

    BlendmodeManager mBlendmodeManager;
    int tuningIndex;

    //-------------------Chromakey-----------------
    ofImage bg_image;

    ofxChromaKeyShader *chromakey[4];
    int camW, camH;

    ofFbo checkerboardTex;

    ofxPanel chromaGui[4];

    bool bShowGui;
    bool bUpdateBgColor;
    //-------------------Chromakey-----------------

    void setup();
    void update();
    void draw();
    void exit();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    void drawDebugMasks(int i);
    void drawCheckerboard(float x, float y, int width, int height, int size);
};
#endif /* OFThreadStream_hpp */
