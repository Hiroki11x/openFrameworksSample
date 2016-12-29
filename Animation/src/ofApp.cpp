#include "ofApp.h"


float radius;
float radian;
float vertex_angle;
float angle;
float rect_w;
float rect_h;
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(30);
    radius = 100;
    radian = 0;
    angle = 0;
    initTime=0;
    rect_w = 2000;
    rect_h = 2000;
    ofSetCircleResolution(3);
}

//--------------------------------------------------------------
void ofApp::update(){
    auto duration=2.f;
    auto endTime =initTime+duration;
    auto now =ofGetElapsedTimef();
    angle=ofxeasing::map_clamp(now,initTime,endTime,0,800,&ofxeasing::bounce::easeOut);

    
    radian =radian+ 0.5;
    vertex_angle += 0.2;
    if(radian>PI*2){
        radian=0;
    }
    if(vertex_angle>PI*2){
        vertex_angle=0;
    }
//    angle=angle+10;
    
 
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,200);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
//    ofDrawLine(0, 0, radius*sin(radian), radius*cos(radian));
    
    ofSetColor(255,250);
    
    ofNoFill();
    ofBeginShape();
//    ofVertex(0, 0);
    for(float i = 0; i<vertex_angle; i+=0.01f){
        ofVertex(radius*sin(radian+i), radius*cos(radian+i));
    }
    ofEndShape();
    
    ofSetColor(255,200);
//    ofDrawLine(radius*cos(radian), radius*sin(radian), radius*cos(radian+0.02), radius*sin(radian+0.02));
    ofFill();
    ofPushMatrix();
    ofRotateZ(angle);
    ofTranslate(rect_w/2, rect_w/2);//一度中心を基準に
    ofRotateZ(45);
    ofTranslate(-(sqrt(2)-1)/2*rect_h,0);
    ofDrawRectangle(-rect_w/2,-rect_h/2,rect_w,rect_h);
    ofPopMatrix();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key ==' '){
        initTime = ofGetElapsedTimef();
    }
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
