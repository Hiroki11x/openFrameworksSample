//
//  PlaneScene.cpp
//  ofxDelaunayCvSample
//
//  Created by HirokiNaganuma on 2016/05/19.
//
//

#include "PlaneScene.hpp"


//--------------------------------------------------------------
void PlaneScene::setup(){
    ofSetWindowShape(1280, 800); //„Ç¶„Ç§„É≥„Éâ„Ç¶„ÅÆ„Çµ„Ç§„Ç∫

    cam.setDesiredFrameRate(30);
    cam.initGrabber(ofGetWidth(), ofGetHeight());

    for (int i=0; i<2000; i++) {
        //„É©„É≥„ÉÄ„É†„Å´2000ÂÄãÈ†ÇÁÇπ„Çí‰Ωú„Çã
        delaunay.addPoint(ofPoint(ofRandom(0, ofGetWidth()),ofRandom(0, ofGetHeight())));
    }

    //„Éâ„É≠„Éç„Éº‰∏âËßíÂΩ¢ÂàÜÂâ≤„Åô„Çã
    delaunay.triangulate();
    //„Åß„Åç„Åü„Éâ„É≠„Éç„Éº„É°„ÉÉ„Ç∑„É•„ÇívboMesh„Å´„Ç≥„Éî„Éº„Åô„Çã
    mesh = delaunay.triangleMesh;
}

//--------------------------------------------------------------
void PlaneScene::update(){
    cam.update();
    if (cam.isFrameNew()) {
        ofPixels pixels = cam.getPixelsRef();

        //„Ç´„É°„É©Êò†ÂÉè„Åã„Çâmesh„ÅÆÈ†ÇÁÇπ„Å´Ëâ≤„ÇíË®≠ÂÆö„Åó„Å¶„ÅÑ„Åè
        mesh.clearColors();
        for (int i=0; i<mesh.getNumVertices(); i++) {
            ofVec2f p = mesh.getVertex(i);
            ofColor color = pixels.getColor((int)p.x, (int)p.y);
            mesh.addColor(color);
        }
    }
}

//--------------------------------------------------------------
void PlaneScene::draw(){
    ofSetColor(0);
    mesh.draw();
}

//--------------------------------------------------------------
void PlaneScene::keyPressed(int key){

}

//--------------------------------------------------------------
void PlaneScene::keyReleased(int key){

}

//--------------------------------------------------------------
void PlaneScene::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void PlaneScene::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void PlaneScene::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void PlaneScene::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void PlaneScene::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void PlaneScene::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void PlaneScene::windowResized(int w, int h){

}

//--------------------------------------------------------------
void PlaneScene::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void PlaneScene::dragEvent(ofDragInfo dragInfo){ 
    
}
