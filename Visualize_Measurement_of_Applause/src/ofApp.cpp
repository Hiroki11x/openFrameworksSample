#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetCircleResolution(60);
    ofBackground(54, 54, 54);
    
    // 0 output channels,
    // 2 input channels
    // 44100 samples per second
    // 256 samples per buffer
    // 4 num buffers (latency)
    
    soundStream.listDevices();
    
    //if you want to set a different device id
    //soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
    
    int bufferSize = 256;
    
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter	= 0;
    drawCounter		= 0;
    smoothedVol     = 0.0;
    scaledVol		= 0.0;
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
    font.loadFont("digital_counter_7_italic.ttf", 30);
    Lfont.loadFont("digital_counter_7_italic.ttf", 90);
    team=0;
    maxVol=0.0f;
    isGetVolume= false;
}

//--------------------------------------------------------------
void ofApp::update(){
    //lets scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(100, 0);
    ofBackgroundGradient(ofColor(25), ofColor(0),  OF_GRADIENT_CIRCULAR);
    ofTranslate(-100, 0);
    ofSetColor(225);
    ofDrawBitmapString("PHOTO COMPETITION BEST MOVIE AWARD @UT GALLALEY 2", 16, 32);
    //ofDrawBitmapString("press 's' to unpause the audio\n'e' to pause the audio", 31, 92);
    
    ofNoFill();//以下埋めない
    
    
    // ----------------------------draw the average volume:----------------------------
    
    ofPushStyle();
    ofPushMatrix();
    
    
    ofSetColor(225);
    ofDrawBitmapString("Scaled average vol (0-100): " + ofToString(scaledVol * 100.0, 0),16,ofGetHeight()-30);//右下
    //ofRect(0, 0, 400, 400);//四角形
    
    ofSetColor(245, 58, 135);
    ofSetColor(ofColor::fromHsb(maxVol/600.0*255.0, 255,255));

    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
    
    ofBeginShape();//円形のそれっぽいビジュアライズ
    for (unsigned int i = 0; i < right.size(); i++){
        ofVertex(100+350*cos(PI+right[i]*190.0f), 350*sin(PI+right[i]*190.0f));
        
    }
    ofEndShape(false);
    
//    for (unsigned int i = 0; i < right.size(); i++){
//        ofBezier(0,0,
//                 ofRandom(300)*cos(ofRandom(2*PI)),ofRandom(300)*sin(ofRandom(2*PI)),
//                 ofRandom(300)*cos(ofRandom(2*PI)),ofRandom(300)*sin(ofRandom(2*PI)),
//                 300*cos(PI+right[i]*90.0f), 300*sin(PI+right[i]*90.0f));
//    }
    
    //----------------------------lets draw the volume history as a graph----------------------------
    
    ofPopMatrix();
    ofPopStyle();
    
    float extend = (float)ofGetWidth()/(volHistory.size()-1);
    
    ofSetColor(ofColor::fromHsb(maxVol/600.0*255.0, 255,255));
    ofBeginShape();
    for (unsigned int i = 0; i < volHistory.size(); i++){
        if( i == 0 ){
            ofVertex(i*extend, ofGetHeight());
        }else if( i == volHistory.size()-1 ) {
            ofVertex(i*extend, ofGetHeight());
        }else{
            if((i%60 && volHistory[i]>volHistory[i-1] && volHistory[i]>volHistory[i+1])|| (i%60 &&volHistory[i]==1 && volHistory[i+1]==1)){
                ofDrawBitmapString(ofToString(volHistory[i] * 600), i*extend,  ofGetHeight()- volHistory[i] * 600);
            }
        }
        ofVertex(i*extend,  ofGetHeight()- volHistory[i] * 600);
        
        if(maxVol <volHistory[i]*600 && isGetVolume){//volの最大値が更新されたら、かつ、入力状態にある時
            maxVol=volHistory[i]*600;
        }else if(!isGetVolume){
            maxVol=0;
            volHistory[i]=0;//ボリュームの履歴を消去
        }
        
    }
    ofEndShape(false);
//    cout<<extend*(volHistory.size()-1)-ofGetWidth()<<endl;
    
    
    drawCounter++;
    
    ofSetColor(225);
    string reportString = "buffers received: "+ofToString(bufferCounter)+"\ndraw routines called: "+ofToString(drawCounter)+"\nticks: " + ofToString(soundStream.getTickCount());//文字列の準備
    ofDrawBitmapString(reportString, 16, 589);
    //ofDrawBitmapString(ofToString(ofGetHours())+ " : "+ofToString(ofGetMinutes())+" : "+ofToString(ofGetSeconds()),ofGetWidth()-160,50);
    font.drawString(ofToString(ofGetHours())+":"+ofToString(ofGetMinutes())+":"+ofToString(ofGetSeconds()),ofGetWidth()-160,50);
    Lfont.drawString("Max Volume: "+ofToString(maxVol),ofGetWidth()/2 -630,ofGetHeight()/2+30);
    switch (team) {
        case 0:
            Lfont.drawString("team J.K",20,200);
            break;
        case 1:
            Lfont.drawString("team M",20,200);
            break;
        case 2:
            Lfont.drawString("team L",20,200);
            break;
        case 3:
            Lfont.drawString("team N",20,200);
            break;
            
        default:
            break;
    }
    cout<<maxVol<<endl;
    
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==OF_KEY_RETURN){
        team=(team+1)%4;
        cout<<maxVol<<endl;
    }
    
    if(key==OF_KEY_UP){
        maxVol=0;
        isGetVolume= true;
        soundStream.start();
    }
    if(key==OF_KEY_DOWN){
        soundStream.stop();
        isGetVolume= false;
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }
    if(key=='f'){
        ofToggleFullscreen();
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
