#include "testApp.h"
//--------------------------------------------------------------
void testApp::setup() {
    //windowの初期設定
    ofBackground(0, 0, 0);
    ofSetWindowShape(1280, 480);
    ofSetFrameRate(30);
    
    //ofxOpenNIの初期設定
    kinect.setup();
    kinect.setRegister(true);
    kinect.setMirror(true);
    kinect.addDepthGenerator();     //距離情報の取得をKinectに組み込む
    kinect.addImageGenerator();     //色情報の取得をKinectに組み込む
    
    //深度画像にRGB画像の視点を適応させることによって、両者のずれをなくす。
    kinect.getDepthGenerator().GetAlternativeViewPointCap().SetViewPoint(kinect.getImageGenerator());

    kinect.start();
    
    //人が切り抜かれる用のofImageにメモリを割り当てる
    maskedImage.allocate(640, 480, OF_IMAGE_COLOR_ALPHA);
    scenery.loadImage("photo.jpg");//合成する風景画像をロード
}

//--------------------------------------------------------------
void testApp::update(){
    kinect.update();
    unsigned char *maskedImageData = maskedImage.getPixels();
    unsigned char *imageData = kinect.getImagePixels().getPixels();
    unsigned short *depthData = kinect.getDepthRawPixels().getPixels();
    for (int k = 0; k < 640*480; k++) {
        maskedImageData[k * 4 + 0] = imageData[k * 3 + 0];
        maskedImageData[k * 4 + 1] = imageData[k * 3 + 1];
        maskedImageData[k * 4 + 2] = imageData[k * 3 + 2];
        //指定範囲の対象物のピクセルのみのこし、それ以外は透明にする
        if (880 <= depthData[k] && depthData[k] < 1200)
            maskedImageData[k * 4 + 3] = 255; //見えるようにする
        else
            maskedImageData[k * 4 + 3] = 0;//見えないように透明化
    }
    maskedImage.setFromPixels(maskedImageData, 640, 480, OF_IMAGE_COLOR_ALPHA);//maskedImageに変換したデータをセット
}

//--------------------------------------------------------------
void testApp::draw(){
    kinect.drawDepth(0, 0, 640, 480);
    scenery.draw(640, 0, 640, 480);//風景描画
    maskedImage.draw(640, 0, 640, 480);//風景を描画した上に、対象物以外透明にした画像を重ねて描画
}
//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}