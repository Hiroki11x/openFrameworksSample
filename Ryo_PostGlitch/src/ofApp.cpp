#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofBackground(0);
    
    //Kinect初期化(ofxKinect)
    kinect.init();
    kinect.open();
    
    //    ofEnableDepthTest();
    //    ofEnableAlphaBlending();
    
    bDrawLenna = false;
    bShowHelp  = true;
    
    /*
     【ofFbo とは】
     描画をしない描画領域です。
     例えば、三角を書いたり、四角を書いたり、勉強していたと思いますが、
     例えばドラえもんを書いた場合に、次回以降のdrawの際にも、
     毎回丸を書いたりしていると大変なので、fboに描画を書き込んで、
     fboをステージに毎回書き込むようにする事で、毎回丸やら四角やらを書かなくて済むようです。
     エフェクトを適用したい映像は、すべてこのFboに描画します。
     */
    
    fbo.allocate(640, 360);//ofFboに対してメモリ割当
    //(おそらく動画サイズ/Kinectの場合はキャプチャした映像サイズに合わせてメモリが割り当てられている)
    
    myGlitch.setup(&fbo); //myGlitchはofxPostGlitchのインスタンス。
    //fboのメモリの先頭番地を引数に与えてエフェクトを書き込みます。
    
    /*
     【ofxPostGlitchとは】
     oF+GLSLでポストエフェクトを実現するためのアドオンです。
     */
    
    //lenna.loadImage("a.png");
    
    //Videoのロードと再生
    video.loadMovie("11.mov");
    video.play();
    
    //SyphonServer
    mainOutputSyphonServer.setName("Screen Outputh");
    mClient.setup();
    mClient.setApplicationName("Simple Serverh");
    mClient.setServerName("");
}

//--------------------------------------------------------------
void ofApp::update(){
    //VideoとKinectのUpdate
    video.update();
    kinect.update();
    
    if (ofGetFrameNum() % 60 == 0) {//1/60で
        flow.resetFeaturesToTrack();
    }
    if (ofGetFrameNum() > 10) {
        flow.calcOpticalFlow(video.getPixelsRef());
    }
    
    pts.clear();
    pts = flow.getFeatures();
    
    delaunay.reset();
    if (pts.size() > 20) {
        for (int i = 0; i < pts.size(); i+=5) {
            delaunay.addPoint(ofPoint(pts[i]));
        }
        delaunay.triangulate();
    }
    
    fbo.begin();//以下をfboに追加し、あとでまとめて描画
    ofClear(0, 0, 0, 255);//画面をクリーン(今回は特にofFboを明示的にクリーン)
    /*
    if (!bDrawLenna){
        for (int i = 0;i < 100;i++){
            if(i % 5 == 0){
                ofSetColor(50 , 255, 100);
            }else if (i % 9 == 0){
                ofSetColor(255, 50, 100);
            }else{
                ofSetColor(255, 255, 255);
            }
        }
    }else{
        ofSetColor(255);
        //lenna.draw(0, 0);
    }
     */
    
    ofSetColor(255);
    kinect.drawDepth(0, 0);//Kinectの深度画像
    ofNoFill();
    delaunay.draw();//三角形に分割するドロネーを描画
    fbo.end();//ofFboへ、描画するものを
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    
    myGlitch.generateFx();//ofxPostGlitchでのエフェクトを生成
    video.draw(0, 0,ofGetWidth(),ofGetHeight());//Videoを背景に描画(Kinectの場合はKinectをkinect.draw())
    ofSetColor(255,128);
    fbo.draw(0, 0,ofGetWidth(),ofGetHeight());
   
    
    mClient.draw(500, 50);
    mainOutputSyphonServer.publishScreen();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, true);
    if (key == '2') myGlitch.setFx(OFXPOSTGLITCH_GLOW			, true);
    if (key == '3') myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, true);
    if (key == '4') myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, true);
    if (key == '5') myGlitch.setFx(OFXPOSTGLITCH_TWIST			, true);
    if (key == '6') myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, true);
    if (key == '7') myGlitch.setFx(OFXPOSTGLITCH_NOISE			, true);
    if (key == '8') myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, true);
    if (key == '9') myGlitch.setFx(OFXPOSTGLITCH_SWELL			, true);
    if (key == '0') myGlitch.setFx(OFXPOSTGLITCH_INVERT			, true);
    
    if (key == 'q') myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
    if (key == 'w') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, true);
    if (key == 'e') myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, true);
    if (key == 'r') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, true);
    if (key == 't') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, true);
    if (key == 'y') myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, true);
    if (key == 'u') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, true);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == '1') myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
    if (key == '2') myGlitch.setFx(OFXPOSTGLITCH_GLOW			, false);
    if (key == '3') myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
    if (key == '4') myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
    if (key == '5') myGlitch.setFx(OFXPOSTGLITCH_TWIST			, false);
    if (key == '6') myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, false);
    if (key == '7') myGlitch.setFx(OFXPOSTGLITCH_NOISE			, false);
    if (key == '8') myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
    if (key == '9') myGlitch.setFx(OFXPOSTGLITCH_SWELL			, false);
    if (key == '0') myGlitch.setFx(OFXPOSTGLITCH_INVERT			, false);
    
    if (key == 'q') myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
    if (key == 'w') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
    if (key == 'e') myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
    if (key == 'r') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
    if (key == 't') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
    if (key == 'y') myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
    if (key == 'u') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);
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