#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(WIDTH, HEIGHT);
    ofSetVerticalSync(true); //垂直同期（処理するフレームと描画するフレームを合わせる）
    ofSetFrameRate(30);
    ofSetCircleResolution(3);
    lenna.loadImage("lenna.png");
    bDrawLenna = false;
    bShowHelp  = true;
    myFbo.allocate(WIDTH, HEIGHT);
    
    myGlitch.setup(&myFbo);
    
    shaderSwitch=false;
  
    //movie
    movie.loadMovie("movie.mp4");
    movie.setSpeed(3);
    
    //audio
    left.assign(bufferSize, 0.0);
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    soundWaveSwitch = 1;
    
    //image
    triangle_w.loadImage("logo.png");
    imageSwitch = 1;

}

//--------------------------------------------------------------
void ofApp::update(){
    movie.update();
    myFbo.begin();
    ofClear(0, 0, 0,255);
    
    if (!bDrawLenna){
    }else{
        ofSetColor(255);
        lenna.draw(0, 0);
    }
    
    ofSetColor(255, 255, 255);
    movie.draw(0, 0, WIDTH, HEIGHT);
    
    myFbo.end();
    if(shaderSwitch){
        shaderIndex=ofRandom(1,17);
        if(ofGetElapsedTimeMillis()%1000<300){
            if (shaderIndex == 1) myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, true);
//            if (shaderIndex == 2) myGlitch.setFx(OFXPOSTGLITCH_GLOW			, true);
            if (shaderIndex == 3) myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, true);
//            if (shaderIndex == 4) myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, true);
            if (shaderIndex == 5) myGlitch.setFx(OFXPOSTGLITCH_TWIST			, true);
//            if (shaderIndex == 6) myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, true);
//            if (shaderIndex == 7) myGlitch.setFx(OFXPOSTGLITCH_NOISE			, true);
//            if (shaderIndex == 8) myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, true);
//            if (shaderIndex == 9) myGlitch.setFx(OFXPOSTGLITCH_SWELL			, true);
           // if (shaderIndex == 10) myGlitch.setFx(OFXPOSTGLITCH_INVERT			, true);
            
            //            if (shaderIndex == 11) myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
            //            if (shaderIndex == 12) myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, true);
            //            if (shaderIndex == 13) myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, true);
            //            if (shaderIndex == 14) myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, true);
            //            if (shaderIndex == 15) myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, true);
            //            if (shaderIndex == 16) myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, true);
            //            if (shaderIndex == 17) myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, true);
        }else{
            
            
            
            if (shaderIndex == 1) myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
//            if (shaderIndex == 2) myGlitch.setFx(OFXPOSTGLITCH_GLOW			, false);
            if (shaderIndex == 3) myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
//            if (shaderIndex == 4) myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
            if (shaderIndex == 5) myGlitch.setFx(OFXPOSTGLITCH_TWIST			, false);
//            if (shaderIndex == 6) myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, false);
//            if (shaderIndex == 7) myGlitch.setFx(OFXPOSTGLITCH_NOISE			, false);
//            if (shaderIndex == 8) myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
//            if (shaderIndex == 9) myGlitch.setFx(OFXPOSTGLITCH_SWELL			, false);
           // if (shaderIndex == 10) myGlitch.setFx(OFXPOSTGLITCH_INVERT			, false);
            //
            //            if (shaderIndex == 11) myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
            //            if (shaderIndex == 12) myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
            //            if (shaderIndex == 13) myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
            //            if (shaderIndex == 14) myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
            //            if (shaderIndex == 15) myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
            //            if (shaderIndex == 16) myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
            //            if (shaderIndex == 17) myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);
            
        }
    }
    else{
        myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
        myGlitch.setFx(OFXPOSTGLITCH_GLOW			, false);
        myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
        myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
        myGlitch.setFx(OFXPOSTGLITCH_TWIST			, false);
        myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, false);
        myGlitch.setFx(OFXPOSTGLITCH_NOISE			, false);
        myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
        myGlitch.setFx(OFXPOSTGLITCH_SWELL			, false);
        myGlitch.setFx(OFXPOSTGLITCH_INVERT			, false);
        
        //        myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
        //        myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
        //        myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
        //        myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
        //        myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
        //        myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
        //        myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);
    }
    
    //audio
    volume = ofSoundGetSpectrum(GetPrecision);
    elapsedTime++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    /* Apply effects */
    //myGlitch.setFx(OFXPOSTGLITCH_INVERT, true);
    myGlitch.generateFx();
    
    /* draw effected view */
    ofSetColor(255, 255, 255);
    myFbo.draw(0, 0);
    
    //audio
    ofSetColor(255, 255, 255);//波形の色を指定
    
    float ys[bufferSize];
    for(unsigned int i = 0; i < bufferSize; i++){
        ys[i] = HEIGHT / 2 - left[i] * 800.0f;
    }
    
    if(soundWaveSwitch == 1){
        ofSetLineWidth(3);//線の幅を指定
        ofNoFill();
        
        /*
        ofBeginShape();//点を結んだ集合を以下で描画
        for (unsigned int i = 0; i < bufferSize; i++){//左チャンネルの配列が終わるまで描画
            //第一引数はx座標,第二引数はy座標(leftの配列の値を表現)
            ofVertex(i * WIDTH / bufferSize, ys[i]);
        }
        ofEndShape(false);
         */
        
        ofFill();
    }
    if(soundWaveSwitch == 2){
        ofSetLineWidth(1);
        float phaseDiff = WIDTH / bufferSize * 8;
        for(int i = 0; i < bufferSize / 8; i++){
            for(int j = 0; j < bufferSize / 8; j++){
                if(i == j)continue;
                float dist = ofDist(i * phaseDiff, ys[i*8], j * phaseDiff, ys[j*8]);
                if(dist < 300 && dist > 100){
                    ofLine(i * phaseDiff, ys[i*8], j * phaseDiff, ys[j*8]);
                }
            }
        }
    }
    //image
    ofSetColor(255, 255, 255);
    float triWidth = triangle_w.getWidth() / 5;
    float triHeight = triangle_w.getHeight() / 5;
    float angle = ofGetElapsedTimeMillis()/10;
    if(imageSwitch==1){
//        triangle_w.draw(WIDTH / 2 - triWidth / 2, HEIGHT / 2 - triHeight / 2, triWidth, triHeight);
    }else if(imageSwitch==2){
        ofPushMatrix();
        ofTranslate(WIDTH / 2, HEIGHT / 2);
        ofRotateZ(angle);
//        triangle_w.draw(-triWidth / 2, -triHeight / 2, triWidth, triHeight);
        ofRotateZ(-angle);
        ofPopMatrix();
    }else if(imageSwitch==3){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 6; j++){
                ofPushMatrix();
                ofTranslate(i * WIDTH / 8 + triWidth / 2, j * HEIGHT / 6 + triHeight / 2);
                ofRotateY(angle);
                ofRotateX(angle);
                ofRotateZ(angle);
//                triangle_w.draw(-triWidth / 2, -triHeight / 2, triWidth, triHeight);
                ofPopMatrix();
            }
        }
    }
    triangle_w.draw(ofGetWidth()-440, ofGetHeight()-80,300,60);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==' ')shaderSwitch = true;
    
    if(key=='1')soundWaveSwitch=1;
    if(key=='2')soundWaveSwitch=2;
    
    if(key=='q')imageSwitch=1;
    if(key=='w')imageSwitch=2;
    
    if(key=='s')movie.play();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key==' ')shaderSwitch = false;
    
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
void ofApp::audioIn(float *input, int bufferSize, int nChannels){
    for (int i = 0; i < bufferSize; i++){
        left[i] = input[i*2]*0.5;//偶数はleftに(左チャンネルのみ取得)
    }
}