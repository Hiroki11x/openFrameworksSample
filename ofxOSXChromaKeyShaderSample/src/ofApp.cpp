#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    bUpdateBgColor = true;

    camW = 640; camH = 480;
    ofSetWindowShape(camW*2, camH*1.5f);

    chromakey = new ofxChromaKeyShader(camW, camH);

    // webcam setup
    webcam.setDesiredFrameRate(60);
    webcam.initGrabber(camW, camH);

    // maskee
    bg_image.load("bg.jpg");

    //GUI
    mGuiManager.setup(chromakey,camW);
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
    mGuiManager.draw(chromakey,camW,bUpdateBgColor);
}


//--------------------------------------------------------------
void ofApp::exit() {
    mGuiManager.exit();
    delete chromakey;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    mGuiManager.keyPressed(key);
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
