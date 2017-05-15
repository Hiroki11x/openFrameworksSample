#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    startpos = ofVec2f(0,500);
    gen_stage = 0;
    treenodes.push_back(TreeNode(gen_stage, startpos, 0));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    for(auto node : treenodes){
        ofDrawCircle(node.pos, 5);
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        gen_stage ++ ;
        for(int i = 0; i < (int)pow(2,gen_stage); i++){
            int index = treenodes.size();
            ofVec2f pos = treenodes.at(int(index-1)/2).pos;
            treenodes.push_back(TreeNode(gen_stage, pos, gen_stage * radius_offset[i%num_of_gen_multi]));
        }

    }
}


/*

|0|1 |                        0
|1|2 |            1                        2
|2|4 |      3           4            5            6
|3|8 |   7     8     9     10    11    12    13    14
|4|16| 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

 */

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
