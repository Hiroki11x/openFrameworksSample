#pragma once

#include "ofMain.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    int size = 100;
    bool matrix[100][100];
    bool tmp_matrix[100][100];
    ofVec2f VVector[8] = {ofVec2f(-1,-1),ofVec2f(0,-1),ofVec2f(1,-1),
        ofVec2f(-1,0),ofVec2f(1,0),
        ofVec2f(-1,1),ofVec2f(0,1),ofVec2f(1,1)};
};
