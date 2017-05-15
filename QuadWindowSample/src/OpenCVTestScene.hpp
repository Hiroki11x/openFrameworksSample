//
//  OpenCVTestScene.hpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/09.
//
//

#ifndef OpenCVTestScene_hpp
#define OpenCVTestScene_hpp

//#define CAM_WIDTH 640
//#define CROP_HEIGHT 480

#define CAM_WIDTH 960
#define CROP_HEIGHT 720

#include <opencv2/opencv.hpp>
#include "ofMain.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"

/*
 
 この方法一回諦め
 
 */


class OpenCVTestScene : public ofBaseApp{

private:
    ofImage img[4];
    ofFbo screenFbo[4];

    cv::VideoCapture cap[4];
    cv::Mat frame[4];

    //---------OpenCV Sample として追加 ---------
    ofxCvColorImage colorImg; //オリジナルのカラー映像

    //HSV系に変換した映像情報
    ofxCvColorImage colorImgHSV;

    ofxCvGrayscaleImage grayImage; //グレースケールに変換後
    ofxCvGrayscaleImage grayBg; //キャプチャーした背景画像
    ofxCvGrayscaleImage grayDiff; //現在の画像と背景との差分
    ofxCvContourFinder contourFinder; //輪郭抽出のためのクラス

    ofxCvColorImage tmp;
    ofTexture trackedTextureRed;

    //HSV系の色相、彩度、明度のマップ
    ofxCvGrayscaleImage hueImg;
    ofxCvGrayscaleImage satImg;
    ofxCvGrayscaleImage briImg;

    //もとの映像情報のピクセルの彩度と明度が
    //指定した色に近ければ255を代入、遠ければ0を代入
    unsigned char * colorTrackedPixelsRed;

    bool bLearnBakground; //背景画像を登録したか否か
    bool showCvAnalysis; //解析結果を表示するか
    int threshold; //2値化の際の敷居値
    int videoMode; //表示する画像を選択
    //------------------------------------------

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
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    void exit();
};

#endif /* OpenCVTestScene_hpp */
