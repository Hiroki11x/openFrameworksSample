//
//  CvParallelStream.hpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/10.
//
//

#ifndef CvParallelStream_hpp
#define CvParallelStream_hpp





#include <opencv2/opencv.hpp>
#include "ofMain.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"
#include "ofxChromaKeyShader.h"
#include "ofxGui.h"
#include "BlendmodeManager.hpp"
#include "CvParallelThread.hpp"

#ifdef CHROMAKEY
#define SCREEN_NUM 4
#else
#define SCREEN_NUM 1
#endif

class CvParallelStream : public ofBaseApp{
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

    BlendmodeManager mBlendmodeManager;
    int tuningIndex;

    CvParallelThread mCvParallelThread[4];
    bool bShowGui;
    int camW, camH;
    ofFbo checkerboardTex;
};


#endif /* CvParallelStream_hpp */
