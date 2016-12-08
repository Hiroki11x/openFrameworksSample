#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    //  window
    ofBackground(0, 0, 0);
    ofSetWindowShape(640, 480);
    ofSetFrameRate(30);
    //  setup ofxOpenNI
    kinect.setup();
    kinect.setRegister(true);
    kinect.setMirror(true);
    kinect.addImageGenerator();     //  required for RGB image
    kinect.addDepthGenerator();     //  required for depth image
    kinect.addHandsGenerator();//手のtrackingを行えるように設定
    kinect.addAllHandFocusGestures();//手のtrackingを行えるように設定
    kinect.setMaxNumHands(2);//Trackingする手の最大数
    kinect.start();//  start kinect
    
    //---------------------加速度検知-------------------------
    mode=0;
    //---------------------加速度検知-------------------------
}
//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    kinect.drawDepth(0, 0);
    if(mode==0){
       ofSetColor(255);
    }else{
        ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
    }
    
    if (kinect.getNumTrackedHands() > 0) {//手を一つ以上検知した時
        for(int i =0;i<kinect.getNumTrackedHands();i++){
            ofxOpenNIHand hand = kinect.getTrackedHand(i);
            p[i] = hand.getPosition();
            ofCircle(p[i].x, p[i].y, 20);
            
            //---------------------加速度検知-------------------------
            int newacc =ofDist(p[i].x, p[i].y,preP[i].x, preP[i].y);//今計算できる加速度
            if(acc[i]<20 && newacc>20){//前回の加速度accが小さく、かつ、今回初めて加速度が大きくなった時
                mode=(mode+1)%2;
            }
            acc[i] = newacc;//過去の加速度に値渡し(次のフレームで現在の加速度を過去の加速度として使う)
        }
        for(int j=0;j<2;j++){
            preP[j] = p[j];//過去の座標に値渡し(次のフレームで現在の座標を過去の座標として使う)
        }
        //---------------------加速度検知-------------------------
        
    }
}
//--------------------------------------------------------------
void ofApp::exit(){

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
void ofApp::windowResized(int w, int h){

}
