#pragma once

#include "ofMain.h"

#include "ofxLeapMotion2.h"//ofxLeapMotion2をインクルード

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void exit();//アプリケーション終了時に呼び出される
		
    ofxLeapMotion leap;//LeapMotionのメインクラスをインスタンス化
    vector <ofxLeapMotionSimpleHand> simpleHands;//シンプルな手のモデルのvector配列
    
    ofEasyCam cam;//EasyCamのインスタンス
    
    vector <ofVec3f> fingerPos;//指や関節の位置を保存するvector配列
    
    vector <ofPoint> handPos;//手の中心座標を保存するvector配列
    
    ofLight light;
    
};
