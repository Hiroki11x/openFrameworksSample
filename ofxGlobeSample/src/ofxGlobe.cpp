//
//  ofxGlobe.cpp
//  ofxGlobeSample
//
//  Created by HirokiNaganuma on 2016/03/19.
//
//

#include "ofxGlobe.hpp"

void ofxGlobe::init(){
    ofVec3f tmpPoint;
//    csv.loadFile(ofToDataPath("file.csv"));
    mMesh.clear();
    mMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    mMesh.clearColors();
    radius = 300;
    for(float rad = 0.0f; rad < 2*PI ; rad +=0.03f){
        for(float theta = 0.0f ; theta < 2*PI ; theta +=0.03f){
            tmpPoint = ofVec3f(radius * cos(theta) * cos (rad) , radius * sin(theta) * cos (rad) ,radius * sin(rad) );
            
            if(ofRandom(100)<95){
                mMesh.addVertex(tmpPoint);
            }else{
                tmpPoint *= 1.2;
                mMesh.addVertex(tmpPoint);
            }
        }
    }
    /*
     * x = radius * cos(theta) * cos (rad)
     * y = radius * sin(theta) * cos (rad)
     * z = radius * sin(rad)
     */
}
void ofxGlobe::update(){
    //    mMesh.
}
void ofxGlobe::draw(){
    mMesh.drawVertices();
}