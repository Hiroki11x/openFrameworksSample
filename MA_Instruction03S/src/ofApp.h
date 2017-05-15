#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "127.0.0.1" // 受信側のIPアドレス(これは自分のIPアドレスのこと/localhostと書いてもOK)
#define PORT 8000 // 受信側のポート番号

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    //OSCメッセージの送信者
    ofxOscSender sender;
    ofxOscReceiver receiver;
    
    ofPoint packPosition;
    ofVec2f packSpeed;
    bool packHere;
};
/*
 Open Sound Control (OSC) は、コンピュータやシンセサイザーや、
 その他のマルチメディアデバイス同士でコミュニケーションするための通信プロトコルです。
 現代のネットワーク技術の成果を電子楽器の世界に適用することで、
 OSCは、相互運用性、正確さ、柔軟さ、また、拡張性に優れた性能を持ちます。
 ポストMIDIを目指すインターネットのプロトコルの仕組みを、
 音楽やマルチメディアの世界へ適用 (UDP/IPを利用)多くの機器、言語、
 アプリケーションに実装済みオープンでシンプルな命名規則 ← URLの仕組みに似ている
 */

