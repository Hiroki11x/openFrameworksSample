#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    backgroundauto_frag = true;
    ofSetBackgroundAuto(backgroundauto_frag);
}

//--------------------------------------------------------------
void ofApp::update(){
    pos = ofVec2f(mouseX,mouseY);

    if(ofDist(past_pos.x, past_pos.y, pos.x, pos.y)>50){

        start_time = ofGetElapsedTimef();
        backgroundauto_frag=false;
        ofSetBackgroundAuto(backgroundauto_frag);

        for(int i = 0;i<5;i++){
            particles.push_back(new Particle());
            particles.back()->init();
            particles.back()->setPosition(pos);
            particles.back()->setSpeed((pos-past_pos)/2);
        }
    }

    past_pos = pos;

    //Particleの自然消滅を促す
    for(int i = 0; i<particles.size();i++){
        particles.at(i)->update();
        if(particles.at(i)->isEntire()){
            particles.erase(particles.begin() + i);
        }
    }

    if(!backgroundauto_frag && ofGetElapsedTimef()-start_time > 1){
        ofBackground(0);
        backgroundauto_frag=true;
        ofSetBackgroundAuto(backgroundauto_frag);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofDrawBitmapStringHighlight("Num of Particle: "+ofToString(particles.size()), 20,20);
    ofSetColor(255);
    for(int i = 0; i<particles.size();i++){
        particles.at(i)->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_RETURN){
        for(int i = 0;i<5;i++){
            particles.push_back(new Particle());
            particles.back()->init();
            particles.back()->setPosition(pos);
            particles.back()->setSpeed((pos-past_pos)/2);
        }
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
