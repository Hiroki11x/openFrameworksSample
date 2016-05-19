
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    
    ofSetVerticalSync(true);
    
    // Escキーで終了しないようにする
    ofSetEscapeQuitsApp(false);
    
    // 使うフォントをロード
    ofxEditor::loadFont("fonts/migmix-1p-regular.ttf", 24);
    
    // sample lua syntax ste programmatically (instead of loaded from xml)
    cppSyntax.setLang("c");
    cppSyntax.addFileExt("c"); // associate .lua with Lua
    cppSyntax.setSingleLineComment("//");
    cppSyntax.setMultiLineComment("/*", "*/");
    cppSyntax.setWord("void", ofxEditorSyntax::KEYWORD);
    cppSyntax.setWord("end", ofxEditorSyntax::KEYWORD);
    cppSyntax.setWord("print", ofxEditorSyntax::FUNCTION);
    editor.getSettings().addSyntax(&cppSyntax);
    editor.getSettings().printSyntaxes(); // print available syntaxes
    //editor.setLangSyntax("Lua"); // set editor syntax manually
    
    // syntax highlighter colors set programmatically (instead of loaded from xml)
    colorScheme.setStringColor(ofColor::yellow);
    colorScheme.setNumberColor(ofColor::orangeRed);
    colorScheme.setCommentColor(ofColor::gray);
    colorScheme.setKeywordColor(ofColor::fuchsia);
    colorScheme.setTypenameColor(ofColor::red);
    colorScheme.setFunctionColor(ofColor::green);
    editor.setColorScheme(&colorScheme);
    
    // open test file, will set syntax based on file extension
    editor.openFile("test.lua");
    ofLogNotice() << "num chars: " << editor.getNumCharacters() << " num lines: " << editor.getNumLines();
    
    // default: white text on black background
    ofBackground(0);
    
    // or black text on white background
    //ofBackground(255);
    //editor.getSettings().setTextColor(ofColor::black);
    //editor.getSettings().setTextShadowColor(ofColor::gray);
    
    debug = false;
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    editor.draw();
    
    if(debug) {
        ofSetColor(255);
        ofDrawBitmapString("fps: "+ofToString((int)ofGetFrameRate()), ofGetWidth()-70, ofGetHeight()-10);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    bool modifierPressed = ofxEditor::getSuperAsModifier() ? ofGetKeyPressed(OF_KEY_SUPER) : ofGetKeyPressed(OF_KEY_CONTROL);
    if(modifierPressed) {
        switch(key) {
            case 's':
                if(editor.getColorScheme()) {
                    editor.clearColorScheme();
                }
                else {
                    editor.setColorScheme(&colorScheme);
                }
                return;
            case 'd':
                debug = !debug;
                return;
            case 'f':
                ofToggleFullscreen();
                return;
            case 'l':
                editor.setLineWrapping(!editor.getLineWrapping());
                return;
            case 'n':
                editor.setLineNumbers(!editor.getLineNumbers());
                return;
            case 'k':
                editor.setAutoFocus(!editor.getAutoFocus());
                return;
            case 'w':
                ofxEditor::setTextShadow(!ofxEditor::getTextShadow());
                return;
            case '1':
                ofLogNotice() << "current line: " << editor.getCurrentLine() <<	" pos: " << editor.getCurrentLinePos();
                editor.setCurrentLinePos(1, 5);
                ofLogNotice() << "current line: " << editor.getCurrentLine() <<	" pos: " << editor.getCurrentLinePos();
                break;
            case '2':
                ofLogNotice() << "current line: " << editor.getCurrentLine() <<	" pos: " << editor.getCurrentLinePos();
                editor.setCurrentLinePos(5, 2);
                ofLogNotice() << "current line: " << editor.getCurrentLine() <<	" pos: " << editor.getCurrentLinePos();
                break;
            case 'p':
                ofLogNotice() << "printing current syntax";
                editor.printSyntax();
                break;
        }
    }
    editor.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
    editor.resize(w, h);
}
