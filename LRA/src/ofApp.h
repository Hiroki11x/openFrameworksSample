#pragma once

///opt/storage/data/resnet/cifar-10/resnet-l20-b128/scale3block3BConv2D/images_576x12800.csv
#define CSVFILE "/Users/hirokinaganuma/Documents/HACK/of_v0.9.2_osx_release/apps/myApps/LRA/bin/data/last_01.csv"

#define BLOCKSIZE 576

//#define MY_M 64
//#define MY_K 576

#define MY_M 576
#define MY_K 12800

//#define MY_M 27
//#define MY_K 147968


#include "ofMain.h"
#include <iostream>

class ofApp : public ofBaseApp{
private:
    float max;
    float average;
    float *A;
    int width, height;
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


    void check_malloc_buf(char* buf);
};
