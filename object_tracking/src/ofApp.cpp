#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    scene_frag = -1;
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
        scene_frag++;
    }

    update_scene();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    m_camera.begin();

    draw_matrix();//マトリックスの描画

    m_box.drawWireframe();
    draw_scene();

    m_camera.end();
    ofPopMatrix();
    ofDrawBitmapStringHighlight("m_box_z: "+ofToString(m_box_z), 20, 20);
    ofDrawBitmapStringHighlight("scene_frag: "+ofToString(scene_frag), 20, 40);
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

//--------------------------------------------------------------
void ofApp::update_scene(){
    switch (scene_frag) {
        case 0:
            update_scene_A();
            break;
        case 1:
            update_scene_B();
            break;
        case 2:
            update_scene_C();
            break;
        case 3:
            update_scene_D();
            break;
        case 4:
            update_scene_E();
            break;

        default:
            break;
    }
}

//任意のシーンの描画
//--------------------------------------------------------------
void ofApp::draw_scene(){
    ofPushMatrix();
    ofTranslate(m_box.getPosition());
    switch (scene_frag) {
        case 0:
            draw_scene_A();
            break;
        case 1:
            draw_scene_B();
            break;
        case 2:
            draw_scene_C();
            break;
        case 3:
            draw_scene_D();
            break;
        case 4:
            draw_scene_E();
            break;

        default:
            break;
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::draw_scene_A(){
    //何か描画
    ofDrawAxis(100);
}

//--------------------------------------------------------------
void ofApp::draw_scene_B(){
    //何か描画
    ofDrawCircle(0, 0, 10);
}

//--------------------------------------------------------------
void ofApp::draw_scene_C(){
    //何か描画
    ofDrawCylinder(10, 5);
}

//--------------------------------------------------------------
void ofApp::draw_scene_D(){
    //何か描画
    ofPushStyle();
    ofNoFill();
    ofVec2f tmp_pos_start;
    ofVec2f tmp_pos_end;
    for(int i = 0; i<100;i++){
        tmp_pos_start = ofVec2f(ofSignedNoise(i,ofGetElapsedTimef()/2),ofSignedNoise(i,ofGetFrameNum()));
        tmp_pos_start.x*=ofGetWidth();
        tmp_pos_start.y*=ofGetHeight();
        tmp_pos_end = ofVec2f(ofSignedNoise(ofGetFrameNum()/2,i),ofSignedNoise(ofGetElapsedTimef(),i));
        tmp_pos_end.x*=ofGetWidth();
        tmp_pos_end.y*=ofGetHeight();
        ofDrawBezier(tmp_pos_start.x,tmp_pos_start.y,
                     tmp_pos_end.x/2,tmp_pos_end.y/2,
                     tmp_pos_start.x/2,tmp_pos_start.y/2,
                     tmp_pos_end.x,tmp_pos_start.x/2);
    }
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::draw_scene_E(){
    //何か描画
    ofVec2f tmp_pos;
    ofPushStyle();
    ofNoFill();
    ofBeginShape();
    for(int i = 0; i<100;i++){
        tmp_pos = ofVec2f(ofSignedNoise(ofGetElapsedTimef()/2,i),ofSignedNoise(i,ofGetFrameNum()/2));
        tmp_pos.x*=ofGetWidth();
        tmp_pos.y*=ofGetHeight();
        ofVertex(tmp_pos.x,tmp_pos.y);
    }
    ofEndShape();
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::update_scene_A(){
}

//--------------------------------------------------------------
void ofApp::update_scene_B(){
}

//--------------------------------------------------------------
void ofApp::update_scene_C(){
}

//--------------------------------------------------------------
void ofApp::update_scene_D(){
}

//--------------------------------------------------------------
void ofApp::update_scene_E(){
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '0'){
        scene_frag++;
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
