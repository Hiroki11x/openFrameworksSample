#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetLogLevel(OF_LOG_VERBOSE);

    leap.open();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);

    cam.setOrientation(ofPoint(20, 0, 0));

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    ImageManager::loadImages();
}

//--------------------------------------------------------------
void ofApp::update(){
    fingersFound.clear();
    simpleHands = leap.getSimpleHands();//simpleHandsはベクター
    if( leap.isFrameNew() && simpleHands.size() ){//LeapMotionのフレームが更新されるかつ、ひとつ以上の手が検出されたとき

        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
        leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);

        fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};

        for(int i = 0; i < simpleHands.size(); i++){
            for (int f=0; f<5; f++) {
                int id = simpleHands[i].fingers[ fingerTypes[f] ].id;
                ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp; // metacarpal
                ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip; // proximal
                ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip; // distal
                ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip; // fingertip
                fingersFound.push_back(id);
            }
        }
    }
    leap.markFrameAsOld();
    ofSetWindowTitle("Num of Hands: "+ofToString(simpleHands.size()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(255), ofColor(200),  OF_GRADIENT_BAR);
    cam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2,-ofGetHeight()/2);
    ImageManager::drawImages();
    ofPopMatrix();


    ofSetColor(200);
    ofDrawBitmapString("ofxLeapMotion - Example App\nLeap Connected? " + ofToString(leap.isConnected()), 20, 20);


    fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};

    for(int i = 0; i < simpleHands.size(); i++){//手の数だけfor文を回す
        bool isLeft        = simpleHands[i].isLeft;
        ofPoint handPos    = simpleHands[i].handPos;
        hand[i]=handPos;
        ofPoint handNormal = simpleHands[i].handNormal;

        ofSetColor(0,200);
        
        for (int f=0; f<5; f++) {//手の関節を描画するためのfor文
            ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp;  // metacarpal
            ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip;  // proximal
            ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip;  // distal
            ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip;  // fingertip

            //手の関節を描画
            ofSetColor(120, 200);//手の関節の色
            ofDrawSphere(mcp.x, mcp.y, mcp.z, 15);
            ofDrawSphere(pip.x, pip.y, pip.z, 15);
            ofDrawSphere(dip.x, dip.y, dip.z, 15);
            ofDrawSphere(tip.x, tip.y, tip.z, 15);

            //手の骨を描画
            ofSetColor(150,200);//手の骨の色
            ofSetLineWidth(10);
            ofDrawLine(mcp.x, mcp.y, mcp.z, pip.x, pip.y, pip.z);
            ofDrawLine(pip.x, pip.y, pip.z, dip.x, dip.y, dip.z);
            ofDrawLine(dip.x, dip.y, dip.z, tip.x, tip.y, tip.z);
        }//手の関節を描画するためのfor文
    }//手の数だけfor文を回す

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
