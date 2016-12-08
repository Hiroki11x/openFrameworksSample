#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include "ofxJSONElement.h"
//#include "ofxARTSATAPI.h"
//#include "ofxSgp.h"

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
//    virtual void onNotifyTLE(ofxSAT::TLERec const& tle, ofxSATTime const& time);
//    virtual void onNotifyData(ofxSATTime const& time);
//    ofxInvaderSAT invader;
//    ofxSgp sgp;
//    ofxSATTime current;
//    ofVec3f position;
    
    ofLight light;
    ofEasyCam cam;
    ofxJSONElement response;
    ofVec3f angleSpeed;
};
