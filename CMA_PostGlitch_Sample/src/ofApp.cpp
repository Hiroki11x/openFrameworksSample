
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    camera.setDistance(400);
    ofSetCircleResolution(3);
    
    lenna.loadImage("lenna.png");
    bDrawLenna = false;
    bShowHelp  = true;
    myFbo.allocate(512, 512);
    
    myGlitch.setup(&myFbo);
    
    shaderSwitch=false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    myFbo.begin();
    ofClear(0, 0, 0,255);
    if (!bDrawLenna){
        camera.begin();
        
        for (int i = 0;i < 100;i++){
            if		(i % 5 == 0)ofSetColor(50 , 255, 100);
            else if (i % 9 == 0)ofSetColor(255, 50, 100);
            else				ofSetColor(255, 255, 255);
            
            ofPushMatrix();
            ofRotate(ofGetFrameNum(), 1.0, 1.0, 1.0);
            ofTranslate((ofNoise(i/2.4)-0.5)*1000,
                        (ofNoise(i/5.6)-0.5)*1000,
                        (ofNoise(i/8.2)-0.5)*1000);
            ofCircle(0, 0, (ofNoise(i/3.4)-0.5)*100+ofRandom(3));
            ofPopMatrix();
        }
        
        camera.end();
    }else{
        ofSetColor(255);
        lenna.draw(0, 0);
    }
    myFbo.end();
    
    if(shaderSwitch){
        shaderIndex=ofRandom(1,10);
        if(ofGetElapsedTimeMillis()%1000<300){
            if (shaderIndex == 1) myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, true);
            if (shaderIndex == 2) myGlitch.setFx(OFXPOSTGLITCH_GLOW			, true);
            if (shaderIndex == 3) myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, true);
            if (shaderIndex == 4) myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, true);
            if (shaderIndex == 5) myGlitch.setFx(OFXPOSTGLITCH_TWIST			, true);
            if (shaderIndex == 6) myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, true);
            if (shaderIndex == 7) myGlitch.setFx(OFXPOSTGLITCH_NOISE			, true);
            if (shaderIndex == 8) myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, true);
            if (shaderIndex == 9) myGlitch.setFx(OFXPOSTGLITCH_SWELL			, true);
            if (shaderIndex == 10) myGlitch.setFx(OFXPOSTGLITCH_INVERT			, true);
            
//            if (shaderIndex == 11) myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
//            if (shaderIndex == 12) myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, true);
//            if (shaderIndex == 13) myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, true);
//            if (shaderIndex == 14) myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, true);
//            if (shaderIndex == 15) myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, true);
//            if (shaderIndex == 16) myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, true);
//            if (shaderIndex == 17) myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, true);
        }else{
            if (shaderIndex == 1) myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
            if (shaderIndex == 2) myGlitch.setFx(OFXPOSTGLITCH_GLOW			, false);
            if (shaderIndex == 3) myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
            if (shaderIndex == 4) myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
            if (shaderIndex == 5) myGlitch.setFx(OFXPOSTGLITCH_TWIST			, false);
            if (shaderIndex == 6) myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, false);
            if (shaderIndex == 7) myGlitch.setFx(OFXPOSTGLITCH_NOISE			, false);
            if (shaderIndex == 8) myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
            if (shaderIndex == 9) myGlitch.setFx(OFXPOSTGLITCH_SWELL			, false);
            if (shaderIndex == 10) myGlitch.setFx(OFXPOSTGLITCH_INVERT			, false);
            
//            if (shaderIndex == 11) myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
//            if (shaderIndex == 12) myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
//            if (shaderIndex == 13) myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
//            if (shaderIndex == 14) myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
//            if (shaderIndex == 15) myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
//            if (shaderIndex == 16) myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
//            if (shaderIndex == 17) myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);
        }
    }
    else{
        myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
        myGlitch.setFx(OFXPOSTGLITCH_GLOW			, false);
        myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
        myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
        myGlitch.setFx(OFXPOSTGLITCH_TWIST			, false);
        myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, false);
        myGlitch.setFx(OFXPOSTGLITCH_NOISE			, false);
        myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
        myGlitch.setFx(OFXPOSTGLITCH_SWELL			, false);
        myGlitch.setFx(OFXPOSTGLITCH_INVERT			, false);
        
        myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
        myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
        myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
        myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
        myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
        myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
        myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    /* draw normal view */
    ofSetColor(255);
    
    ofPixels pix;
//    myFbo.readToPixels(pix);
//    pix.draw(0, 0);
    
    /* Apply effects */
    myGlitch.generateFx();
    
    /* draw effected view */
    ofSetColor(255);
    myFbo.draw(512, 0);
    
    
    /* show information*/
    string info = "";
    info += "1 - 0 : Apply glitch effects.\n";
    info += "q - u : Apply color remap effects.\n";
    info += "L key : Switch 3Dview / 2DImage.\n";
    info += "H key : Hide or show this information.";
    
    if (bShowHelp){
        ofSetColor(0, 200);
        ofRect(25, 17, 320, 60);
        ofSetColor(255);
        ofDrawBitmapString(info, 30,30);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==' '){
        shaderSwitch=!shaderSwitch;
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