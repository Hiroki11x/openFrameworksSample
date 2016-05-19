
#pragma once

#include "ofMain.h"
#include "ofxEditor.h"

// syntax example using a single text editor instance
//
// app key commands:
//    MOD -> CTRL or Super (Windows Key, Mac CMD)
//
// MOD + s: toggle syntax highlighting
// MOD + d: toggle debug framerate display
// MOD + f: toggle fullscreen
// MOD + l: toggle line wrapping
// MOD + n: toggle line numbers
// MOD + k: toggle auto focus zooming
// MOD + w: toggle text shadow
// MOD + 1: set line position (debugging)
// MOD + 2: set line position again (debugging)
// MOD + p: print current syntax parser text blocks (debugging)
//
// see ofxGLEditor.h for editor key commands
//
class ofApp : public ofBaseApp {
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void windowResized(int w, int h);
    
    ofxEditor editor;
    ofxEditorColorScheme colorScheme;
    ofxEditorSyntax cppSyntax;
    bool debug; //< show fps?
};
