//
//  OFThreadSample.hpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/10.
//
//

#ifndef OFThreadSample_hpp
#define OFThreadSample_hpp


#define SCREEN_NUM 4

#include "ofMain.h"
#include "MyThread.hpp"
//#include <opencv2/opencv.hpp>
//#include "CameraStreamer.hpp"
//#include <opencv2/highgui.hpp>


class OFThreadSample : public ofBaseApp{

public:
    MyThread thread;
    ofImage myImage;

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

#endif /* OFThreadSample_hpp */
