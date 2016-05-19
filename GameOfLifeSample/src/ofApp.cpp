#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(5);
    ofBackground(255);
    
    for(int i = 0 ;i < size; i++){
        for(int j = 0 ;j < size; j++){
            matrix[i][j] = false;
            if((i>5 || i<10) && (j>5 || j<10)){
                matrix[i][j] = true;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 1 ;i < size-1; i++){
        for(int j = 1 ;j < size-1; j++){
            int tmp = 0;
            for(int k = 0; k < 8; k++){
                if(matrix[(int)VVector[k].x+i][(int)VVector[k].y+j]){
                    tmp++;
                }
            }
            if(matrix[i][j] ){//生きている時
                if(tmp <= 1 || tmp >= 4 ){
                    tmp_matrix[i][j] = false;
                }else if(tmp == 3 || tmp == 2){
                    tmp_matrix[i][j] = true;
                }
            }else {
                if(tmp == 3 ){
                    tmp_matrix[i][j] = true;
                }
            }
        }
    }
    for(int i = 1 ;i < size-1; i++){
        for(int j = 1 ;j < size-1; j++){
            matrix[i][j] = tmp_matrix[i][j];
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 1 ;i < size-1; i++){
        for(int j = 1 ;j < size-1; j++){
            if(matrix[i][j]){
                ofSetColor(0,255,0,100);
            }else{
                ofSetColor(0,190);
            }
            ofDrawRectangle(10*i, 10*j, 9,9);
            ofSetColor(255,190);
            ofDrawBitmapString(ofToString(matrix[i][j]), 10*i+5, 10*j+5);
        }
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
