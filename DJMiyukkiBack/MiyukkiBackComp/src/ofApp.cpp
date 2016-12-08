#include "ofApp.h"
#define NUM 2000
#define DISTANCE 1000000000
int x[NUM];
int y[NUM];
int z[NUM];
int size[NUM];
bool change;
//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(10, 10, 90);
	
	cameraRotation.set(0);//cameraRotationは三次元ベクトル(スカラーがここではセットされている)
	zoom = -500;//zoomをz軸方向の基準座標系として使う
	zoomTarget = 200;//keyEventでカメラを近づけたりする際にzoomに影響を及ぼす
	
	ofDisableArbTex();
	ofEnableAlphaBlending();
    ofToggleFullscreen();
    ofSetFrameRate(100);
    change=false;
    
    //locating boxes
    for(int i=0;i<NUM;i++){
        x[i] = ofRandom(-ofGetWidth(),ofGetWidth());
        y[i] = ofRandom(-ofGetWidth(),ofGetWidth());
        z[i] = ofRandom(-ofGetWidth(),ofGetWidth());
        size[i]=ofRandom(5,12);
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    
    zoomTarget=mouseX;

	// move the camera around
	float mx = (float)mouseX/(float)ofGetWidth();
	float my = (float)mouseY/(float)ofGetHeight();
	ofVec3f des(mx * 360.0, my * 360.0, 0);
	cameraRotation += (des-cameraRotation) * 0.05;//三次元ベクトルcameraRotationに現在地に依存する三次元ベクトルの影響を及ぼす
	zoom += (zoomTarget - zoom) * 0.05;
    
    if((mouseX-ofGetWidth()/2<=0)&&(change==false)){
        change=true;
    }else if((mouseX-ofGetWidth()/2>0)&&(change==true)){
        change=false;
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0,5,20);
	
	ofSetColor(255);
	
	ofPushMatrix();
    
    if(change==false){
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 1200-zoom);
        ofRotate(cameraRotation.x, 0, 1, 0);//横回転(mouseXに連動)
    }else if(change==true){
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2, zoom-50);
        ofRotate(cameraRotation.x, 0, 1, 0);//横回転(mouseXに連動)
    }
    
    
	//ofRotate(cameraRotation.x, 0, 1, 0);//横回転(mouseXに連動)
	ofRotate(cameraRotation.y, 1, 0, 0);//縦回転(mouseYに連動)
	//ofRotate(cameraRotation.y, 0, 0, 1);//円回転(mouseYに連動)
    //ofNoFill();
    //ofDrawSphere(0,0,20);
    
    ofSetColor(250,0,0);
    //ofLine(-1*DISTANCE, 0,0, DISTANCE, 0,0);//x軸
    //ofLine(0, -1*DISTANCE, 0,0, DISTANCE,0);//y軸
    //ofLine(0, 0, -1*DISTANCE,0, 0,DISTANCE);//z軸
    
    float hue = fmodf(ofGetElapsedTimef()*10,255);//経過時間のパラメータから255を法としたmodを取る
    
    //ofNoFill();
    for(int i=0;i<NUM;i++){
        ofTranslate(x[i], y[i],z[i]);
        
        
        ofColor c;
        // the range of each of the arguments here is 0..255 so we map i and j to that range.
        c.setHsb( hue, ofRandom(150,255), ofRandom(100,205) );
        //(色相,彩度,輝度)
        
        // assign the color and draw a rectangle
        ofSetColor( c );
        
        ofDrawBox(size[i]);
        ofTranslate(-x[i], -y[i],-z[i]);
    }
	
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	if(key == 'f') ofToggleFullscreen();
	if(key == OF_KEY_UP) zoomTarget +=20;
	if(key == OF_KEY_DOWN) zoomTarget -=20;
    if(key=='a'){
    }
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
