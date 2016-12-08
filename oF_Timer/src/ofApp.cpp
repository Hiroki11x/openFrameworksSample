#include "ofApp.h"
unsigned int valueRed[7623];
unsigned int valueGreen[7623];
unsigned int valueBlue[7623];
int timer;
int framerate = 20;
int limitSecond =10;
void ofApp::setup(){
    sampleRate = 44100; //サンプリング周波数
    bufSize = 256;
    amp = 0.5; //音量
    pan = 0.5; //左右の定位
    phase = 0; //位相
    frequency = 440; //周波数
    waveShape = 6; //波形
    ofSetFrameRate(framerate);
    ofBackground(3, 3, 3);
    ofSoundStreamSetup(2, 0, this); //サウンドストリームの準備、左右2ch
    ofToggleFullscreen();
    ofEnableSmoothing();
    //画面の混色の設定を加算合成にする
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    //画像データの読込み
    myImage.loadImage("TSUBAME20.png");
    
    
    unsigned char * pixels = myImage.getPixels(); //画像の幅と高さを所得
    int w = myImage.width;
    int h = myImage.height;
    int counter=0;
    for (int i = 0; i < w; i+=8){
        for (int j = 0; j < h; j+=8){ //ピクセルのRGBの値を取得
            valueRed[counter] = pixels[j*3 * w + i*3];
            valueGreen[counter] = pixels[j*3 * w + i*3+1];
            valueBlue[counter] = pixels[j*3 * w + i*3+2];
            counter++;
        }
    }
    //ofDrawBitmapString(ofToString(counter), 10,300);
    //cout<<counter<<endl;
    
    
    ofBackground(34, 34, 34);
    ofSetVerticalSync(false);
    ofEnableAlphaBlending();
    
    //we load a font and tell OF to make outlines so we can draw it as GL shapes rather than textures
    font.loadFont("type/migmix.ttf", 100, true, false, true, 0.4, 90);
#ifdef TARGET_OPENGLES
    shader.load("shaders_gles/noise.vert","shaders_gles/noise.frag");
#else
    if(ofGetGLProgrammableRenderer()){
        shader.load("shaders_gl3/noise.vert", "shaders_gl3/noise.frag");
    }else{
        shader.load("shaders/noise.vert", "shaders/noise.frag");
    }
#endif
    
    doShader = false;
    
    ofEnableSmoothing();
    //画面の混色の設定を加算合成にする
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    //キャプチャするムービーのサイズを指定
    camWidth = ofGetWidth();
    camHeight = ofGetHeight();
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(camWidth,camHeight);
    timer=0;
}

void ofApp::update(){
    //ムービーをカメラからキャプチャする
    vidGrabber.update();
    timer++;
}

void ofApp::draw(){
    
    //色の設定
    ofSetColor(255, 255, 255);
    //読み込んだ画像データを画面に描画
    //myImage.draw(20,20); //画像データのビットマップ情報を配列に格納
    
    float audioHeight = ofGetHeight()/2.0f;
    float phaseDiff = ofGetWidth()/float(bufSize);
    
    ofSetColor(0,255,0);
if((timer/framerate)<limitSecond){
    ofSetBackgroundAuto(20);
    font.drawString(ofToString(limitSecond-timer/framerate), 100, ofGetHeight()/2);
}else{
    //-----------------Shader----------------------
    ofSetColor(0, 255, 0);
    ofFill();
    
    if(doShader){
        shader.begin();
        shader.setUniform1f("timeValX", ofGetElapsedTimef() * 0.1 );
        shader.setUniform1f("timeValY", -ofGetElapsedTimef() * 0.18 );
        shader.setUniform2f("mouse", mouseX - ofGetWidth()/2, ofGetHeight()/2-mouseY );
    }

    font.drawStringAsShapes("A Happy New Year", ofGetWidth()/2-600, ofGetHeight()/2+30);
    
    //左チャンネル波形を描画
    for (int i = 0; i < bufSize; i++){
        ofLine(i*phaseDiff, audioHeight/4, i*phaseDiff, audioHeight/4+lAudio[i]*audioHeight);
    }
    
    //右チャンネル波形を描画
    for (int i = 0; i < bufSize; i++){
        ofLine(i*phaseDiff, audioHeight/4*7, i*phaseDiff, audioHeight/4*7+rAudio[i]*audioHeight);
    }
    
    ofTranslate(-ofGetWidth(), 0);
    //---------------VideoGrabber--------------
    unsigned char * pixels = vidGrabber.getPixels();
    //画像を10ピクセルごとにスキャン
    for (int i = 0; i < camWidth; i+=6){
        for (int j = 0; j < camHeight; j+=6){
            //RGBそれぞれのピクセルの明度を取得
            unsigned char r = pixels[(j * camWidth + i)*3];
            unsigned char g = pixels[(j * camWidth + i)*3+1];
            unsigned char b = pixels[(j * camWidth + i)*3+2];
            //取得したRGB値をもとに、円を描画
            //取得したピクセルの明るさを、円の半径に対応させている
            ofSetColor(255, 0, 0, 50);
            ofCircle(camWidth+0 + i,20+j,20.0*(float)r/255.0);
            ofSetColor(0, 255, 0, 50);
            ofCircle(camWidth+0 + i,20+j,20.0*(float)g/255.0);
            ofSetColor(0, 0, 255, 50);
            ofCircle(camWidth+0 + i,20+j,20.0*(float)b/255.0);
        }
    }
    //---------------VideoGrabber--------------
    ofTranslate(ofGetWidth(), 0);
    
    if( doShader ){
        shader.end();
    }
    //-----------------Shader----------------------
}
}

void ofApp::keyPressed  (int key){
    //キー入力によって波形選択と音量調整
    switch(key){
        case '-': //音量下げる
            amp -= 0.05;
            amp = MAX(amp, 0);
            break;
        case '+': //音量上げる
            amp += 0.05;
            amp = MIN(amp, 1);
            break;
        case '1': //sin波
            waveShape = 1;
            break;
        case '2': //ノコギリ波
            waveShape = 2;
            break;
        case '3': //矩形波
            waveShape = 3;
            break;
        case '4': //三角波
            waveShape = 4;
            break;
        case '5': //ホワイトノイズ
            waveShape = 5;
            break;
        case '6': //ホワイトノイズ
            waveShape = 6;
            break;
        case '7': //ホワイトノイズ
            waveShape = 7;
            break;
        case 'f':
            ofToggleFullscreen();
            break;
        case 's':
            doShader = !doShader;
            break;
    }
}


void ofApp::keyReleased(int key){
}

void ofApp::mouseMoved(int x, int y ){
    pan = (float)x / (float)ofGetWidth();
    float heightPct = (float(ofGetHeight()-y) / float(ofGetHeight()));
    frequency = 4000.0f * heightPct;
    if(frequency < 20){
        frequency = 20;
    }
}

void ofApp::mouseDragged(int x, int y, int button){
}

void ofApp::mousePressed(int x, int y, int button){
}

void ofApp::mouseReleased(int x, int y, int button){
}

void ofApp::windowResized(int w, int h){
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
                *ofSignedNoise(ofGetElapsedTimef()+ofRandom(-1, 1));
                break;
            case 7: //色相表現
                sample =PI*valueBlue[i-(int)phase]/100;
                break;
                
        }
        //ofDrawBitmapString(ofToString(bufferSize), 300,300);
        // オーディオアウト、左右2ch
        lAudio[i] = output[i * nChannels] = sample * pan * amp;
        rAudio[i] = output[i * nChannels + 1] = sample * (1.0 - pan) * amp;
    }
}