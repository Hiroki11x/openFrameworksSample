#include "testApp.h"
int pos_y[200];
//--------------------------------------------------------------
void testApp::setup(){
    // 画面の設定
    ofBackground(0);
    ofEnableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ADD);

    cam.setDistance(100);
        
    // メッシュの幅と高さ
    w = 400;
    h = 2000;

    z =10;
    
    // 頂点の色を初期化
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            mesh.addColor(ofFloatColor(0.5, 0.8, 1.0));
        }
    }
    
    // 全ての頂点の位置を更新して頂点情報として追加
    for (int i = 0; i < w; i+=2) {
        for (int j = 0; j < h; j+=2) {
            float z = ofSignedNoise(ofGetElapsedTimef(),i,j)*5;
            
            mesh.addVertex(ofVec3f(i - w/3, j - h/3, z));
            mesh.addColor(ofFloatColor(0,ofSignedNoise(ofGetElapsedTimef(),i,j),0));
            
            
        }
    }
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    ofSetLineWidth(0.5);
}

//--------------------------------------------------------------
void testApp::update(){
//    // まず全ての頂点情報を削除
    mesh.clearVertices();
    mesh.clearColors();
    for (int i = 0; i < w; i+=4) {
        for (int j = 0; j < h; j+=2) {
            float z = ofSignedNoise(ofGetElapsedTimef(),i,j)*h/100;
            
            mesh.addVertex(ofVec3f(i - w/3, j - h/3, z));
            mesh.addColor(ofFloatColor(0,ofSignedNoise(ofGetElapsedTimef(),i,j)*2,0));
            
            
        }
    }
    cam.setPosition(x, y, z);
    cam.lookAt(ofVec3f(100,10000,0));
}

//--------------------------------------------------------------
void testApp::draw(){
    // メッシュの描画
    ofSetHexColor(0xffffff);
    cam.begin(); // カメラ開始
    cam.rotate(90, ofVec3f(0,1,0));
    
    // 頂点の位置をドットで表示
    glPointSize(0.1);
    glEnable(GL_LINE_WIDTH);
    mesh.drawVertices();
    
    cam.end(); // カメラ終了
    
    // ログの表示
    string info;
    info = "Vertex num = " + ofToString(w * h, 0) + "\n";
    info += "FPS = " + ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapString(info, 30, 30);
    ofDrawBitmapString(ofToString(x), 30, 60);
    ofDrawBitmapString(ofToString(y), 30, 80);
    ofDrawBitmapString(ofToString(z), 30, 100);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    // fキーでフルスクリーン表示
    if (key == 'f') {
        ofToggleFullscreen();
    }else if(key=='x'){
        x+=10;
    }else if(key=='y'){
        y+=10;
    }else if(key=='z'){
        z+=5;
    }else if(key=='X'){
        x-=10;
    }
    else if(key=='Y'){
        y-=10;
    }
    else if(key=='Z'){
        z-=5;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}