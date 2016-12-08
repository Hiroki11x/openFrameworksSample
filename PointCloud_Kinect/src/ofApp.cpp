#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //画面設定
    ofBackgroundHex(0x000000);
    ofSetFrameRate(60);
    
    // Kinect初期設定
    // 深度とRGB情報のずれを補整
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
    // 角度を調整(0度に)
    angle = 0;
    kinect.setCameraTiltAngle(angle);

}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();//kinectからのデータを更新
}

//--------------------------------------------------------------
void ofApp::draw(){
    // ドラッグで視線を変更できるように(ofEasyCam)
    easyCam.begin();
    //ポイントクラウドの描画
    drawPointCloud();
    easyCam.end();
}
void ofApp::drawPointCloud() {
    // 画面の幅と高さ
    int w = 640;
    int h = 480;
    // メッシュを生成
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    // 設定した間隔で、画面の深度情報と色を取得してメッシュの頂点に設定
    int step = 2;
    for(int y = 0; y < h; y += step) {
        for(int x = 0; x < w; x += step) {
            if(kinect.getDistanceAt(x, y) > 0) {
                mesh.addColor(kinect.getColorAt(x,y));
                mesh.addVertex(kinect.getWorldCoordinateAt(x, y));
            }
        }
    }
    
    // メッシュの頂点を描画
    glPointSize(2);
    ofPushMatrix();
    ofScale(1, -1, -1);
    ofTranslate(0, 0, -1000);
    glEnable(GL_DEPTH_TEST);
    mesh.drawVertices();
    glDisable(GL_DEPTH_TEST);
    ofPopMatrix();
}

void ofApp::exit() {
    // Kinect終了
    kinect.close();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // 矢印キーでKinectの角度を操作
    switch (key) {
            
        case OF_KEY_UP:
            angle++;
            if(angle>30) angle=30;
            kinect.setCameraTiltAngle(angle);
            break;
            
        case OF_KEY_DOWN:
            angle--;
            if(angle<-30) angle=-30;
            kinect.setCameraTiltAngle(angle);
            break;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
