#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(640, 480); //ウインドウのサイズ

    cam.setDesiredFrameRate(30);
    cam.initGrabber(ofGetWidth(), ofGetHeight());

    for (int i=0; i<2000; i++) {
        //ランダムに2000個頂点を作る
        delaunay.addPoint(ofPoint(ofRandom(0, ofGetWidth()),ofRandom(0, ofGetHeight())));
    }

    //ドロネー三角形分割する
    delaunay.triangulate();
    //できたドロネーメッシュをvboMeshにコピーする
    mesh = delaunay.triangleMesh;
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if (cam.isFrameNew()) {
        ofPixels pixels = cam.getPixelsRef();

        //カメラ映像からmeshの頂点に色を設定していく
        mesh.clearColors();
        for (int i=0; i<mesh.getNumVertices(); i++) {
            ofVec2f p = mesh.getVertex(i);
            ofColor color = pixels.getColor((int)p.x, (int)p.y);
            mesh.addColor(color);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    mesh.draw();
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
