#pragma once
#include "ofMain.h"
#include "ofxLeapMotion2.h"
#include "ImageManager.hpp"
class ofApp : public ofBaseApp{

private:
    ofxLeapMotion leap;
    vector <ofxLeapMotionSimpleHand> simpleHands;


    vector <int> fingersFound;
    ofEasyCam cam;
    ofPoint hand[4];
    ofLight light;
    
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
