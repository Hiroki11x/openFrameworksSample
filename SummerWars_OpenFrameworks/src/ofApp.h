#pragma once

#include "ofMain.h"
#include "CommentView.h"
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
private:
    vector<CommentView *> commentView;
    ofCamera cam;
    ofTrueTypeFont font;
    ofVideoPlayer video;
    ofTrueTypeFont timerFont;
    bool CameraMode;
    int CameraCursor;
    float CameraX,CameraY,CameraZ=800;
};
