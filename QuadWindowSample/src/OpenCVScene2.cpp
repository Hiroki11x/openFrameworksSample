//
//  OpenCVScene2.cpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/09.
//
//

#include "OpenCVScene2.hpp"

//--------------------------------------------------------------
void OpenCVScene2::setup(){

    ofSetFrameRate(0);

    //    img[0].load("img_0.jpeg");
    //    img[1].load("img_1.jpeg");
    //    img[2].load("img_2.jpeg");
    //    img[3].load("img_3.jpeg");

    for(int i = 1 ;i<1 ;i++){
        screenFbo[i].clear();
        screenFbo[i].allocate(CAM_WIDTH,CROP_HEIGHT);
    }

    //岩瀬 192.168.145.238
    //    cap[0] = cv::VideoCapture("http://192.168.145.238:7890/ipvideo.mjpg");
    //    img[0].allocate(CAM_WIDTH, CROP_HEIGHT, OF_IMAGE_COLOR);

    //長田 192.168.157.5
    cap[1] = cv::VideoCapture("http://192.168.157.5:7890/ipvideo.mjpg");
    img[1].allocate(CAM_WIDTH, CROP_HEIGHT, OF_IMAGE_COLOR);

    //奥村 192.168.145.27 (KeiのPCの設定的に、きつい)
    //    cap[2] = cv::VideoCapture("http://192.168.145.27:7890/ipvideo.mjpg");
    //    img[2].allocate(CAM_WIDTH, CROP_HEIGHT, OF_IMAGE_COLOR);


    //---------OpenCV Sample として追加 ---------
    //使用する画像の領域を確保
    colorImg.allocate(CAM_WIDTH,CROP_HEIGHT);
    grayImage.allocate(CAM_WIDTH,CROP_HEIGHT);
    grayBg.allocate(CAM_WIDTH,CROP_HEIGHT);
    grayDiff.allocate(CAM_WIDTH,CROP_HEIGHT);

    //変数の初期化
    bLearnBakground = true;
    showCvAnalysis = false;
    threshold = 20;
    videoMode = 0;
    //------------------------------------------

}

//--------------------------------------------------------------
void OpenCVScene2::update(){


    for(int i = 1; i<2;i++){
        if (cap[i].isOpened() ){
            cap[i] >> frame[i];
            if(frame[i].empty()){
                cout << "empty" << endl;
                exit();
            }else{
                img[i].setFromPixels(frame[i].ptr(), frame[i].cols, frame[i].rows, OF_IMAGE_COLOR,FALSE);
                colorImg.setFromPixels(frame[i].ptr(),frame[i].cols, frame[i].rows);
                //---------OpenCV Sample として追加 ---------

                //カラーのイメージをグレースケールに変換
                grayImage = colorImg;//ofxCvColorImageからの返還じゃないとpixel生で操作する必要あり

                //まだ背景画像が記録されていなければ、現在のフレームを背景画像とする
                if (bLearnBakground == true){
                    grayBg = grayImage;
                    bLearnBakground = false;
                }

                //グレースケールのイメージと取り込んだ背景画像との差分を算出
                grayDiff.absDiff(grayBg, grayImage);
                //画像を2値化(白と黒だけに)する
                grayDiff.threshold(threshold);
                //2値化した画像から輪郭を抽出する
                contourFinder.findContours(grayDiff, 25, grayDiff.width * grayDiff.height, 10, false, false);

                //-----------------------------------------------------
            }
            if(cv::waitKey(30) >= 0) exit();
        }
    }



    for(int i = 1 ;i<2 ;i++){
        screenFbo[i].begin();
        ofClear(0);
        if(img[i].isAllocated())img[i].draw(0,0);
        screenFbo[i].end();
    }
}

//--------------------------------------------------------------
void OpenCVScene2::draw(){
    ofBackground(0);
    screenFbo[1].draw(0,0);

    //---------OpenCV Sample として追加 ---------
    //現在のモードに応じて、表示する映像を切り替え
    switch (videoMode) {

        case 1:
            //グレースケール映像
            grayImage.draw(0, 0, ofGetWidth(), ofGetHeight());
            break;

        case 2:
            //背景画像
            grayBg.draw(0, 0, ofGetWidth(), ofGetHeight());
            break;

        case 3:
            //2値化された差分映像
            grayDiff.draw(0, 0, ofGetWidth(), ofGetHeight());
            break;

        default:
            //カラー映像
            colorImg.draw(0, 0, ofGetWidth(), ofGetHeight());
            break;
    }

    //画面に対する映像の比率を計算
    float ratioX = ofGetWidth()/CAM_WIDTH;
    float ratioY = ofGetHeight()/CROP_HEIGHT;

    //解析結果を表示する場合
    if (showCvAnalysis) {
        //検出した解析結果を表示
        for (int i = 0; i < contourFinder.nBlobs; i++){
            ofPushMatrix();
            //画面サイズいっぱいに表示されるようリスケール
            glScalef((float)ofGetWidth() / (float)grayDiff.width,
                     (float)ofGetHeight() / (float)grayDiff.height,
                     1.0f);
            contourFinder.blobs[i].draw(0,0);
            ofFill();
            ofSetColor(255, 0, 0);
            ofEllipse(contourFinder.blobs[i].centroid.x, contourFinder.blobs[i].centroid.y, 4, 4);
            ofPopMatrix();
        }
    }

    //ログと操作説明を表示
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("FPS: "+ofToString(ofGetFrameRate()), 20, 20);
    ofDrawBitmapString("Threshold: "+ofToString(threshold), 20, 35);
    ofDrawBitmapString("Number of Blobs: "+ofToString(contourFinder.nBlobs), 20, 50);
    ofDrawBitmapString("[0] Show original video", 20, 65);
    ofDrawBitmapString("[1] Show grayscale video", 20, 80);
    ofDrawBitmapString("[2] Show captured background", 20, 95);
    ofDrawBitmapString("[3] Show difference from background", 20, 110);
    ofDrawBitmapString("[space] Captuer background", 20, 125);
    ofDrawBitmapString("[a] Analysis on / off", 20, 140);
}

//--------------------------------------------------------------
void OpenCVScene2::keyPressed(int key){

    //キー入力でモード切り替え
    //---------OpenCV Sample として追加 ---------
    switch (key){
        case '0':
            //カラー映像表示
            videoMode = 0;
            break;

        case '1':
            //グレースケール映像表示
            videoMode = 1;
            break;

        case '2':
            //背景画像表示
            videoMode = 2;
            break;

        case '3':
            //2値化した差分映像
            videoMode = 3;
            break;

        case 'a':
            //解析結果の表示の on / off
            showCvAnalysis ? showCvAnalysis=false : showCvAnalysis=true;
            break;

        case 'f':
            //フルスクリーンに
            ofSetFullscreen(true);
            break;

        case ' ':
            //背景画像を新規に取り込む
            bLearnBakground = !bLearnBakground;
            break;

        case '+':
            //2値化の閾値を増加
            threshold ++;
            if (threshold > 255) threshold = 255;
            break;

        case '-':
            //2値化の閾値を減少
            threshold --;
            if (threshold < 0) threshold = 0;
            break;
    }
    //------------------------------------------
}

//--------------------------------------------------------------
void OpenCVScene2::keyReleased(int key){

}

//--------------------------------------------------------------
void OpenCVScene2::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void OpenCVScene2::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void OpenCVScene2::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void OpenCVScene2::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void OpenCVScene2::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void OpenCVScene2::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void OpenCVScene2::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void OpenCVScene2::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void OpenCVScene2::dragEvent(ofDragInfo dragInfo){ 
    
}
