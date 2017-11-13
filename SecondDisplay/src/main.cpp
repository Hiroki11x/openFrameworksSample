#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    ofGLFWWindowSettings windowSettings;
    windowSettings.decorated = false;
    windowSettings.width = 3440;
    windowSettings.height = 1440;
    ofCreateWindow(windowSettings);
    ofRunApp(new ofApp());
}
