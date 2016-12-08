#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxDelaunay.h"
#include "ofxKinect.h"
#include "ofxPostGlitch.h"
#include "ofxSyphon.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxCv::FlowPyrLK flow;//映像からピクセルデータをせっとしたりする
    ofxDelaunay delaunay;//ドロネー(三角形分割してくれるアドオン)
    ofxKinect kinect;//Kinectのインスタンス
    ofxPostGlitch myGlitch;//エフェクトをかけたりする
    
    ofxSyphonServer mainOutputSyphonServer;//
    ofxSyphonServer individualTextureSyphonServer;
    ofxSyphonClient mClient;
    
    vector<ofVec3f> pts;
    bool	bDrawLenna;
    bool	bShowHelp;
    
    ofFbo fbo;//映像をためておく
    ofImage lenna;
    ofVideoPlayer video;
};
