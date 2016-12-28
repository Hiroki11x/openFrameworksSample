//
//  nonLeapApp.hpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/9/16.
//
//

#ifndef nonLeapApp_hpp
#define nonLeapApp_hpp

#include "ofMain.h"
#include "ofxLeapMotion2.h"
#include "ImageManager.hpp"
#include "SideUIManager.hpp"
#include "ofxSyphonServer.h"

class nonLeapApp : public ofBaseApp{

private:

    ofEasyCam cam;

    ofVec3f pastHand;

    SideUIManager mSideUIManager;
    ofxSyphonServer mSyphonServer;

    int mode;
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
    
};
#endif /* nonLeapApp_hpp */
