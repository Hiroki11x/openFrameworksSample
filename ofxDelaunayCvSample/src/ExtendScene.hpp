//
//  ExtendScene.hpp
//  ofxDelaunayCvSample
//
//  Created by HirokiNaganuma on 2016/05/19.
//
//

#ifndef ExtendScene_hpp
#define ExtendScene_hpp

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxDelaunay.h"

class ExtendScene : public ofBaseApp{

public:

    float w,h;

    ofVideoGrabber cam;
    ofxDelaunay delaunay;
    ofVboMesh mesh;

    ofxCvColorImage colorImage;
    ofxCvGrayscaleImage grayImage, edgeImage;


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
    
};

#endif /* ExtendScene_hpp */
