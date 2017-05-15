//
//  OFThreadSample.cpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/10.
//
//

#include "OFThreadSample.hpp"

void OFThreadSample::setup() {

    ofxOpenGLContextScope::setup();
    // start the thread
    thread.init();
    thread.startThread();    // blocking, non verbose
}

void OFThreadSample::update() {

//    // lock access to the resource
//    thread.lock();
//
//    // copy image
//    myImage = thread.image;
//
//    // done with the resource
//    thread.unlock();
}

void OFThreadSample::exit() {

    // stop the thread
    thread.stopThread();
}

void OFThreadSample::draw() {
    thread.image.draw(0, 0,100,100);
    // stop the thread
}
//--------------------------------------------------------------
void OFThreadSample::keyPressed(int key){

}

//--------------------------------------------------------------
void OFThreadSample::keyReleased(int key){

}

//--------------------------------------------------------------
void OFThreadSample::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void OFThreadSample::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void OFThreadSample::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void OFThreadSample::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void OFThreadSample::windowResized(int w, int h){

}

//--------------------------------------------------------------
void OFThreadSample::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void OFThreadSample::dragEvent(ofDragInfo dragInfo){
    
}