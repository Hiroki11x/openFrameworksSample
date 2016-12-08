#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sound[0].loadSound("do.mp3");
    sound[1].loadSound("le.mp3");
    sound[2].loadSound("mi.mp3");
    sound[3].loadSound("fa.mp3");
    sound[4].loadSound("so.mp3");
    sound[5].loadSound("la.mp3");
    sound[6].loadSound("si.mp3");
    sound[7].loadSound("doh.mp3");
    for(int i =0;i<8;i++){
        size[i]=100;
        color[i].set(255,255,255);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    for(int i =0;i<4;i++){
        
        ofSetColor(color[i*2]);
        ofDrawBitmapString("box no: "+ofToString(i*2),100+i*200,180);
        ofRect(100+i*200,200,size[i*2],size[i*2]);
        
        ofSetColor(color[i*2+1]);
        ofDrawBitmapString("box no: "+ofToString(i*2+1),100+i*200,480);
        ofRect(100+i*200,500,size[i*2+1],size[i*2+1]);
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //keyのasciiコードをconsole outする9
    cout<<key<<endl;
    //ここで渡されるkeyはasciiコードで渡される。
    if(key>=48 && key<=55){
        sound[key-48].play();
        size[key-48] = ofRandom(100);
        color[key-48].set(255,0,0);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key>=48 && key<=55){
        size[key-48] = 100;
        color[key-48].set(0, 255, 0);
    }
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
