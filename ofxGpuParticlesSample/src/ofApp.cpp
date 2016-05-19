#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetFrameRate(60);
    
    // 1,000,000 particles
    unsigned w = 1000;
    unsigned h = 1000;
    particles.init(w, h);
    
    // use new to allocate 4,000,000 floats on the heap rather than
    float* particlePosns = new float[w * h * 4]; //座標の初期化()
    
    // particleの初期座標セット
    for (unsigned y = 0; y < h; ++y){ //y方向
        for (unsigned x = 0; x < w; ++x){ //z方向
            unsigned idx = y * w + x;
            particlePosns[idx * 4] = 400.f * x / (float)w - 200.f; // particle x
            particlePosns[idx * 4 + 1] = 400.f * y / (float)h - 200.f; // particle y
            particlePosns[idx * 4 + 2] = ofRandom(-10,10); // particle z
            particlePosns[idx * 4 + 3] = 0.f; // dummy
        }
    }
    particles.loadDataTexture(ofxGpuParticles::POSITION, particlePosns);// 座標初期化した配列をparticleにセット
    delete[] particlePosns; //確保してたアドレス解放
    particles.zeroDataTexture(ofxGpuParticles::VELOCITY); // 速度ベクトルを初期化
    ofAddListener(particles.updateEvent, this, &ofApp::onParticlesUpdate); // onParticlesUpdateを呼ぶためにlistenerをセット
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate(), 2));
    particles.update();
}

void ofApp::onParticlesUpdate(ofShader& shader){
    ofVec3f mouse(ofGetMouseX() - ofGetWidth()/2,ofGetHeight()/2 - ofGetMouseY() , 0.0f);
    mouse *= 0.2;
    
    shader.setUniform3fv("mouse", mouse.getPtr());
    shader.setUniform1f("elapsed", ofGetLastFrameTime());
    shader.setUniform1f("radiusSquared", 500.f * 500.f);
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    ofSetColor(100,100);
    ofDrawRectangle(-ofGetWidth(), -ofGetHeight(), ofGetWidth()*2, ofGetHeight()*2);
    particles.draw();
    cam.end();
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
