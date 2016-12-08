#include "ofApp.h"
float X,Y;
bool mode;
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
    kinect.addUserGenerator();      //  required for skeleton tracking
    kinect.setMaxNumUsers(2);       //  max num of skeleton to track
    //  start kinect
    kinect.start();
    X=ofGetWidth()/330.0;
    Y=ofGetHeight()/290.0;
    ofToggleFullscreen();
    mode=false;
    
    elapsedTime=0;
    
    int bufferSize=256;
    left.assign(bufferSize,0.0);
    soundStream.setup(this,0,2,44100,bufferSize,4);
};

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();
    volume =ofSoundGetSpectrum(1);
    elapsedTime++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetCircleResolution(50);
    //  normal color
    if(mode){
        ofSetColor(ofRandom(30),ofRandom(30,255), ofRandom(255),ofRandom(255));
    }else{
        ofSetColor(120,120, 120);
    }
    //draw depth/RGB/skeletons images
    kinect.drawImage(0, 0, ofGetWidth(), ofGetHeight());
    ofPushMatrix();
    ofScale(X, Y);
    //draw user
    
    if (kinect.getNumTrackedUsers() > 0) {//検知したとき
        //skeleton data
        ofxOpenNIUser user = kinect.getTrackedUser(0);
        //draw limbs
        ofSetLineWidth(1);
        ofSetColor(255, 255, 255,100);
        for (int i = 0; i < user.getNumLimbs(); i++) {
            ofxOpenNILimb limb = user.getLimb((enum Limb) i);
            if (limb.isFound()) {
                float x1 = limb.getStartJoint().getProjectivePosition().x;
                float y1 = limb.getStartJoint().getProjectivePosition().y;
                float x2 = limb.getEndJoint().getProjectivePosition().x;
                float y2 = limb.getEndJoint().getProjectivePosition().y;
                ofLine(x1, y1, x2, y2);
            }
            if(ofDist(
                            user.getJoint(JOINT_LEFT_HAND).getProjectivePosition().x,
                            user.getJoint(JOINT_LEFT_HAND).getProjectivePosition().y,
                            user.getJoint(JOINT_RIGHT_HAND).getProjectivePosition().x,
                            user.getJoint(JOINT_RIGHT_HAND).getProjectivePosition().y)<50){
                mode=true;
            }else{
                mode=false;
            }
        }
        //  draw joints
        
        ofMesh m;
        m.setMode(OF_PRIMITIVE_POINTS );
        for (int i = 0; i < user.getNumJoints(); i++) {
            /*
             *2 頭
             *5 左手
             *8 右手
             */
            ofNoFill();
            ofxOpenNIJoint joint = user.getJoint((enum Joint) i);
            if(i==0 && joint.isFound()){
                ofSetColor(255, 255, 255,100);
                float x = joint.getProjectivePosition().x;
                float y = joint.getProjectivePosition().y;
                ofCircle(x, y, ofRandom(5,10));
                ofSetCircleResolution(6);
                ofCircle(x, y, 250);
                ofSetLineWidth(4);
                ofSetCircleResolution(3);
                ofCircle(x, y, 200);
                ofSetLineWidth(1);
                ofSetCircleResolution(50);
                ofLine(x,y,x+20,y-20);
                ofDrawBitmapString("Joint Point Num" +ofToString(i), x+20,y-20);
                m.addVertex(ofVec3f(x,y,0));
            }else if(i==2 && joint.isFound()){
                ofSetColor(0, 255, 255,75);
                float x = joint.getProjectivePosition().x;
                float y = joint.getProjectivePosition().y;
                ofCircle(x, y, ofRandom(20,30));
                ofLine(x,y,x+20,y-20);
                ofDrawBitmapString("Joint Point Num" +ofToString(i), x+20,y-20);
                m.addVertex(ofVec3f(x,y,0));
            }else if((i==5||i==8)&& joint.isFound()){//頭
                ofSetColor(0, 255, 255,75);
                float x = joint.getProjectivePosition().x;
                float y = joint.getProjectivePosition().y;
                ofCircle(x, y, ofRandom(5,10));
                ofLine(x,y,x+20,y-20);
                ofDrawBitmapString("Joint Point Num" +ofToString(i), x+20,y-20);
                m.addVertex(ofVec3f(x,y,0));
            }else if(joint.isFound()) {
                ofSetColor(255, 255, 255,100);
                float x = joint.getProjectivePosition().x;
                float y = joint.getProjectivePosition().y;
                ofCircle(x, y, ofRandom(5,10));
                ofLine(x,y,x+20,y-20);
                ofDrawBitmapString("Joint Point Num "+ofToString(i), x+20,y-20);
                m.addVertex(ofVec3f(x,y,0));
            }
            m.draw();
        }
    }//検知したとき終了
    ofPopMatrix();
    ofNoFill();
    ofSetColor(255);
    ofSetCircleResolution(6);
    ofCircle(ofGetWidth()-100, 100, 100);
    ofDrawBitmapString("Time : "+ofToString(ofGetHours())+" : "+ofToString(ofGetMinutes())+" : "+ofToString(ofGetSeconds()),ofGetWidth()-172,100);

    ofFill();
    for(int j=5;j<ofGetWidth();j+=30){
        for(int i=10;i<ofGetHeight();i+=30){
            ofDrawBitmapString("+", j,i);
        }
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
    
//    unsigned short *depthData = kinect.getDepthRawPixels().getPixels();
//    unsigned short depthMM = depthData[y * 640 + x];
//    sprintf(buffer, "%d mm", depthMM);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}
void ofApp::audioIn(float * input,int bufferSize,int nChannels){
    if(elapsedTime%8==0){
        for(int i=0; i<bufferSize; i++){
            left[i] =input[i*2]*0.5;
        }
    }
}