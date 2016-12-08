#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //画面の初期設定
    ofSetVerticalSync(true);
    
    //カメラの初期設定
    cam.setOrientation(ofPoint(-20, 0, 0));
    
    //GL設定
    glEnable(GL_DEPTH_TEST);//深さを有効に
    glEnable(GL_NORMALIZE);//法線ベクトルの自動正規化
    
    //Leap Motion開始
    leap.open();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    simpleHands = leap.getSimpleHands();//検出された手の数だけ、ofxLeapMotionSimpleHandのvector配列に追加
    if( leap.isFrameNew() && simpleHands.size() ){// フレーム更新して、手が検出されたら
        
        fingerPos.clear();//今保存されている指の位置をクリア
        
        handPos.clear();//今保存されている手の中心の位置座標をクリア
        
        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);//画面の大きさにあわせて、スケールをマッピング
        leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);
        
        fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
        
        for(int i = 0; i < simpleHands.size(); i++){// 検出された手の数だけくりかえし
            
            handPos.push_back(simpleHands[i].handPos);//手の中心座標をvector配列に追加(これは手の数だけ行われます)
            
            for (int f=0; f<5; f++) {//手の関節を描画するためのfor文
                ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp;  // metacarpal(手の最も中心側)
                fingerPos.push_back(mcp);//fingerPos vector配列に追加
                
                ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip;  // proximal(手の二番目に中心側)
                fingerPos.push_back(pip);//fingerPos vector配列に追加
                
                ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip;  // distal(手の指先の一歩手前)
                fingerPos.push_back(dip);//fingerPos vector配列に追加
                
                ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip;  // fingertip(手の指先)
                fingerPos.push_back(tip);//fingerPos vector配列に追加
            }
        }
    }
    leap.markFrameAsOld();// ofxLeapMotionに現在のフレームは古くなったことを通知
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    light.enable();
    cam.begin();
    for(int i = 0; i < simpleHands.size(); i++){//手の数だけfor文を回す
 
        ofSetColor(0,255,0);//手の中心を緑色にセット
        ofDrawSphere(handPos.at(i), 20);//手の中心座標に球を描画
        
        for (int f=0; f<5; f++) {//手の関節を描画するためのfor文
            ofSetColor(255);
            ofDrawSphere(fingerPos.at(20*i+4*f+0), 10);//mcp(手の最も中心側)
            
            ofSetColor(200);
            ofDrawSphere(fingerPos.at(20*i+4*f+1), 10);//pip(手の二番目に中心側)
            
            ofSetColor(155);
            ofDrawSphere(fingerPos.at(20*i+4*f+2), 10);//dip(手の指先の一歩手前)
            
            ofSetColor(100);
            ofDrawSphere(fingerPos.at(20*i+4*f+3), 10);//tip(手の指先)
            
            ofLine(fingerPos.at(20*i+4*f+0),fingerPos.at(20*i+4*f+1));
            ofLine(fingerPos.at(20*i+4*f+1),fingerPos.at(20*i+4*f+2));
            ofLine(fingerPos.at(20*i+4*f+2),fingerPos.at(20*i+4*f+3));
        }
        
    }
    if(simpleHands.size()==2){
        float distance = sqrt(pow(handPos.at(0).x-handPos.at(1).x,2)
                              +pow(handPos.at(0).y-handPos.at(1).y,2)
                              +pow(handPos.at(0).z-handPos.at(1).z,2));
        
        ofSetColor(227,100);
        ofDrawSphere((handPos.at(0).x+handPos.at(1).x)/2,
                     (handPos.at(0).y+handPos.at(1).y)/2,
                     (handPos.at(0).z+handPos.at(1).z)/2,
                     distance/2);
    
    }
    cam.end();
    light.disable();
    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::exit(){
    leap.close();//インスタンスを終了させる。
}
