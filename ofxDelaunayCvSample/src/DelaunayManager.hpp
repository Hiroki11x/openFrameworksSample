//
//  DelaunayManager.hpp
//  ofxDelaunayCvSample
//
//  Created by HirokiNaganuma on 2016/05/26.
//
//

#ifndef DelaunayManager_hpp
#define DelaunayManager_hpp
#pragma once

#include "ofMain.h"
#include "DelaunayComponent.hpp"

class DelaunayManager : public ofBaseApp{
private:
    DelaunayComponent mDelaunay;

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

#endif /* DelaunayManager_hpp */
