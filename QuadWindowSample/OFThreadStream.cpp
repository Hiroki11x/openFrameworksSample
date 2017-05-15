//
//  OFThreadStream.cpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/11.
//
//

#include "OFThreadStream.hpp"


void OFThreadStream::setup() {

    ofxOpenGLContextScope::setup();
    // start the thread
    for(int i = 0 ;i<SCREEN_NUM;i++){
        thread[i].init(i);
        thread[i].startThread();    // blocking, non verbose
        screenFbo[i].allocate(CAM_WIDTH, CROP_HEIGHT);
    }

    ofSetFrameRate(0);
    camW = 960; camH = 740;
    ofSetWindowShape(camW*2, camH*1.5f);//WindowSizeは1980*1080
    mBlendmodeManager.init();
    tuningIndex = 0;

    //-----------------------------------Chromakey Shader--------------------------------
    bShowGui = true;
    bUpdateBgColor = true;

    //以下取得する画像の大きさの比に合わせる
    for(int i = 0;i<SCREEN_NUM;i++){
        chromakey[i] = new ofxChromaKeyShader(CAM_WIDTH, CROP_HEIGHT);
    }

    // maskee
    bg_image.load("black.jpg");//真っ黒背景(問題ないきがする)
    //-----------------------------------Chromakey Shader--------------------------------


    //---------------------GUI---------------------
    for(int i = 0;i<SCREEN_NUM;i++){
        chromaGui[i].setDefaultHeight(24);
        chromaGui[i].setDefaultWidth(camW/2);
        chromaGui[i].setup();
        chromaGui[i].add(chromakey[i]->generalParams);
        chromaGui[i].add(chromakey[i]->positionParams);
        chromaGui[i].setPosition(0, 0);
    }
    //---------------------GUI---------------------
}

void OFThreadStream::update() {
    for(int i = 0 ;i<SCREEN_NUM;i++){
        if(bUpdateBgColor && thread[i].img.isAllocated())
            chromakey[i]->updateBgColor(thread[i].img.getPixels());//Chromakeyに新しいPixelを入れる
            chromakey[i]->updateChromakeyMask(thread[i].img.getTexture(), bg_image.getTexture());
    }
    //---------------------FBOに描画--------------------
    for(int i = 0 ;i<SCREEN_NUM ;i++){
        screenFbo[i].begin();
        ofClear(0);
        //        img[i].draw(0, 0);
        chromakey[i]->drawFinalImage(0, 0, CAM_WIDTH, CROP_HEIGHT);//chromacyかけたやつを描画
        screenFbo[i].end();
    }
    //---------------------FBOに描画--------------------
}


void OFThreadStream::exit() {
    for(int i = 0 ;i<SCREEN_NUM;i++){
        thread[i].stopThread();
    }
    delete *chromakey;
}

