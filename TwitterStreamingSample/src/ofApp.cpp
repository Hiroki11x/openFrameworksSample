#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    twitterStreamingManager.setup();
    FontManager::init();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle("FPS: " + ofToString(ofGetFrameRate()) +"/  num of element: "+ofToString(TweetJsonReceiver::data_num));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2-300, ofGetHeight()/2);
    if(TweetJsonReceiver::tweetData.size()>0){
        TweetJsonReceiver::tweetData.back().image.draw(-100,-100,200,200);
        FontManager::drawSmallString("@"+ofToString(TweetJsonReceiver::tweetData.back().twitter_id),150,-60);
        FontManager::drawSmallWString(TweetJsonReceiver::tweetData.back().user_name,150,-40);
        FontManager::drawSmallString("followers_count: "+ofToString(TweetJsonReceiver::tweetData.back().followers_count),150,-20);
        FontManager::drawSmallString("friends_count: "+ofToString(TweetJsonReceiver::tweetData.back().friends_count),150,0);
        FontManager::drawSmallWString(TweetJsonReceiver::tweetData.back().tweet_text,150,20);
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::exit() {
    twitterStreamingManager.exit();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
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
