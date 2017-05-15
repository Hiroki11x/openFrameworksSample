#pragma once

#include "ofMain.h"
#include "TreeNode.hpp"

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

    ofVec2f startpos;
    int gen_stage;
    const int num_of_gen_multi =2;
    const float radius_offset[2] = {0.2f,-0.2f};
    vector<TreeNode> treenodes;
};
