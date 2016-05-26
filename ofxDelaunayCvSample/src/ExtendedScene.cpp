//
//  ExtendedScene.cpp
//  ofxDelaunayCvSample
//
//  Created by HirokiNaganuma on 2016/05/26.
//
//

#include "ExtendedScene.hpp"

void ExtendedScene::setup(){
    ofSetWindowShape(1920, 1080); //ウインドウのサイズ

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

void ExtendedScene::update(){
    cam.update();
    if (cam.isFrameNew()) {
        ofPixels pixels = cam.getPixelsRef();

        //ドロネーをリセット
        delaunay.reset();

        /*ドロネー三角形分割*/
        for (int i=0; i<1000; i++) {
            delaunay.addPoint(ofPoint(ofRandom(0, ofGetWidth()),ofRandom(0, ofGetHeight())));
        }
        //四隅にも点を加えとく
        delaunay.addPoint(ofPoint(0,0));
        delaunay.addPoint(ofPoint(0,ofGetHeight()));
        delaunay.addPoint(ofPoint(ofGetWidth(),ofGetHeight()));
        delaunay.addPoint(ofPoint(ofGetWidth(),0));
        delaunay.triangulate();

        //メッシュの中身をクリア
        mesh.clear();
        for (int i=0; i<delaunay.triangleMesh.getNumIndices()/3; i++) {
            int idx1 = delaunay.triangleMesh.getIndex(i*3);
            int idx2 = delaunay.triangleMesh.getIndex(i*3+1);
            int idx3 = delaunay.triangleMesh.getIndex(i*3+2);

            ofVec2f v1 = delaunay.triangleMesh.getVertex(idx1);
            ofVec2f v2 = delaunay.triangleMesh.getVertex(idx2);
            ofVec2f v3 = delaunay.triangleMesh.getVertex(idx3);

            //重心の色を使う
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

void ExtendedScene::draw(){
    ofSetColor(0);
    mesh.draw();
}