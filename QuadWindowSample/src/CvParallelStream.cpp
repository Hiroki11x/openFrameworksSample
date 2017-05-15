//
//  CvParallelStream.cpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/10.
//
//

#include "CvParallelStream.hpp"

//--------------------------------------------------------------
void CvParallelStream::setup(){

    ofxOpenGLContextScope::setup();

    ofSetFrameRate(2);
    bShowGui = true;

    camW = 960; camH = 740;

    ofSetWindowShape(1920,1480);//WindowSizeは1980*1080

    mBlendmodeManager.init();
    bShowGui = true;
    tuningIndex = 0;

    for(int i = 0 ;i<SCREEN_NUM ;i++){
        mCvParallelThread[i].setup(i);
    }
    for(int i = 0 ;i<SCREEN_NUM ;i++){
        mCvParallelThread[i].startThread();
    }
}

//--------------------------------------------------------------
void CvParallelStream::exit() {
//    delete *chromakey;
    //thread終了後に呼ばれるはず
    for(int i = 0 ;i<SCREEN_NUM ;i++){
        mCvParallelThread[i].stopThread();
    }
}

//--------------------------------------------------------------
void CvParallelStream::update(){

}

//--------------------------------------------------------------
void CvParallelStream::draw(){
//    ofSetWindowTitle("[FPS]: "+ofToString(ofGetFrameRate()) +" / "+ mBlendmodeManager.getBlendmodeName());
    ofSetColor(255);
    ofBackground(0);

    //----------------------------GUIの描画--------------------------
    if(bShowGui) {

        //---------------------FBOに描画--------------------
        for(int i = 4; i<SCREEN_NUM ;i++){
            mCvParallelThread[i].screenFbo.begin();
//            ofClear(0);
#ifdef CHROMAKEY
            mCvParallelThread[i].chromakey->drawFinalImage(0, 0, camW/2, camH/2);//chromacyかけたやつを描画
#else
            mCvParallelThread[i].img.draw(0, 0);
#endif
            mCvParallelThread[i].screenFbo.end();
        }
        //---------------------FBOに描画--------------------

#ifdef CHROMAKEY
        mCvParallelThread[tuningIndex].chromaGui.draw();
        //BackgroundColorはどこにするか見たいな四角形を描画

        //------------------------Chromakeyを描画-------------------------
        mCvParallelThread[tuningIndex].chromakey->drawFinalImage(camW/2, 0, camW, camH);//chromacyかけたやつを描画
#endif
        drawDebugMasks(tuningIndex);//Debug各種をサブルーチン化
        //------------------------Chromakeyを描画-------------------------
    }
    //----------------------------GUIの描画--------------------------
    else{
        //-----------------------それぞれの描画------------------------
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotate(45);
        mCvParallelThread[0].screenFbo.draw(50,50);
        ofRotate(90);
        mCvParallelThread[1].screenFbo.draw(50,50);
        ofRotate(90);
        mCvParallelThread[2].screenFbo.draw(50,50);
        ofRotate(90);
        mCvParallelThread[3].screenFbo.draw(50,50);
        ofPopMatrix();
        //-----------------------それぞれの描画------------------------
    }
}

//--------------------------------------------------------------
void CvParallelStream::drawDebugMasks(int i) {
    ofSetColor(255);
    int previewW = camW/2, previewH = camH/2, labelOffset = 10;

#ifdef CHROMAKEY
    mCvParallelThread[i].chromakey->drawBaseMask(camW + previewW, 0, previewW, previewH);
    ofDrawBitmapStringHighlight("Base mask", camW + previewW, labelOffset, ofColor(0, 125), ofColor::white);

    mCvParallelThread[i].chromakey->drawDetailMask(camW + previewW, previewH, previewW, previewH);
    ofDrawBitmapStringHighlight("Detailed mask", camW + previewW, previewH + labelOffset, ofColor(0, 125), ofColor::white);

    mCvParallelThread[i].chromakey->drawChromaMask(previewW, camH, previewW, previewH);
    ofDrawBitmapStringHighlight("Chroma mask", previewW, camH + labelOffset, ofColor(0, 125), ofColor::white);

    drawCheckerboard(camW, camH, previewW, previewH, 5);

    mCvParallelThread[i].chromakey->drawFinalMask(camW, camH, previewW, previewH);
    ofDrawBitmapStringHighlight("Final mask", camW, camH + labelOffset, ofColor(0, 125), ofColor::white);
#endif

    mCvParallelThread[i].img.draw(camW + previewW, camH, previewW, previewH);
    ofDrawBitmapStringHighlight("RGB image", camW + previewW, camH + labelOffset, ofColor(0, 125), ofColor::white);
}

//--------------------------------------------------------------
//チェス盤みたいなやつを描画
void CvParallelStream::drawCheckerboard(float x, float y, int width, int height, int size) {
    if (!checkerboardTex.isAllocated()) {
        checkerboardTex.allocate(width, height);

        ofPushStyle();
        checkerboardTex.begin();
        ofClear(255, 255, 255, 255);
        int numWidth = width/size;
        int numHeight = height/size;
        for(int h=0; h<numHeight; h++) {
            for(int w=0; w<numWidth; w++) {
                if ((h+w)%2 == 0) {
                    ofSetColor(ofColor::black);
                    ofDrawRectangle(w*size, h*size, size, size);
                }
            }
        }
        checkerboardTex.end();
        ofPopStyle();
    }

    ofSetColor(255, 255);
    checkerboardTex.draw(x, y);
}

//--------------------------------------------------------------
void CvParallelStream::keyPressed(int key){

}

//--------------------------------------------------------------
void CvParallelStream::keyReleased(int key){
    switch(key){
//        case 'a':
//            bUpdateBgColor = !bUpdateBgColor;
//            break;
        case 'g':
            bShowGui = !bShowGui;
            break;
        case ' ':
            mBlendmodeManager.nextIndex();
            break;
        case OF_KEY_RETURN:
            tuningIndex = (tuningIndex+1)%3;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void CvParallelStream::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void CvParallelStream::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void CvParallelStream::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void CvParallelStream::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void CvParallelStream::windowResized(int w, int h){

}

//--------------------------------------------------------------
void CvParallelStream::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void CvParallelStream::dragEvent(ofDragInfo dragInfo){
    
}
