#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0, 0, 0);

    // 指定したIPアドレスとポート番号でサーバーに接続
    //OSCメッセージの送信者 ofxOscSender sender;
	sender.setup("10.1.2.19",PORT);
    receiver.setup(PORT);
    //#define HOST "127.0.0.1" // 受信側のIPアドレス
    //#define PORT 8000 // 受信側のポート番号
    
    //初期packがある方をtrueに
    packHere = true;
    packPosition = ofPoint(100,100);
    packSpeed = ofVec2f(0,0);
}

void ofApp::update(){
    
    if(pow(abs(mouseY - packPosition.y),2) + pow(abs(mouseX - packPosition.x),2) < 100){
        //packに当てた時の速度を調整の必要あり
        packSpeed = ofVec2f(ofRandom(-5,5),-7);
    }
    if(packHere){
        packPosition += packSpeed;
        
        if(packPosition.y < 0){
            packHere = false;
            ofxOscMessage message;
            message.setAddress("/packSend");
            message.addFloatArg(-packSpeed.x);
            message.addFloatArg(-packSpeed.y);
            message.addFloatArg(ofGetWidth() - packPosition.x);
            
            sender.sendMessage(message);
        }
        
        if(packPosition.y > ofGetHeight() - 10){
            packSpeed.y *= -1;
        }
        
        if(packPosition.x < 10 || packPosition.x > ofGetWidth() -10 ){
            packSpeed.x *= -1;
        }
        
    }else{
        while(receiver.hasWaitingMessages()){
            ofxOscMessage recievedMessage;
            receiver.getNextMessage(&recievedMessage);
        
            packHere = true;
            packSpeed.x = recievedMessage.getArgAsFloat(0);
            packSpeed.y = recievedMessage.getArgAsFloat(1);
            packPosition = ofPoint(recievedMessage.getArgAsFloat(2),1);
        }
    }
}

void ofApp::draw(){
    //現在のマウスの場所に円を描画
    ofSetColor(255, 255, 255);
    ofCircle(mouseX, mouseY, 10);
    if(packHere){
        ofCircle(packPosition, 20);
    }
}

//マウスを座標(480, 240)に動かした場合
//‣/mouse/position 480 240
void ofApp::mouseMoved(int x, int y){
	/*ofxOscMessage m;//OSCメッセージの準備
	m.setAddress("/mouse/position");//OSCアドレスの指定
	m.addIntArg(x);//OSC引数として、現在のマウスの座標(x, y)を送信
	m.addIntArg(y);
	sender.sendMessage(m);//メッセージを送信*/
}

void ofApp::mouseDragged(int x, int y, int button){
	/*ofxOscMessage m;//OSCメッセージの準備
	m.setAddress("/mouse/position");//OSCアドレスの指定
	m.addIntArg(x);//OSC引数として、現在のマウスの座標(x, y)を送信
	m.addIntArg(y);
	sender.sendMessage(m);//メッセージを送信*/
}

//マウスボタンを押した瞬間
//‣ /mouse/button “down”
void ofApp::mousePressed(int x, int y, int button){
	/*ofxOscMessage m;//OSCメッセージの準備
	m.setAddress("/mouse/button");//OSCアドレスの指定
	m.addStringArg("down");//OSC引数として、マウス状態"down"を送信
	sender.sendMessage(m); //メッセージを送信*/
}

void ofApp::mouseReleased(int x, int y, int button){
    
	/*ofxOscMessage m;//OSCメッセージの準備
	m.setAddress("/mouse/button");//OSCアドレスの指定
	m.addStringArg("up");//OSC引数として、マウス状態"up"を送信
	sender.sendMessage( m );//メッセージを送信*/
}