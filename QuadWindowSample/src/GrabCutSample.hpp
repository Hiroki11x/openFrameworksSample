//
//  GrabCutSample.hpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/10.
//
//

#ifndef GrabCutSample_hpp
#define GrabCutSample_hpp

#define CAM_WIDTH 800
#define CROP_HEIGHT 600

#include "ofMain.h"
#include "opencv2/opencv.hpp"

class GrabCutSample : public ofBaseApp{
    ofImage img[4];
    ofFbo screenFbo[4];
    cv::VideoCapture cap[4];
    cv::Mat frame[4];
    void setup();
    void update();
    void draw();
};

#endif /* GrabCutSample_hpp */
