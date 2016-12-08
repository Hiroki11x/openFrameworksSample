#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofSetFrameRate(20);
    //基本的な設定
    ofSetCircleResolution(64);
    //ofEnableDepthTest();
    ofSetVerticalSync(true);
   // gl(GL_DEPTH);
    
    
    video.loadMovie("earth.mov");
    video.setLoopState(OF_LOOP_NORMAL);
    video.play();
    
    timerFont.loadFont("FlopDesignFONT.otf", 15);
    CameraMode = false;
    CameraCursor = 0;
    
    //画像と、表示画像を準備
    string fileName = "0001.png";
    char char1[32];
    string nation[] = {"JPN","FRA","ESP","USA","JPN","UAE","IND","CHN","BRZ"};//国名は下に表示
    string time[] = {"12:00","11:00","10:00","10:30","11:30","13:00","14:00","13:30","14:30","15:00","9:30"};//時刻は上の左側
    string date[] = {"Aug 10 (Mon)","Aug 11 (Tue)","Aug 12 (Wed)","Aug 13 (Thu)","Aug 14 (Fri)"};//時刻は上の右側
    
    for(int i =0;i<32;i++){
        
        sprintf(char1, "%04d.png", i);
        fileName = ofToString(char1);
        
        commentView.push_back(new CommentView());
        float radius = ofRandom(550,780);
        float angle = ofRandom(2*PI);
//        float aim_x = ofRandom(-ofGetWidth()/1.5,ofGetWidth()/1.5);
//        float aim_y = ofRandom(-ofGetHeight()/1.5,ofGetHeight()/1.5);
        
        commentView.back()->setAngle(angle);
        
        float aim_x = radius*cos(angle);
        float aim_y = radius*sin(angle);
        
        commentView.back()->setAimPosition(aim_x,aim_y);
        commentView.back()->setCenterPosition(0,0);
        commentView.back()->setSize(ofRandom(100,140));
        commentView.back()->setImage(fileName);//setするイメージ画像のファイル名をセット(連番に設定)
        commentView.back()->setString(time[i%(sizeof(time)/sizeof(time[0]))]
                                      +date[i%(sizeof(date)/sizeof(date[0]))],
                                      nation[i%(sizeof(nation)/sizeof(nation[0]))]);//表示する文字列をセット
        
        commentView.back()->setSpeed(aim_x/1024,aim_y/1024);//初期速度を差分で設定
        commentView.back()->setViewColor(ofColor::fromHsb(ofRandom(255), ofRandom(140,190), 255));//ざわっちさんカラー
    }
    ofToggleFullscreen();
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    
    if(ofGetElapsedTimef()>12){//10秒後からアニメーション実行
        for(int i =0;i<commentView.size();i++){
            commentView.at(i)->update();//速度によって更新、目標点に近づくほど減速
        }
        if(ofGetFrameNum()*2<300){
            cam.setPosition(0,0, 500+ofGetFrameNum()*2);
        }else{
            cam.setPosition(0,0,800+100*sin((float)ofGetFrameNum()/60));
            //cam.setPosition(0,0,(ofGetFrameNum()-12*20)*20);
        }
    }
    
    if(CameraMode){//Enterの入力で変える(あるcommentViewを見るモード)
//        cam.setPosition(CameraX,CameraY,800+100*sin((float)ofGetFrameNum()/60));
        cam.setPosition(CameraX,CameraY,CameraZ);
        cam.lookAt(ofVec3f(commentView.at(CameraCursor%commentView.size())->center_x,commentView.at(CameraCursor%commentView.size())->center_y,0));
    }else{//中心を向くモード
        cam.lookAt(ofVec3f(0,0,0));
    }
     
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofBackground(59,166,246);
    ofBackground(255);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    
    cam.begin();
    ofSetColor(255);
    video.draw(-video.width/12, -video.height/12,video.width/6,video.height/6);
    ofSetColor(100,100);
    ofRect(-63, 0, 140, 27);
    ofSetColor(0);
    
    //タイマー表示
    timerFont.drawString(ofToString(ofGetHours())+":"+ofToString(ofGetMinutes())+":"+ofToString(ofGetSeconds())+":"+ofToString(ofGetElapsedTimeMillis()%60), -50, 0);
    
    
    //線の描画、CommentViewの描画
    if(ofGetElapsedTimef()>12){
        ofSetColor(100);
        for(int i =0;i<commentView.size();i++){
            float pivotX = 80*cos(commentView.at(i)->angle);
            float pivotY = 80*sin(commentView.at(i)->angle);
            ofLine(pivotX,pivotY,commentView.at(i)->center_x,commentView.at(i)->center_y);//中心からの線
        }
        for(int i =0;i<commentView.size();i++){
            commentView.at(i)->draw();
        }
    }else{
        
    }
    cam.end();
    ofSetColor(0);
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    ofDrawBitmapString("ENTER: "+ofToString(CameraMode), 20,15);
    ofDrawBitmapString("SHIFT: "+ofToString(CameraCursor%commentView.size()), 20,30);
    ofDrawBitmapString("RIGHT/LEFT: "+ofToString(CameraX), 20,45);
    ofDrawBitmapString("UP/DOWN: "+ofToString(CameraY), 20,60);
    ofDrawBitmapString("ALT/COMMAND: "+ofToString(CameraZ), 20,75);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key==OF_KEY_RIGHT_SHIFT){
        CameraCursor++;
    }else if(key == OF_KEY_RETURN){
        CameraMode = (!CameraMode);
    }
    
    if(key==OF_KEY_UP){
        CameraY+=25;
    }else if(key==OF_KEY_DOWN){
        CameraY-=25;
    }
    
    if(key==OF_KEY_LEFT){
        CameraX-=25;
    }else if(key==OF_KEY_RIGHT){
        CameraX+=25;
    }
    
    if(key==OF_KEY_ALT){
        CameraZ-=25;
    }else if(key==OF_KEY_COMMAND){
        CameraZ+=25;
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
