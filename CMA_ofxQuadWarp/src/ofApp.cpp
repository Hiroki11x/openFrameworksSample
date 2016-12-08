#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(50);
    ofSetFrameRate(30);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetCircleResolution(30);

    
    video[0].loadMovie("m3.mov");
//    video[1].loadMovie("m4.mov");
    video[2].loadMovie("m5.mov");
    video[0].setLoopState(OF_LOOP_NORMAL);
//    video[1].setLoopState(OF_LOOP_NORMAL);
    video[2].setLoopState(OF_LOOP_NORMAL);
    
    int x = 0;
    int y = 0;
    for (int i=0; i<NUM; i++) {
        w[i] = 300;
        h[i] = 300;
//        cout<<"w[i] "<<w[i] <<endl;
//        cout<<"h[i] "<<h[i] <<endl;
        
        fbo[i].allocate(w[i], h[i]);
        
        warper[i].setSourceRect( ofRectangle( 0, 0, w[i], h[i] ) );
        warper[i].setTopLeftCornerPosition( ofPoint( x, y ) );
        warper[i].setTopRightCornerPosition( ofPoint( x + w[i], y ) );
        warper[i].setBottomLeftCornerPosition( ofPoint( x, y + h[i] ) );
        warper[i].setBottomRightCornerPosition( ofPoint( x + w[i], y + h[i] ) );
        warper[i].setup();
        
        x+=105;
        y+=105;
    }
    video[0].play();
//    video[1].play();
    video[2].play();
}

//--------------------------------------------------------------
void ofApp::update(){
    video[0].update();
//    video[1].update();
    video[2].update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    warperDraw();//これで実際に描画するものを準備
    
    for (int i=0; i<NUM; i++){
        
        ofSetColor(255);
        
        ofMatrix4x4 mat = warper[i].getMatrix();
        ofPushMatrix();
        ofMultMatrix(mat.getPtr());
//        glMultMatrixf(mat.getPtr());
        fbo[i].draw(0, 0);
        
        ofPopMatrix();
        
        ofSetColor(100);
        ofSetLineWidth(2);
        warper[i].draw();
        
        ofSetColor(ofColor::magenta);
        warper[i].drawQuadOutline();
        
        ofSetColor(ofColor::yellow);
        warper[i].drawCorners();
        
        ofSetColor(ofColor::magenta);
        warper[i].drawHighlightedCorner();
        
        ofSetColor(ofColor::red);
        warper[i].drawSelectedCorner();
    }
    
    ofCircle(mouseX,mouseY,ofRandom(1,10));
    
}

void ofApp::warperDraw() {
    for (int i=0; i<NUM; i++){
        fbo[i].begin();
        //************ここにi番目の描画するものを書く*************//
        switch (i) {
            case 0:
                ofSetColor(255);
                video[0].draw(0, 0,300,300);
                break;
                
            case 1:
                ofClear(255, 0);//これがないとfboにずっと上書きされ続ける
                ofSetColor(255);
                ofRect(0,0,300,300);
                for(int j=0;j<100;j++){
                    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
                    ofCircle(ofRandom(0,w[i]), ofRandom(0,h[i]), ofRandom(5,20));
                }
                break;
                
            case 2:
                ofClear(255, 0);//これがないとfboにずっと上書きされ続ける
                ofSetColor(125);
                ofRect(0,0,300,300);
                for(int j=0;j<10;j++){
                    ofSetColor(ofColor::fromHsb(ofGetFrameNum()%256, 255, 255));
                    ofLine(ofRandom(0,w[i]), ofRandom(0,h[i]),ofRandom(0,w[i]), ofRandom(0,h[i]));
                }
                break;
                
            case 3:
                ofClear(255, 0);//これがないとfboにずっと上書きされ続ける
                ofSetColor(5*ofGetFrameNum()%256);
                ofRect(0,0,300,150);
                ofSetColor((127+5*ofGetFrameNum())%256);
                ofRect(0,150,300,150);
                break;
                
            case 4:
                ofSetColor(255);
                video[2].draw(0, 0,300,300);
                break;
                
//            case 5:
//                ofSetColor(255);
//                video[2].draw(0, 0,300,300);
//                break;
                
            default:
                break;
        }
        //************ここにi番目の描画するものを書く*************//
        fbo[i].end();
    }
}

void ofApp::exit() {
    for (int i=0; i<NUM; i++){
        warper[i].save();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 's' ){
        for (int i=0; i<NUM; i++) {
            warper[i].toggleShow();
        }
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
