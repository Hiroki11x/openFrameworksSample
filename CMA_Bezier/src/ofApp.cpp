#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetCircleResolution(60);//関係ない
    for(int i =0 ;i<100 ; i++){
        position.push_back(ofVec2f(ofRandom(ofGetWidth()),
                                   ofRandom(ofGetHeight())
                                   )
                           );
        speed.push_back(ofVec2f(ofRandom(-3,3),
                                ofRandom(-3,3)));
        
        strings.push_back(new FlowString());
        strings.back()->setPosition(ofRandom(ofGetWidth()),
                                   ofRandom(ofGetHeight()));
        strings.back()->setSpeed(ofRandom(-3,3),
                                 ofRandom(-3,3));
        strings.back()->setString("Test; "+ofToString(ofRandom(100)));
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i =0 ;i<speed.size() ; i++){
        position.at(i).x+=speed.at(i).x;
        position.at(i).y+=speed.at(i).y;
        
        if(position.at(i).x< 0 || position.at(i).x>ofGetWidth()){
            speed.at(i).x*=-1;
        }
        
        if(position.at(i).y< 0 || position.at(i).y>ofGetHeight()){
            speed.at(i).y*=-1;
        }
        strings.at(i)->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(50,50,50),ofColor(0,0,0));
    for(int i =0 ;i<speed.size()-2 ; i++){
        int k = ((int)(position.at(i).x*position.at(i).y))%256;
        ofNoFill();
        ofSetColor(ofColor::fromHsb((ofGetFrameNum()+i*3)%256,255,255,255));
        ofSetLineWidth(sqrt(sqrt(k))/10);
        ofBezier(position.at(0).x,position.at(0).y,
                 
                 position.at(i).x+speed.at(i).x,position.at(i).y+speed.at(i).y,
                 position.at(i+1).x+speed.at(i).x,position.at(i+1).y+speed.at(i).y,
                 
                 position.at(i+2).x+speed.at(i).x,position.at(i+2).y+speed.at(i).y);
        strings.at(i)->draw();
    }
    ofFill();
    ofSetColor(10,100);
    ofCircle(position.at(0).x,position.at(0).y,20);
    ofCircle(position.at(1).x,position.at(1).y,20);
    
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

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
