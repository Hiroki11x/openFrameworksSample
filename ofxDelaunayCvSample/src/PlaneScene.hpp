//
//  PlaneScene.hpp
//  ofxDelaunayCvSample
//
//  Created by HirokiNaganuma on 2016/05/19.
//
//

#ifndef PlaneScene_hpp
#define PlaneScene_hpp

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxDelaunay.h"

class PlaneScene : public ofBaseApp{

public:

    ofVideoGrabber cam;
    ofxDelaunay delaunay;
    ofVboMesh mesh;
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

#endif /* PlaneScene_hpp */
