#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // 画面の設定
    ofBackground(0);
    ofEnableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ADD);

    // メッシュの幅と高さ
    w = 300;
    h = 300;

    // 頂点の色を初期化
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            mVboMesh.addColor(ofFloatColor(0.5, 0.8, 1.0));
        }
    }

    // 全ての頂点の位置を更新して頂点情報として追加
    mVboMesh.clear();
    for (int i = 0; i < w; i+=2) {
        for (int j = 0; j < h; j+=2) {
            float z = ofSignedNoise(ofGetElapsedTimef(),i,j)*5;
            mVboMesh.addVertex(ofVec3f(i - w/3, z,j - h/3));
            mVboMesh.addColor(ofFloatColor(0,ofSignedNoise(ofGetElapsedTimef(),i,j),0));

        }
    }
    mVboMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    ofSetLineWidth(0.5);
}

//--------------------------------------------------------------
void ofApp::update(){
    // まず全ての頂点情報を削除
    mVboMesh.clearVertices();
    mVboMesh.clearColors();
    for (int i = 0; i < w; i+=4) {
        for (int j = 0; j < h; j+=2) {
            float z = ofSignedNoise(ofGetElapsedTimef(),i,j)*h/100+(i+j)/100;
            mVboMesh.addVertex(ofVec3f(i - w/3, z,j - h/3));
            mVboMesh.addColor(ofFloatColor(0,ofSignedNoise(ofGetElapsedTimef(),i,j)*2,0));
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // メッシュの描画
    ofSetHexColor(0xffffff);

    // 頂点の位置をドットで表示
    glPointSize(0.1);
    glEnable(GL_LINE_WIDTH_RANGE);

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    mEasyCam.begin();

    mVboMesh.drawFaces();

    mEasyCam.end();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_UP){
        tmp = 100;
    }
    if(key == OF_KEY_DOWN){
        tmp = 10;
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
