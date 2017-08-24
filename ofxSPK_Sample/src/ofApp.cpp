//
//  ofApp.cpp
//  example-pointsprite
//
//  Created by HirokiNaganuma on 8/24/17.
//
//

#include "ofApp.h"

#include "ofxSPK.h"

ofxSPK::System sys;
ofxSPK::Group group;

ofImage sprite;

ofxSPK::Modifier rot;

//--------------------------------------------------------------
void ofApp::setup()
{
    // setup pointsprite texture
    // NOTES: the texture size must be Power of Two,
    // and turn off arb texture option while loading
    ofDisableArbTex();
    sprite.loadImage("image.jpg");
    ofEnableArbTex();

    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);

    sys.setup();

    group.setup(sys);
    group.setColor(ofxSPK::RangeC(ofColor(255, 255), ofColor(255, 255)),
                   ofxSPK::RangeC(ofColor(0, 0), ofColor(255, 0)));

    group.setLifeTime(0.5, 5);
    group.setFriction(0.1);
    group.setSize(0, ofxSPK::RangeF(30, 250));

    group.setGravity(ofVec3f(0, -10, 0));
    group.setMass(0.1, 1);

    rot.setup(SPK::Vortex::create(SPK::Vector3D(ofGetWidth()/2, ofGetHeight()/2),
                                  SPK::Vector3D(0, 1, 0),
                                  200,
                                  10), group);

    group.reserve(10000);
}

//--------------------------------------------------------------
void ofApp::update()
{
    group.emitRandom(10, ofVec3f(ofGetMouseX(), ofGetMouseY()));

    sys.update();

    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofEnableBlendMode(OF_BLENDMODE_ADD);

    // sys.debugDraw();

    // bind texture, enable point sprite while drawing particles
    sprite.bind();
    ofEnablePointSprites();
    sys.draw();
    ofDisablePointSprites();
    sprite.unbind();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
    
}
