//
//  MainStream.cpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/09.
//
//

#include "MainStream.hpp"

//--------------------------------------------------------------
void MainStream::setup(){

    ofSetFrameRate(0);

    camW = 960; camH = 740;
    ofSetWindowShape(camW*2, camH*1.5f);//WindowSizeは1980*1080

    mBlendmodeManager.init();
    tuningIndex = 0;

    //---------------------------mjpg Connection-------------------------------------
    img[0].allocate(CAM_WIDTH, CROP_HEIGHT, OF_IMAGE_COLOR);
    screenFbo[0].allocate(CAM_WIDTH, CROP_HEIGHT);
    cap[0] = cv::VideoCapture("http://52.197.48.133:8080/?action=stream&type=mjpg");
    cap[0].set(CV_CAP_PROP_BUFFERSIZE, 3); // internal buffer will now store only 3 frames
    cap[0].set(CV_CAP_PROP_FPS, 0);

#ifdef MULTISCREEN
    img[1].allocate(CAM_WIDTH, CROP_HEIGHT, OF_IMAGE_COLOR);
    screenFbo[1].allocate(CAM_WIDTH, CROP_HEIGHT);
    cap[1] = cv::VideoCapture("http://52.197.48.133:8082/?action=stream&type=mjpg");
    cap[1].set(CV_CAP_PROP_BUFFERSIZE, 3); // internal buffer will now store only 3 frames
    cap[1].set(CV_CAP_PROP_FPS, 0);

    img[2].allocate(CAM_WIDTH, CROP_HEIGHT, OF_IMAGE_COLOR);
    screenFbo[2].allocate(CAM_WIDTH, CROP_HEIGHT);
    cap[2] = cv::VideoCapture("http://52.197.48.133:8081/?action=stream&type=mjpg");
    cap[2].set(CV_CAP_PROP_BUFFERSIZE, 3); // internal buffer will now store only 3 frames
    cap[2].set(CV_CAP_PROP_FPS, 0);

    img[3].allocate(CAM_WIDTH, CROP_HEIGHT, OF_IMAGE_COLOR);
    cap[3] = cv::VideoCapture("http://52.197.48.133:8083/?action=stream&type=mjpg");
    screenFbo[3].allocate(CAM_WIDTH, CROP_HEIGHT);
    cap[3].set(CV_CAP_PROP_BUFFERSIZE, 3); // internal buffer will now store only 3 frames
    cap[3].set(CV_CAP_PROP_FPS, 0);
#endif


    //---------------------------mjpg Connection--------------------------------------


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

//--------------------------------------------------------------
void MainStream::exit() {
    delete *chromakey;
}

//--------------------------------------------------------------
void MainStream::update(){
    ofSetWindowTitle("[FPS]: "+ofToString(ofGetFrameRate()) +" / "+ mBlendmodeManager.getBlendmodeName());

    //-------------取得した videocapture をchromakeyにセット--------------
    for(int i = 0; i<SCREEN_NUM;i++){
        if (cap[i].isOpened() ){
            cap[i] >> frame[i];
            if(frame[i].empty()){
                cout << "empty" << endl;
                break;
            }else{
                img[i].setFromPixels(frame[i].ptr(), frame[i].cols, frame[i].rows, OF_IMAGE_COLOR,FALSE);//RaspPiからの入力はBGRじゃないのでfalseを引数に入れない
                if(bUpdateBgColor && img[i].isAllocated())
                    chromakey[i]->updateBgColor(img[i].getPixels());//Chromakeyに新しいPixelを入れる
                chromakey[i]->updateChromakeyMask(img[i].getTexture(), bg_image.getTexture());
            }
            if(cv::waitKey(30) >= 0) {
                break;
            }
        }
    }
    //-------------取得した videocapture をchromakeyにセット--------------



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

//--------------------------------------------------------------
void MainStream::draw(){
    ofSetColor(255);
    ofBackground(0);

    //----------------------------GUIの描画--------------------------
    if(bShowGui) {
        chromaGui[tuningIndex].draw();
        //BackgroundColorはどこにするか見たいな四角形を描画
        if(bUpdateBgColor) {
            ofPushStyle();
            ofNoFill();
            ofSetLineWidth(3);
            ofSetColor(255);
            ofVec2f bgColorPos = chromakey[tuningIndex]->bgColorPos.get();
            ofDrawRectangle(bgColorPos.x + camW/2, bgColorPos.y, chromakey[tuningIndex]->bgColorSize.get(), chromakey[tuningIndex]->bgColorSize.get());
            ofDrawBitmapString("bgColor", bgColorPos.x + camW/2, bgColorPos.y - 5);
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
}

//--------------------------------------------------------------
void MainStream::drawDebugMasks(int i) {
    ofSetColor(255);
    int previewW = camW/2, previewH = camH/2, labelOffset = 10;

    chromakey[i]->drawBaseMask(camW + previewW, 0, previewW, previewH);
    ofDrawBitmapStringHighlight("Base mask", camW + previewW, labelOffset, ofColor(125, 225), ofColor::white);

    chromakey[i]->drawDetailMask(camW + previewW, previewH, previewW, previewH);
    ofDrawBitmapStringHighlight("Detailed mask", camW + previewW, previewH + labelOffset, ofColor(125, 225), ofColor::white);

    chromakey[i]->drawChromaMask(previewW, camH, previewW, previewH);
    ofDrawBitmapStringHighlight("Chroma mask", previewW, camH + labelOffset, ofColor(125, 225), ofColor::white);

    drawCheckerboard(camW, camH, previewW, previewH, 5);

    chromakey[i]->drawFinalMask(camW, camH, previewW, previewH);
    ofDrawBitmapStringHighlight("Final mask", camW, camH + labelOffset, ofColor(125, 225), ofColor::white);

    img[i].draw(camW + previewW, camH, previewW, previewH);
    ofDrawBitmapStringHighlight("RGB image", camW + previewW, camH + labelOffset, ofColor(125, 225), ofColor::white);
}

//--------------------------------------------------------------
//チェス盤みたいなやつを描画
void MainStream::drawCheckerboard(float x, float y, int width, int height, int size) {
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
void MainStream::keyPressed(int key){

}

//--------------------------------------------------------------
void MainStream::keyReleased(int key){
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
            tuningIndex = (tuningIndex+1)%3;
#endif
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void MainStream::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void MainStream::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void MainStream::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void MainStream::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void MainStream::windowResized(int w, int h){

}

//--------------------------------------------------------------
void MainStream::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void MainStream::dragEvent(ofDragInfo dragInfo){
    
}
