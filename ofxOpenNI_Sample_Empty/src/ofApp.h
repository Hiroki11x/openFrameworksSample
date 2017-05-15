
#include "ofxOpenNI.h"
#include "ofMain.h"

class ofApp : public ofBaseApp{
    
//ofxOpenNI
private:
    ofxOpenNI kinect;
public:
    
	void setup();
	void update();
	void draw();
    void exit();
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
};

