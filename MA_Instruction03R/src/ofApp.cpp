#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0, 0, 0);
    
    //指定したポートで接続
    receiver.setup(PORT);//OSCメッセージを受信するインスタンス ofxOscReceiver receiver;
    // OSCを受信するポート番号を設定 #define PORT 8000

    mouseX = 0;//値を初期化
    mouseY = 0;
    mouseButtonState = "";//受信したマウスボタンの状態
}

void ofApp::update(){
    
    while(receiver.hasWaitingMessages()){// 現在順番待ちのOSCメッセージがある間は受信を続ける
        
        ofxOscMessage m;//次のメッセージを取得
        receiver.getNextMessage(&m);//mのアドレスが引数
        
        if (m.getAddress() == "/mouse/position"){// メッセージが /mouse/position ならマウスの位置を取得
            remoteMouse.x = m.getArgAsInt32(0);// 受信したマウス座標ofPoint(引数の0番目の32bitのintを取得)
            remoteMouse.y = m.getArgAsInt32(1);// 受信したマウス座標ofPoint(引数の0番目の32bitのintを取得)
        
        }else if (m.getAddress() == "/mouse/button"){// メッセージが /mouse/button ならマウスボタンの状態を取得
            mouseButtonState = m.getArgAsString(0);
        }
    }
}

void ofApp::draw(){
    int radius;

    // マウスボタンが押されていたら、赤い円を描画
    if (mouseButtonState == "down") {
        radius = ofRandom(20,50);
        ofSetColor(255, 127, 0);
    } else {// そうでなければ、青い円を描画
        radius = 10;
        ofSetColor(0, 127, 255);
    }
    ofCircle(remoteMouse.x, remoteMouse.y, radius);
}


