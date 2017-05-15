#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    bShowGui = true;
    bUpdateBgColor = true;

    camW = 640; camH = 480;
    ofSetWindowShape(camW*2, camH*1.5f);

    chromakey = new ofxChromaKeyShader(camW, camH);

    // webcam setup
    webcam.setDesiredFrameRate(60);
    webcam.initGrabber(camW, camH);

    // maskee
    bg_image.load("bg.jpg");

    // GUI
    chromaGui.setDefaultHeight(18);
    chromaGui.setDefaultWidth(camW/2);
    chromaGui.setup(chromakey->generalParams, "chromaSettings.xml");
    chromaGui.loadFromFile("chromaSettings.xml");
    chromaGui.setPosition(0, 0);	

}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));

    webcam.update();
    if(webcam.isFrameNew()) {
        if(bUpdateBgColor)
            chromakey->updateBgColor(webcam.getPixels());
        chromakey->updateChromakeyMask(webcam.getTexture(), bg_image.getTexture());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofBackground(0);

    // draw Cam mask
    chromakey->drawFinalImage(camW/2, 0, camW, camH);
    DrawerUtil::drawDebugMasks(camW, camH, chromakey, webcam);

    // GUI
    if(bShowGui) {
        chromaGui.draw();

        // draw bg color's reference Rect
        if(bUpdateBgColor) {
            ofPushStyle();
            ofNoFill();
            ofSetLineWidth(3);
            ofSetColor(255);
            ofVec2f bgColorPos = chromakey->bgColorPos.get();
            ofDrawRectangle(bgColorPos.x + camW/2, bgColorPos.y, chromakey->bgColorSize.get(), chromakey->bgColorSize.get());
            ofDrawBitmapString("bgColor", bgColorPos.x + camW/2, bgColorPos.y - 5);
            ofPopStyle();
        }
    }
}


//--------------------------------------------------------------
void ofApp::exit() {
    chromaGui.saveToFile("chromaSettings.xml");
    delete chromakey;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
