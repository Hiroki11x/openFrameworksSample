#include "ofApp.h"

template<class T> void ofApp::shuffle(T array[],int size){
    for(int i=0;i<size;i++){
        int j = rand()%size;
        T t = array[i];
        array[i] = array[j];
        array[j] = t;
    }
}


//--------------------------------------------------------------
void ofApp::setup(){
    members[0].name = "Okakan";
    members[0].image.load("okakan.jpg");

    members[1].name = "Hyou-chan";
    members[1].image.load("hyouchan.jpg");

    members[2].name = "Hocchan";
    members[2].image.load("hocchan.jpg");

    members[3].name = "Kannon";
    members[3].image.load("kanon.jpg");

    members[4].name = "Kaito";
    members[4].image.load("kaito.jpg");

    members[5].name= "Takers";
    members[5].image.load("takers.jpg");

    members[6].name = "Eiichi";
    members[6].image.load("eiichi.jpg");

    members[7].name = "Youhei";
    members[7].image.load("youhei.jpg");


    shuffle(members, 8);

    index = -1;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0 ; i<=index ; i++){
        ofDrawBitmapStringHighlight(ofToString(members[i].name),(i%4)*ofGetWidth()/4, (i/4)*ofGetHeight()/2+50);
        
        members[i].image.draw( (i%4)*ofGetWidth()/4,
                              (i/4)*ofGetHeight()/2+80,members[i].image.getWidth()/4,members[i].image.getHeight()/4);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_RETURN){
        index= (index+1)%8;
        
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
