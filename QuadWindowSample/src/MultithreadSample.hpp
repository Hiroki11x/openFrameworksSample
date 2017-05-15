//
//  MultithreadSample.hpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/10.
//
//

/*
 ダメだった
 */

#ifndef MultithreadSample_hpp
#define MultithreadSample_hpp

#define CAM_WIDTH 400
#define CROP_HEIGHT 300

#define SCREEN_NUM 4


#include <opencv2/opencv.hpp>
#include "ofMain.h"
#include "CameraStreamer.hpp"
#include <opencv2/highgui.hpp>

class MultithreadSample : public ofBaseApp{
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
    
    
};

#endif /* MultithreadSample_hpp */
