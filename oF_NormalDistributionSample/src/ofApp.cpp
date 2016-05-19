#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


    //Normal Distribution /std::reserve: 31033msec /without reserve -> 32646msec
    using my_engine = mt19937;
    using my_distribution = normal_distribution<>;
    my_engine mEngine {};
    my_distribution mDistribution {0.0,10.0};// 平均0.0、標準偏差10.0で分布させる

    const auto t1 = std::chrono::high_resolution_clock::now();
    position_vector_3d.reserve(100000);
    for(int i = 0 ; i<100000 ; i++){
        float  x = round(mDistribution(mEngine));
        float y = round(mDistribution(mEngine));
        float z = round(mDistribution(mEngine));
        position_vector_3d.push_back(ofVec3f(x,y,z));
    }

    const auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count() << "msec" << std::endl;
    ofBackground(0);
    cam_dist = 600;


    //Normal Distribution /std::generate:32868msec
    /*
     using my_engine = mt19937;
     using my_distribution = normal_distribution<>;
     my_engine mEngine {};
     my_distribution mDistribution {0.0,10.0};// 平均0.0、標準偏差10.0で分布させる

    const auto t1 = std::chrono::high_resolution_clock::now();
    const auto size = position_vector_3d.size();
    position_vector_3d.resize(size + 100000);
    std::generate(position_vector_3d.begin()+ size, position_vector_3d.end(),[&mDistribution, &mEngine](){ return ofVec3f(mDistribution(mEngine),mDistribution(mEngine),mDistribution(mEngine));});
    const auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count() << "msec" << std::endl;
    ofBackground(0);
    cam_dist = 600;
     */
}


//--------------------------------------------------------------
void ofApp::update(){
//    cam.setPosition(0, 0, cam_dist);
}

//--------------------------------------------------------------
void ofApp::draw(){

//    ofNoFill();
    ofSetColor(0,200,255,20);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);

    cam.begin();

//    for(auto v :position_vector_2d){
//        ofDrawCircle(v.x*10 ,v.y*10 ,5);
//    }

    for(auto v :position_vector_3d){
        ofDrawBox(v.x*10 ,v.y*10 ,v.z*10 ,5);
    }

    cam.end();

    ofPopMatrix();
    ofDrawBitmapStringHighlight("cam_dist: "+ofToString(cam_dist), 20,20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_UP){
        cam_dist += 10;
    }else if(key ==OF_KEY_DOWN){
        cam_dist-= 10;
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
