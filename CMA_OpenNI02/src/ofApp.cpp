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
    
    kinect.getDepthGenerator().GetAlternativeViewPointCap().SetViewPoint(kinect.getImageGenerator());
    kinect.addUserGenerator();
    
    kinect.start();//  start kinect
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    kinect.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    kinect.drawDepth(0, 0, 640, 480);
    //kinect.drawSkeletons(0,0,640,480);
    ofSetCircleResolution(20);
    if (kinect.getNumTrackedUsers() > 0) {//人間を一人以上検知したとき
        ofxOpenNIUser user = kinect.getTrackedUser(0);//0番目の人をuserとします。(一人のみしか検知しないとき)
        //関節に円を描く
        ofSetColor(255, 255, 255,ofRandom(255));//色は白がチカチカするように設定
        for (int i = 0; i < user.getNumJoints(); i++) {//人の関節の数だけfor文を回します。関節の数は円の数です。
            ofxOpenNIJoint joint = user.getJoint((enum Joint) i);//i(数値を)enum型に変換します。
            if (joint.isFound()) {//その関節が検知されているとき
                float x = joint.getProjectivePosition().x;//関節のx座標
                float y = joint.getProjectivePosition().y;//関節のy座標
                switch ((enum Joint) i) {
                    case JOINT_HEAD:
                    case JOINT_LEFT_HAND:
                    case JOINT_RIGHT_HAND:
                    case JOINT_LEFT_FOOT:
                    case JOINT_RIGHT_FOOT:
                        ofSetColor(255,0,0);
                        ofNoFill();
                        ofSetCircleResolution(3);
                        ofTranslate(x,y);
                        ofRotate(i*30);
                        ofSetLineWidth(1);
                        for(int j =1 ;j<4;j++){
                            ofCircle(0, 0,j*5);
                        }
                        ofRotate(-i*30);
                        ofSetCircleResolution(6);
                        ofSetColor(255,0,0,100);
                        ofFill();
                        ofCircle(0, 0, 35);
                        ofTranslate(-x,-y);
                        
                        break;
                    default:
                        ofSetLineWidth(0.1);
                        ofSetCircleResolution(6);
                        ofSetColor(255,100);
                        ofNoFill();
                        for(int j =1 ;j<10;j++){
                            ofCircle(x,y,j*2);
                        }
                        break;
                }
            }
        }//Jointに関するfor文を終了
        
        ofSetLineWidth(1);
        ofSetColor(255);
        for (int i = 0; i < user.getNumLimbs(); i++) {
            ofxOpenNILimb limb = user.getLimb((enum Limb) i);//i(数値を)enum型に変換します。
            if (limb.isFound()) {//そのlimbが検知されているとき
                float sX = limb.getStartJoint().getProjectivePosition().x;
                float sY = limb.getStartJoint().getProjectivePosition().y;
                float eX = limb.getEndJoint().getProjectivePosition().x;
                float eY = limb.getEndJoint().getProjectivePosition().y;
                ofLine(sX, sY, eX, eY);
            }
        }//Limbに関するfor文を終了
        
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
