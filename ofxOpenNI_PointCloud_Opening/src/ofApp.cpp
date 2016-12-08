#include "ofApp.h"
int mode;
int step;
//--------------------------------------------------------------
void ofApp::setup(){
    //画面設定
    
    
    ofBackgroundHex(0x000000);
    ofSetFrameRate(60);
    
    // Kinect初期設定
    // 深度とRGB情報のずれを補整
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
    // 角度を調整(0度に)
    angle = 0;
    kinect.setCameraTiltAngle(angle);
    //kinect.
    
    ofPushMatrix();
    ofTranslate(0, -100);
    ofScale(1, 1, 1);
    ofRotateX(90);
    //    camera.setFov(90);
    //    camera.lookAt(ofVec3f(0,0,0));
    //    camera.setPosition(300, 30, 300);
    ofPopMatrix();
    
    step = 10;
    easyCam.setDistance(1500);
    
    ofxGuiSetDefaultWidth(300);
    ofxGuiSetDefaultHeight(18);
    gui.setup("Depth Masking Control");
    gui.setPosition(10, 10);
    gui.add(near.set( "near", 0, 0, 255 ));
    gui.add(far.set( "far", 255, 0, 255 ));
    
    gui.add(filled.set("bFill", true));
    gui.add(radius.set( "radius", 140, 10, 300 ));
    gui.add(center.set("center",ofVec2f(ofGetWidth()*.5,ofGetHeight()*.5),ofVec2f(0,0),ofVec2f(ofGetWidth(),ofGetHeight())));
    gui.add(color.set("color",ofColor(100,100,140),ofColor(0,0),ofColor(255,255)));
    gui.add(circleResolution.set("circleRes", 5, 3, 90));
    gui.add(twoCircles.setup("twoCircles"));
    gui.add(ringButton.setup("ring"));
    gui.add(screenSize.set("screenSize", ""));
    
    gui2.setup("Point Cloud Gui");
    gui2.setPosition(10, 10);
    gui2.add(filled.set("num of pixel", true));
    gui2.add(radius.set( "pixel type", 140, 10, 300 ));
    gui2.add(center.set("average position",ofVec2f(ofGetWidth()*.5,ofGetHeight()*.5),ofVec2f(0,0),ofVec2f(ofGetWidth(),ofGetHeight())));
    gui2.add(near.set( "apply level", 0, 0, 255 ));
    gui2.add(far.set( "depth level", 255, 0, 255 ));
    
    
    
    gui2.add(circleResolution.set("hands tracking", 5, 3, 90));
    gui2.add(twoCircles.setup("circle resolution"));
    gui2.add(ringButton.setup("vertex type"));
    gui2.add(screenSize.set("vertex range", ""));
    gui2.add(color.set("hands color",ofColor(100,100,140),ofColor(0,0),ofColor(255,255)));
    
    
    elapsedTime=0;
    
    int bufferSize=256;
    left.assign(bufferSize,0.0);
    soundStream.setup(this,0,2,44100,bufferSize,4);
    
    
    finder.setup("haarcascade_frontalface_alt.xml");
    
    lockon.loadImage("lockon.png");

    
    ofToggleFullscreen();
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();//kinectからのデータを更新
    
    img.setFromPixels(kinect.getPixels(), 640, 480, OF_IMAGE_COLOR);
    finder.findHaarObjects(img, 80, 80);
    
    
    volume =ofSoundGetSpectrum(1);
    elapsedTime++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    // ドラッグで視線を変更できるように(ofEasyCam)
    easyCam.begin();
    //    camera.begin();
    
    ofTranslate(-300, 0);//(カメラとの距離、オブジェクトの高さ)
    //ofRotate(rotate, 0, 1, 0);
    ofScale(1, 1, -1);
    
    ofPushMatrix();
    ofRotateY(135);
    
    //    camera.setFov(90);
    //    camera.lookAt(ofVec3f(0,0,0));
    //    camera.setPosition(820*cos(ofMap(ofGetElapsedTimeMillis(), 0, 6000, 0, PI)), ofGetElapsedTimeMillis()/1000, 820*sin(ofMap(ofGetElapsedTimeMillis(), 0, 6000, 0, PI)));
    
    
    //ポイントクラウドの描画
    drawPointCloud();
    //ofTranslate(-ofGetWidth()/2,0);//(横方向調整,縦方向調整);
    ofTranslate(0,0,ofGetHeight());
    ofSetColor(50, 50, 200,20);
//    ofDrawBox(0,0,0,ofGetWidth()/4,ofGetHeight(),5);
//    ofDrawBox(ofGetWidth()/4,0,0,10+3*ofGetWidth()/4,ofGetHeight(),5);
    ofDrawBox(0,0,0,ofGetWidth(),ofGetHeight(),5);
    //ofDrawBox(ofGetWidth()/2,-ofGetHeight()/4,0,ofGetWidth()/4,ofGetHeight()/4,5);
    ofSetColor(100,100,255);
    kinect.draw(-ofGetWidth()/3, -ofGetHeight()/3, ofGetWidth()/4, ofGetHeight()/4);
    kinect.drawDepth(-ofGetWidth()/3, ofGetHeight()/6, ofGetWidth()/4, ofGetHeight()/4);
    for (int i = 0; i < finder.blobs.size(); i++) {
        ofRectangle cur = finder.blobs[i].boundingRect;
        lockon.draw(cur.x-ofGetWidth()/3, cur.y-ofGetHeight()/3, cur.width, cur.height);
        //Rotateさせる
    }
    ofNoFill();
    
    //=----------Audio-------
    ofSetLineWidth(0.5);
    ofSetColor(255);
    slide++;
    if(slide==130)slide=0;
    ofBeginShape();
    for(int n=0; n< 1.5*left.size()/3; n++){
        ofVertex(-ofGetWidth()/2+30+n*10,-300-left[n+slide]*2000.0f);
    }
    ofEndShape(false);
    //=----------Audio-------
    
    ofSetColor(250, 0, 0,30);
    ofSetLineWidth(3);
    ofDrawBox(0,0,0,ofGetWidth()/2,ofGetHeight()/2,50);
    ofDrawBox(0,0,0,ofGetWidth(),ofGetHeight(),50);
    ofDrawBox(0,0,0,ofGetWidth()*1.5,ofGetHeight()*1.5,50);
    ofSetLineWidth(1);
    ofFill();
    ofColor(255);
        //ofxGuiを描画
    ofTranslate(ofGetHeight()/1.45,0,0);
    ofScale(1, -1, -1);
    gui.draw();
    ofScale(1, -1, -1);
    
    ofTranslate(-ofGetHeight()*1.8,0,0);
    ofScale(1, -1, -1);
    gui2.draw();
     ofScale(1, -1, -1);
    ofTranslate(ofGetHeight()*1.8,0,0);
    
    ofTranslate(-ofGetHeight()/1.45,0,0);
    
    ofTranslate(0,0,-ofGetHeight());
    //ofTranslate(ofGetWidth()/2,0);
    
    
    ofPopMatrix();
    easyCam.end();
    
    //    camera.end();
}
void ofApp::drawPointCloud() {
    // 画面の幅と高さ
    int w = 640;
    int h = 480;
    // メッシュを生成
    ofMesh mesh;
    if(mode==0){
        mesh.setMode(OF_PRIMITIVE_TRIANGLES );
    }else if(mode==1){
        mesh.setMode(OF_PRIMITIVE_LINES );
    }else{
        mesh.setMode(OF_PRIMITIVE_POINTS );
    }
    
    
    // 設定した間隔で、画面の深度情報と色を取得してメッシュの頂点に設定
    
    for(int y = 0; y < h; y += step) {
        for(int x = 0; x < w; x += step) {
            if(kinect.getDistanceAt(x, y) > 0) {
                mesh.addColor(kinect.getColorAt(x,y));
                mesh.addVertex(kinect.getWorldCoordinateAt(x, y));
                //ofDrawBitmapString("0", x,y,);
                //                    ofDrawBitmapString("pos_x"+ofToString(x), x,y);
                //                    ofDrawBitmapString("pos_y"+ofToString(y), x,y+10);
            }
        }
    }
    
    // メッシュの頂点を描画
    glPointSize(2);
    ofPushMatrix();
    ofScale(1, -1, -1);
    ofTranslate(0, 0, -1000);
    glEnable(GL_DEPTH_TEST);
    mesh.drawVertices();
    glDisable(GL_DEPTH_TEST);
    ofPopMatrix();
}

void ofApp::exit() {
    // Kinect終了
    kinect.close();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // 矢印キーでKinectの角度を操作
    switch (key) {
            
        case OF_KEY_UP:
            step +=2;
            break;
            
        case OF_KEY_DOWN:
            if(step>2){
                step -=2;
            }
            break;
        case OF_KEY_RETURN:
            mode=(mode+1)%3;
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
void ofApp::audioIn(float * input,int bufferSize,int nChannels){
    if(elapsedTime%8==0){
        for(int i=0; i<bufferSize; i++){
            left[i] =input[i*2]*0.5;
        }
    }
}
