//
//  ExtendedCvScene.cpp
//  ofxDelaunaySample
//
//  Created by HirokiNaganuma on 2016/05/19.
//
//

#include "ExtendedCvScene.hpp"


//--------------------------------------------------------------
void ExtendedCvScene::setup(){
    ofSetWindowShape(1280, 800); //ウインドウのサイズ

    cam.setDesiredFrameRate(30);
    cam.initGrabber(ofGetWidth(), ofGetHeight());

    w = ofGetWidth();
    h = ofGetHeight();

    grayImage.allocate(w, h);
    edgeImage.allocate(w, h);
}

//--------------------------------------------------------------
void ExtendedCvScene::update(){
    cam.update();
    if (cam.isFrameNew()) {
        //リセット
        delaunay.reset();
        mesh.clear();

        /*Cannyの部分*********************************************************************/
        colorImage.setFromPixels(cam.getPixels(), w, h);
        grayImage = colorImage;
        grayImage.blur();
        cvCanny(grayImage.getCvImage(), edgeImage.getCvImage(), 20, 100);//Canny Filter
        edgeImage.flagImageChanged();
        edgeImage.dilate();
        unsigned char *edgeData = edgeImage.getPixels();

        //輪郭線を間引いて頂点として扱う
        int up = 80;
        for (int i=0; i<w*h; i+=up) {
            if (edgeData[i] == 0){ continue;}
            else{
                int coordY = floor(i/w);
                delaunay.addPoint(ofVec2f(i-w*coordY, coordY));
            }
        }
        /********************************************************************************/
        //ランダムな点を増やす
        for (int i=0; i<200; i++) {
            delaunay.addPoint(ofPoint(ofRandom(0, ofGetWidth()),ofRandom(0, ofGetHeight())));
        }
        //四隅の点
        delaunay.addPoint(ofPoint(0,0));
        delaunay.addPoint(ofPoint(0,ofGetHeight()));
        delaunay.addPoint(ofPoint(ofGetWidth(),ofGetHeight()));
        delaunay.addPoint(ofPoint(ofGetWidth(),0));
        delaunay.triangulate();

        /*ポリゴンの中心の色を使う*/
        ofPixels pixels = cam.getPixelsRef();
        for (int i=0; i<delaunay.triangleMesh.getNumIndices()/3; i++) {
            int idx1 = delaunay.triangleMesh.getIndex(i*3);
            int idx2 = delaunay.triangleMesh.getIndex(i*3+1);
            int idx3 = delaunay.triangleMesh.getIndex(i*3+2);

            ofVec2f v1 = delaunay.triangleMesh.getVertex(idx1);
            ofVec2f v2 = delaunay.triangleMesh.getVertex(idx2);
            ofVec2f v3 = delaunay.triangleMesh.getVertex(idx3);

            ofVec2f gp = (v1+v2+v3)/3.0;

            ofColor color = pixels.getColor((int)gp.x, (int)gp.y);

            mesh.addVertex(v1);
            mesh.addVertex(v2);
            mesh.addVertex(v3);

            mesh.addColor(color);
            mesh.addColor(color);
            mesh.addColor(color);

        }
    }
}

//--------------------------------------------------------------
void ExtendedCvScene::draw(){
    ofFill();
    ofSetColor(255);
    mesh.draw();
}

//--------------------------------------------------------------
void ExtendedCvScene::keyPressed(int key){

}

//--------------------------------------------------------------
void ExtendedCvScene::keyReleased(int key){

}

//--------------------------------------------------------------
void ExtendedCvScene::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ExtendedCvScene::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ExtendedCvScene::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ExtendedCvScene::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ExtendedCvScene::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ExtendedCvScene::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ExtendedCvScene::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ExtendedCvScene::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ExtendedCvScene::dragEvent(ofDragInfo dragInfo){ 
    
}
