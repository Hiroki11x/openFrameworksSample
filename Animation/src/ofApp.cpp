#include "ofApp.h"


float radius;
float radian;
float vertex_angle;
float angle;
float rect_w;
float rect_h;
float r;
float dist_x=-2;
float dist_y=-2;
float middle_x;
float middle_y;
float multiple;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    radius = 100;
    radian = 0;
    angle = 0;
    initTime=0;
    rect_w = 2000;
    rect_h = 2000;
    ofSetCircleResolution(3);
    player.load("FLASH.mp4");
    player.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    auto duration=1.f;
    auto endTime =initTime+duration;
    auto now =ofGetElapsedTimef();
    angle=ofxeasing::map_clamp(now,initTime,endTime,0,200,&ofxeasing::bounce::easeOut);
    r=ofxeasing::map_clamp(now,initTime,endTime,0, 200, &ofxeasing::quint::easeOut);
    multiple=ofxeasing::map_clamp(now,initTime,endTime,1,200,&ofxeasing::quint::easeOut);
    dist_x=multiple*dist_x/30;
    dist_y=multiple*dist_y/30;
    
    radian =radian+ 0.5;
    vertex_angle += 0.2;
    if(radian>PI*2){
        radian=0;
    }
    if(vertex_angle>PI*2){
        vertex_angle=0;
    }
    player.update();
 
}

//--------------------------------------------------------------
void ofApp::draw(){
    player.draw(0, 0, ofGetWidth(),ofGetHeight());
    ofSetColor(255,200);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofDrawCircle(0, 0, r);
    ofDrawLine(middle_x-dist_x,middle_x-dist_y,middle_x+dist_x,middle_y+dist_y);
    
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
        dist_x =1;
        dist_y =1;
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

void ofApp::rotateScreen(int center_x,int center_y,int angle){
    ofPushMatrix();
    ofFill();
    ofTranslate(center_x,center_y);
    ofRotateZ(angle);
    ofTranslate(rect_w/2, rect_w/2);//一度中心を基準に
    ofRotateZ(45);
    ofTranslate(-(sqrt(2)-1)/2*rect_h,0);
    ofDrawRectangle(-rect_w/2,-rect_h/2,rect_w,rect_h);
    ofPopMatrix();
}

void ofApp::triangle(int x,int y,float r){
    ofSetCircleResolution(3);
    ofDrawCircle(0, 0, r);
}

void ofApp::circle_rotate(int x,int y,float r,float angle){
    ofFill();
    ofBeginShape();
    for(float i = 0; i<vertex_angle; i+=0.01f){
        ofVertex(radius*sin(radian+i), radius*cos(radian+i));
    }
    ofEndShape();
}

void ofApp::circle_outline(int x,int y,float r,float angle){
    ofNoFill();
    ofBeginShape();
    for(float i = 0; i<vertex_angle; i+=0.01f){
        ofVertex(r*sin(radian+i),r*cos(radian+i));
    }
    ofEndShape();
}