void OFThreadStream::draw() {
    ofSetColor(255);
    ofBackground(0);

    //----------------------------GUIの描画--------------------------
    if(bShowGui) {
        chromaGui[tuningIndex].draw();
        //BackgroundColorはどこにするか見たいな四角形を描画
        if(bUpdateBgColor) {
            ofPushStyle();
            ofPushMatrix();
            ofTranslate(camW/2,0);
            ofScale(4.8,4.8);
            ofNoFill();
            ofSetLineWidth(3);
            ofSetColor(255);
            ofVec2f bgColorPos = chromakey[tuningIndex]->bgColorPos.get();
            ofDrawRectangle(bgColorPos.x, bgColorPos.y, chromakey[tuningIndex]->bgColorSize.get(), chromakey[tuningIndex]->bgColorSize.get());
            ofDrawBitmapString("bgColor", bgColorPos.x, bgColorPos.y - 5);
            ofPopMatrix();
            ofPopStyle();
        }

        //------------------------Chromakeyを描画-------------------------
        chromakey[tuningIndex]->drawFinalImage(camW/2, 0, camW, camH);//chromacyかけたやつを描画
        drawDebugMasks(tuningIndex);//Debug各種をサブルーチン化
        //------------------------Chromakeyを描画-------------------------
    }
    //----------------------------GUIの描画--------------------------
    else{
        //-----------------------それぞれの描画------------------------
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
#ifdef MULTISCREEN
        ofPushMatrix();
        ofTranslate(-225,100);
        screenFbo[0].draw(0,0,450,337.5);
        ofPopMatrix();

        ofPushMatrix();
        ofRotate(180);
        ofTranslate(-225,100);
        screenFbo[1].draw(0,0,450,337.5);
        ofPopMatrix();

        ofPushMatrix();
        ofRotate(90);
        ofTranslate(-225,100);
        screenFbo[2].draw(0,0,450,337.5);
        ofPopMatrix();

        ofPushMatrix();
        ofRotate(270);
        ofTranslate(-225,100);
        screenFbo[3].draw(0,0,450,337.5);
        ofPopMatrix();
#else
        ofPushMatrix();
        ofTranslate(-225,100);
        screenFbo[0].draw(0,0,450,337.5);
        ofPopMatrix();

        ofPushMatrix();
        ofRotate(180);
        ofTranslate(-225,100);
        screenFbo[0].draw(0,0,450,337.5);
        ofPopMatrix();

        ofPushMatrix();
        ofRotate(90);
        ofTranslate(-225,100);
        screenFbo[0].draw(0,0,450,337.5);
        ofPopMatrix();

        ofPushMatrix();
        ofRotate(270);
        ofTranslate(-225,100);
        screenFbo[0].draw(0,0,450,337.5);
        ofPopMatrix();
#endif
        ofPopMatrix();
        //-----------------------それぞれの描画------------------------
    }
    ofSetWindowTitle("FPS: "+ofToString(ofGetFrameRate())+" / "+mBlendmodeManager.getBlendmodeName());
}

//--------------------------------------------------------------
void OFThreadStream::drawDebugMasks(int i) {
    ofSetColor(255);
    int previewW = camW/2, previewH = camH/2, labelOffset = 10;

    chromakey[i]->drawBaseMask(camW + previewW, 0, previewW, previewH);
    ofDrawBitmapStringHighlight("Base mask", camW + previewW, labelOffset, ofColor(0, 125), ofColor::white);

    chromakey[i]->drawDetailMask(camW + previewW, previewH, previewW, previewH);
    ofDrawBitmapStringHighlight("Detailed mask", camW + previewW, previewH + labelOffset, ofColor(0, 125), ofColor::white);

    chromakey[i]->drawChromaMask(previewW, camH, previewW, previewH);
    ofDrawBitmapStringHighlight("Chroma mask", previewW, camH + labelOffset, ofColor(0, 125), ofColor::white);

    drawCheckerboard(camW, camH, previewW, previewH, 5);

    chromakey[i]->drawFinalMask(camW, camH, previewW, previewH);
    ofDrawBitmapStringHighlight("Final mask", camW, camH + labelOffset, ofColor(0, 125), ofColor::white);

    thread[i].img.draw(camW + previewW, camH, previewW, previewH);
    ofDrawBitmapStringHighlight("RGB image", camW + previewW, camH + labelOffset, ofColor(0, 125), ofColor::white);
}

//--------------------------------------------------------------
//チェス盤みたいなやつを描画
void OFThreadStream::drawCheckerboard(float x, float y, int width, int height, int size) {
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
void OFThreadStream::keyPressed(int key){

}

//--------------------------------------------------------------
void OFThreadStream::keyReleased(int key){
    switch(key){
        case 'a':
            bUpdateBgColor = !bUpdateBgColor;
            break;
        case 'g':
            bShowGui = !bShowGui;
            break;
        case ' ':
            mBlendmodeManager.nextIndex();
            break;
        case OF_KEY_RETURN:
#ifdef MULTISCREEN
            tuningIndex = (tuningIndex+1)%SCREEN_NUM;
#endif
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void OFThreadStream::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void OFThreadStream::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void OFThreadStream::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void OFThreadStream::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void OFThreadStream::windowResized(int w, int h){

}

//--------------------------------------------------------------
void OFThreadStream::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void OFThreadStream::dragEvent(ofDragInfo dragInfo){
    
}