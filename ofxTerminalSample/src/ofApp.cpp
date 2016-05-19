#include "ofApp.h"
/**
 * Sample Dataは適当なデータなのでほとんど読む必要なし
 * 適当なデータ.draw(int x,int y)で文字列描画してるだけ
 * Scroll 文字列の座標決めはManagerでしてます
 */

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    sampledatamanager.init();
}

//--------------------------------------------------------------
void ofApp::update(){
    sampledatamanager.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    sampledatamanager.draw();
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
