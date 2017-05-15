#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxGui.h"
#include "ofxOpenCv.h"
#include "ofxAssimpModelLoader.h"

#define _USE_LIVE_VIDEO

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
    
#ifdef _USE_LIVE_VIDEO
    //ライブカメラを使用する際には、カメラ入力を準備
    ofVideoGrabber 		vidGrabber;
#else
    //あらかじめ録画した映像を使用する際には、ビデオプレイヤーを準備
    ofVideoPlayer 		vidPlayer;
#endif
    
    ofxCvColorImage			colorImg;  //オリジナルのカラー映像
    ofxCvGrayscaleImage 	grayImage;  //グレースケールに変換後
    ofxCvGrayscaleImage 	grayBg;  //キャプチャーした背景画像
    ofxCvGrayscaleImage 	grayDiff;  //現在の画像と背景との差分
    ofxCvContourFinder 	contourFinder;  //輪郭抽出のためのクラス
    
    int 				threshold;  //2値化の際の敷居値
    int                 videoMode;  //表示する画像を選択
    float               degree;
    bool				bLearnBakground;  //背景画像を登録したか否か
    bool                showCvAnalysis;  //解析結果を表示するか
    
    ofxKinect               kinect;
    ofImage                 cameraImage;
    ofSpherePrimitive       sphere;
    ofImage                 image;
    ofxAssimpModelLoader    model;
    
};
