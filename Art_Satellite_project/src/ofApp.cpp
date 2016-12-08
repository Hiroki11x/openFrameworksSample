#include "ofApp.h"
//bool SATERROR_OK = true;
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofSetFrameRate(30);
    ofEnableDepthTest();
    ofEnableLighting();
    light.setPosition(300, 200, 50);
    light.enable();
    
    
    ofBackground(0);
    ofSetFrameRate(30);
    // INVADERのセットアップ
//    if (invader.setNotifier(this) == SATERROR_OK) {
//        if (invader.setup() == SATERROR_OK) {
//            cout << "Hello ARTSAT." << endl;
//        }
//    }
}

//--------------------------------------------------------------
void ofApp::update(){
    bool result = response.open("http://api.artsat.jp/web/v2/invader/sensor_data.json");//Access ARTSAT WebAPI
    angleSpeed.x=response["results"][0]["sensors"]["ax"] ["value"].asFloat();
    angleSpeed.y=response["results"][0]["sensors"]["ay"]["value"].asFloat();
    angleSpeed.z=response["results"][0]["sensors"]["az"]["value"].asFloat();
    
    float sec = ofGetElapsedTimef();
    
//    // 現在の時刻を取得
//    current = ofxSATTime::currentTime();
//    // SGPに時間を設定
//    sgp.update(&current);
//    // 現在のPRISM衛星の3D座標を算出
//    position = sgp.getPos();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofSetColor(63);
    //ofDrawBitmapString(response.getRawString(), 10, 12);
    ofSetColor(255);
    
    
    int lineHeigt = 35;
    int startY =30;
    // JSONデータをパースして、画面に表示
    string available_time = response["results"][0] ["closest_available_time_iso_string"].asString();
    ofDrawBitmapString(available_time, startY, lineHeigt*1);
    
    //Latitude of an observer (degree)
    float lat = response["results"][0]["sensors"]["lat"] ["value"].asFloat();
    ofDrawBitmapString("lat = " + ofToString(lat,12), startY, lineHeigt*2);
    
    //Longitude of an observer (degree)
    float lon = response["results"][0]["sensors"]["lon"] ["value"].asFloat();
    ofDrawBitmapString("lon = " + ofToString(lon,12), startY, lineHeigt*3);
    
    //Altitude of an observer (meter)
    float alt = response["results"][0]["sensors"]["alt"] ["value"].asFloat();
    ofDrawBitmapString("alt = " + ofToString(alt,12), startY, lineHeigt*4);
    
    //Angular velocity　x
    float ax = response["results"][0]["sensors"]["ax"]["value"].asFloat();
    ofDrawBitmapString("ax = " + ofToString(ax,12), startY, lineHeigt*5);
    
    //Angular velocity y
    float ay = response["results"][0]["sensors"]["ay"]["value"].asFloat();
    ofDrawBitmapString("ay = " + ofToString(ay,12), startY, lineHeigt*6);
    
    //Angular velocity z
    float az = response["results"][0]["sensors"]["az"]["value"].asFloat();
    ofDrawBitmapString("az = " + ofToString(az,12), startY, lineHeigt*7);
     
     //Attitude velocity x
     float px = response["results"][0]["sensors"]["px"]["value"].asFloat();
     ofDrawBitmapString("px = " + ofToString(px,12), startY, lineHeigt*8);
     
     //Attitude velocity y
     float py = response["results"][0]["sensors"]["py"]["value"].asFloat();
     ofDrawBitmapString("py = " + ofToString(py,12), startY, lineHeigt*9);
     
     //Attitude velocity z
     float pz = response["results"][0]["sensors"]["pz"]["value"].asFloat();
     ofDrawBitmapString("pz = " + ofToString(pz,12), startY, lineHeigt*10);
     
     //magnetometric sensor x
     float mx = response["results"][0]["sensors"]["mx"]["value"].asFloat();
     ofDrawBitmapString("mx = " + ofToString(mx,12), startY, lineHeigt*11);
     
     //magnetometric sensor y
     float my = response["results"][0]["sensors"]["my"]["value"].asFloat();
     ofDrawBitmapString("my = " + ofToString(my,12), startY, lineHeigt*12);
     
     //magnetometric sensor z
     float mz = response["results"][0]["sensors"]["mz"]["value"].asFloat();
     ofDrawBitmapString("mz = " + ofToString(mz,12), startY, lineHeigt*13);
     
     //innner temperature
     float tin = response["results"][0]["sensors"]["tin"]["value"].asFloat();
     ofDrawBitmapString("tin = " + ofToString(tin,12), startY, lineHeigt*14);
    
    
    ofVec3f angle = angleSpeed*ofGetElapsedTimef();
    
    cam.begin();
    
    ofPushMatrix();
    ofRotateX(ofRadToDeg(angle.x));
    ofRotateY(ofRadToDeg(angle.y));
    ofRotateZ(ofRadToDeg(angle.z));
    
    ofBoxPrimitive box;
    box.draw();
    ofPopMatrix();
    
    cam.end();
//    int lineHeigt = 15;
//    int startY =30;
//    string available_time = response["results"][0] ["closest_available_time_iso_string"].asString();
//    ofDrawBitmapString(available_time, startY, lineHeigt*1);
//    
//    ofxJSONElement::Members mem = response["results"][0]["sensors"].getMemberNames();
//    for (int i = 0; i < mem.size(); i++) {
//        string lavel = mem[i]; float value = response["results"][0]["sensors"][mem[i]]["value"].asFloat();
//        ofDrawBitmapString(lavel + " = " + ofToString(value), 10, lineHeigt * (i + 3));
//    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
