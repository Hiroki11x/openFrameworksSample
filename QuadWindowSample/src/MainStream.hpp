//
//  MainStream.hpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/09.
//
//

#ifndef MainStream_hpp
#define MainStream_hpp

#define CAM_WIDTH 200
#define CROP_HEIGHT 150

#define MULTISCREEN

#ifdef MULTISCREEN
#define SCREEN_NUM 4
#else
#define SCREEN_NUM 1
#endif

#include <opencv2/opencv.hpp>
#include "ofMain.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"
#include "ofxChromaKeyShader.h"
#include "ofxGui.h"
#include "BlendmodeManager.hpp"

class MainStream : public ofBaseApp{
    void setup();
    void update();
    void draw();
    void exit();

    void drawDebugMasks(int i) ;
    void drawCheckerboard(float x, float y, int width, int height, int size);

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

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


    //-------------------mjpg Connection-----------------
    ofImage img[4];
    ofFbo screenFbo[4];

    cv::VideoCapture cap[4];
    cv::Mat frame[4];
    //-------------------mjpg Connection-----------------
};

#endif /* MainStream_hpp */