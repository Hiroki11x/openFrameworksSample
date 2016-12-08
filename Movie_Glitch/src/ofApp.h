#pragma once

#include "ofMain.h"
#include "ofxPostGlitch.h"


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
    
    ofImage			lenna;
    bool			bDrawLenna;
    bool			bShowHelp;
    
    ofFbo			myFbo;
    
    ofTexture		texture;
    
    const int WIDTH = 1280;
    const int HEIGHT = 720;
    
    /*Addon instance*/
    //ofxPostGlitch
    ofxPostGlitch	myGlitch;
    
    int shaderIndex;
    bool shaderSwitch;
    
    /*movie*/
    ofVideoPlayer movie;

    /*audio*/
    int GetPrecision = 1;
    float *volume;
    void audioIn(float * input, int bufferSize, int nChannels); //サウンド入力するためのイベント
    vector <float> left;    //左チャンネルのベクトル(左側の音声出力について考える)
    ofSoundStream soundStream;  //サウンドストリーム(音声の出力入力等をコントロールしている)
    int slide;
    int elapsedTime;
    const int bufferSize = 256;

    unsigned int soundWaveSwitch;
    /*image*/
    ofImage triangle_w;
    unsigned int imageSwitch;
};
