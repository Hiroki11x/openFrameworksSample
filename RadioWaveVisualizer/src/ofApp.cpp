#include "ofApp.h"
int hour,minuite,second;
int setHour,setMinuite,setSecond;
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    //font.loadFont("Adamas-Regular.otf", 60);
    font.loadFont("Roboto-Light.ttf",60);
    setHour=19;
    setMinuite=47;
    setSecond=0;
    
    
    hour=setHour-1;
    second=mod(setMinuite-1,60);
    minuite=mod(setSecond-1,60);
    
    
    sampleRate = 44100; //サンプリング周波数
    bufSize = 256;
    amp = 0.5; //音量
    pan = 0.5; //左右の定位
    phase = 0; //位相
    frequency = 440; //周波数
    waveShape = 6; //波形
    //ofSetFrameRate(framerate);
    ofBackground(3, 3, 3);
    ofSoundStreamSetup(2, 0, this); //サウンドストリームの準備、左右2ch
    
}
int ofApp::mod(int a,int b){
    return (b-abs(a))%b;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    ofSetColor(255);
    //font.drawString(ofToString(second),50,70);
    
    double minites = (int)ofGetElapsedTimef()/60;
    double second = ofGetElapsedTimef()-minites*60;
    if(second<10){
        font.drawString("ELAPSED TIME : "+ofToString(minites)+":0"+ofToString(ofGetElapsedTimef()-minites*60), 100, -30+ofGetHeight()/2);
    }else{
        font.drawString("ELAPSED TIME : "+ofToString(minites)+":"+ofToString(ofGetElapsedTimef()-minites*60), 100, -30+ofGetHeight()/2);
    }
    
    cam.end();
    
    
    float audioHeight = ofGetHeight()/2.0f;
    float phaseDiff = ofGetWidth()/float(bufSize);
    //左チャンネル波形を描画
    for (int i = 0; i < bufSize; i++){
        ofLine(i*phaseDiff, audioHeight/4, i*phaseDiff, audioHeight/4+lAudio[i]*audioHeight);
    }
    
    //右チャンネル波形を描画
    for (int i = 0; i < bufSize; i++){
        ofLine(i*phaseDiff, audioHeight/4*7, i*phaseDiff, audioHeight/4*7+rAudio[i]*audioHeight);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
            
        default:
            break;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::audioRequested(float * output, int bufferSize, int nChannels){
    float sample; //出力する音のサンプル
    float phaseDiff; //位相の変化
    
    //1サンプルあたりの位相の変化を計算
    phaseDiff = TWO_PI * frequency / sampleRate;
    
    //バッファのサイズ分の波形を生成
    for (int i = 0; i < bufferSize; i++){
        //位相を更新
        phase += phaseDiff;
        while (phase > TWO_PI){
            phase -= TWO_PI;
        }
        // 波形を選択
        switch (waveShape) {
            case 1: // Sin波
            sample = sin(phase);
            break;
            case 2: // ノコギリ波
            sample = - phase / PI + 1;
            break;
            case 3: // 矩形波
            sample = (phase < PI) ? -1 : 1;
            break;
            case 4: // 三角波
            sample = (phase < PI) ? -2 / PI * phase + 1 : 2 / PI * phase - 3;
            break;
            case 5: // ホワイトノイズ
            sample = ofRandom(-0.5, 0.5)+2*sin(phase);
            break;
            case 6: //ランダムっぽく
            sample = ofSignedNoise(ofGetElapsedTimef(),ofRandom(1))*0.04
            +sin(phase*ofSignedNoise(ofGetElapsedTimef()*ofRandom(0.1)))
            *ofSignedNoise(ofGetElapsedTimef()+ofRandom(-1, 1))/10;
            break;
            case 7: //色相表現
            //sample =PI*valueBlue[i-(int)phase]/100;
            break;
            
        }
        //ofDrawBitmapString(ofToString(bufferSize), 300,300);
        // オーディオアウト、左右2ch
        lAudio[i] = output[i * nChannels] = sample * pan * amp;
        rAudio[i] = output[i * nChannels + 1] = sample * (1.0 - pan) * amp;
    }
}
