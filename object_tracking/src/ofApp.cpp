#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    matrix_size = 3000;
    m_box_z = 0;
    z_offset = 0;
    m_box.set(1); // boxのsize(大きさ)を設定
    m_box.setPosition(0, 0, m_box_z);
}

//--------------------------------------------------------------
void ofApp::update(){
    m_box_z += 10; //位置の更新
    m_box_pos.z = m_box_z; //ポジションに位置の更新
    m_box.setPosition(m_box_pos); //ボックス実体にポジションを適用(更新)
    m_box_pos.x = ofSignedNoise(ofGetElapsedTimef()/10,0,0)*500;
    m_box_pos.y = (1+ofSignedNoise(0,ofGetElapsedTimef()/2,0))*50;
    m_box_pos.z = -30+m_box_z-ofSignedNoise(ofGetElapsedTimef())*10;
    m_camera.setPosition(m_box_pos);//カメラの実体にポジションを適用(更新)
    m_box_pos.z += 30;//カメラの見る位置を変更(boxのポジションとは)
    m_camera.lookAt(m_box_pos);

    if(0 > z_offset-m_box_z){//無限にマトリックスを表示するための更新
        z_offset += matrix_size;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    m_camera.begin();

    draw_matrix();//マトリックスの描画

    m_box.drawWireframe();

    m_camera.end();
    ofPopMatrix();
    ofDrawBitmapStringHighlight("m_box_z: "+ofToString(m_box_z), 20, 20);
}

//下のマトリックスの描画
//--------------------------------------------------------------
void ofApp::draw_matrix(){
    ofPushMatrix();
    ofTranslate(0,0, z_offset);
    ofRotateX(-90);

    for(int i = -matrix_size; i<matrix_size; i+=50){
        ofDrawLine(-matrix_size,i,matrix_size,i);
    }
    for(int i = -matrix_size; i<matrix_size; i+=50){
        ofDrawLine(i,-matrix_size,i,matrix_size);
    }

    ofPopMatrix();
}

//任意のシーンの描画
//--------------------------------------------------------------
void ofApp::draw_scene(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '0'){

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
