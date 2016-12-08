#pragma once

#include "ofMain.h"

#include "ofxQuadWarp.h"//ofxQuadWarpをインクルード

#define NUM 5

class ofApp : public ofBaseApp{

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void warperDraw();
    void exit();
    
    ofxQuadWarp warper[NUM];
    ofFbo fbo[NUM];
    int w[NUM];
    int h[NUM];
    ofVideoPlayer video[3];
		
};
