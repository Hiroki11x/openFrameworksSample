#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mPDF.load("sample.pdf");

    /* ofPathは今回使わない
    mPath.setFilled(false);
    mPath.setStrokeWidth(15);
    mPath.setStrokeHexColor(0x0022ff);
    for (int i = 0; i < mPDF.getNumPath(); i++){
        ofPath& path = mPDF.getPathAt(i);
        mPath.append(path);
    }
    mPath.close();
     */

    // PDFのパスを順番に取り出し、細かく分けたやつをpolysVecにpush_backしていく
    for (int i = 0; i < mPDF.getNumPath(); i++){
        ofPath& path = mPDF.getPathAt(i);
        const vector<ofPolyline > &tmpPoly = path.getOutline();
        for (int k = 0; k < tmpPoly.size(); k++){
            polys.push_back(tmpPoly[k]);
            cout << "polysVec.size():" << polys.size() << " /k:" << k <<endl;
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
//    mPath.draw();
    drawAnimation();
}

//--------------------------------------------------------------
void ofApp::drawAnimation(){
    ofPolyline tmpPoly;
    float animation_time = fmodf(ofGetElapsedTimef(), 1) * 4;
    for (int k = 0; k < polys.size(); k++){
        tmpPoly = polys.at(k).getResampledByCount(100);
        int target_size = polys.size() * animation_time;
        tmpPoly.resize(target_size);
        tmpPoly.draw();
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
