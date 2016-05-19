#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetVerticalSync(true);
    ofSetFrameRate(30);

    bool result = response.openLocal("fb_pictures.json");
    if(!result){
        cout << "Error:Not Found Json Data!" << endl;
    } else {
        for(int i = 0; i < response.size(); i++){
            cout << response[to_string(i)] << endl;
            pictures.push_back(ofImage(response[to_string(i)].asString()));
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int x = 0;
    int y = 0;
    for(auto pic: pictures){
        if(x>ofGetWidth()/100-1){
            x-=(ofGetWidth()/100)+1;
            y++;
        }
        pic.draw(x*100, y*100, 100, 100);
        x++;
    }
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
