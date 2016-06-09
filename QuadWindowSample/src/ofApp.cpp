#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(0);

//    img[0].load("img_0.jpeg");
//    img[1].load("img_1.jpeg");
//    img[2].load("img_2.jpeg");
//    img[3].load("img_3.jpeg");

    for(int i = 0 ;i<4 ;i++){
        screenFbo[i].clear();
        screenFbo[i].allocate(250,250);
    }

     //岩瀬 192.168.145.238
     cap[0] = cv::VideoCapture("http://192.168.145.238:7890/ipvideo.mjpg");
     img[0].allocate(CAM_WIDTH, CROP_HEIGHT, OF_IMAGE_COLOR);

     //長田 192.168.157.5
     cap[1] = cv::VideoCapture("http://192.168.157.5:7890/ipvideo.mjpg");
     img[1].allocate(CAM_WIDTH, CROP_HEIGHT, OF_IMAGE_COLOR);

     //奥村 192.168.145.27 (KeiのPCの設定的に、きつい)
     cap[2] = cv::VideoCapture("http://192.168.145.27:7890/ipvideo.mjpg");
     img[2].allocate(CAM_WIDTH, CROP_HEIGHT, OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){


    for(int i = 0; i<4;i++){
        if (cap[i].isOpened() ){
            cap[i] >> frame[i];
            if(frame[i].empty()){
                cout << "empty" << endl;
                exit();
            }else{
                img[i].setFromPixels(frame[i].ptr(), frame[i].cols, frame[i].rows, OF_IMAGE_COLOR,FALSE);
            }
            if(cv::waitKey(30) >= 0) exit();
        }
    }

    for(int i = 0 ;i<4 ;i++){
        screenFbo[i].begin();
        ofClear(0);
        if(img[i].isAllocated())img[i].draw(50,50,200,200);
        screenFbo[i].end();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotate(45);
    screenFbo[0].draw(0,0);
    ofRotate(90);
    screenFbo[1].draw(0,0);
    ofRotate(90);
    screenFbo[2].draw(0,0);
    ofRotate(90);
    screenFbo[3].draw(0,0);
    ofPopMatrix();
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
