#include "ofMain.h"
#include "ofApp.h"
#include "OpenCVTestScene.hpp"

//========================================================================
int main( ){
	ofSetupOpenGL(480*2,360*2,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
//	ofRunApp(new ofApp());
    ofRunApp(new OpenCVTestScene());

}
