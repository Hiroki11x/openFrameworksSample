//
//  GrabCutSample.cpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/10.
//
//

/*
 一番planeっぽいコード
 精度悪いし、FPS0に成る
 */

#include "GrabCutSample.hpp"

void GrabCutSample::setup(){
    cap[0] = cv::VideoCapture("http://192.168.149.229:7890/ipvideo.mjpg");
    img[0].allocate(CAM_WIDTH, CROP_HEIGHT, OF_IMAGE_COLOR);
}

void GrabCutSample::update(){
    
    for(int i = 0; i<1;i++){
        if (cap[i].isOpened() ){
            cap[i] >> frame[i];
            if(frame[i].empty()){
                cout << "empty" << endl;
                exit();
            }else{
                cv::Rect roi(0, 0,CAM_WIDTH, CROP_HEIGHT);				// 前景抽出したい範囲を指定
                cv::Mat im, im2, mask, bg, fg;
                im = frame[i];
                cv::grabCut(im, im2, roi, bg, fg,1,cv::GC_INIT_WITH_RECT);
                cv::compare(im2, cv::GC_PR_FGD, mask, cv::CMP_EQ);	// 前景のマスク画像を作成
                im.copyTo(im2, mask);					// マスク画像を用いて入力画像から前景抽出
                img[i].setFromPixels(im2.ptr(), im2.cols, im2.rows, OF_IMAGE_COLOR);
            }
            if(cv::waitKey(30) >= 0) exit();
        }
    }
}

void GrabCutSample::draw(){
    ofSetWindowTitle("FPS"+ofToString(ofGetFrameRate()));
    for(int i = 0 ;i<1 ;i++){
//        screenFbo[i].begin();
        ofClear(0);
        if(img[i].isAllocated())img[i].draw(0,0);
//        screenFbo[i].end();
    }
}