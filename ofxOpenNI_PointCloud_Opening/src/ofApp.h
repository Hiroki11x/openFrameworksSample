#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxGui.h"
#include "ofxOpenCv.h"

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
    void drawPointCloud();
    void exit();
    ofxKinect kinect;
    int angle;
    ofEasyCam easyCam;
    //    ofCamera camera;
    
    ofParameter<int> near;
    ofParameter<int> far;
    
    ofParameter<float> radius;
    ofParameter<ofColor> color;
    ofParameter<ofVec2f> center;
    ofParameter<int> circleResolution;
    ofParameter<bool> filled;
    ofxButton twoCircles;
    ofxButton ringButton;
    ofParameter<string> screenSize;
    
    ofxPanel gui,gui2;
    
    void audioIn(float * input, int bufferSize, int nChannles);
    vector <float> left;
    ofSoundStream soundStream;
    float *volume;
    int slide;
    int elapsedTime;
    
    ofImage img;
    ofImage lockon;
    ofxCvHaarFinder finder;
};
