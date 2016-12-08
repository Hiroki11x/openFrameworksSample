#include "ofApp.h"
#include "ofxInkSim.h"
#include "ofxInkSim.h"

void ofApp::setup()
{
    ofSetFrameRate(5);
    inkSim.setup();
    gui.setup(inkSim.getUniformInfo());
    moodmachine.setSpeed(2.0);
    pdf.load("abe.pdf");
    
}

void ofApp::update(){
    inkSim.update();
}

void ofApp::draw(){
    inkSim.draw();
    gui.draw();
    drawArt();
    ofDrawBitmapStringHighlight("press ' ' to hide gui", 10, ofGetHeight() - 20);
}

void ofApp::mouseDragged(int x, int y, int button)
{
}

void ofApp::mouseReleased(int x, int y, int button)
{

}

void ofApp::keyPressed(int key)
{
    if (key == 'd')
    {
        inkSim.toggleDebug();
    }
    else if (key == ' ')
    {
        gui.toggleVisible();
    }
    else if (key == 'r')
    {
        gui.resetToDefault();
    }
    else if (key == 'c')
    {
        inkSim.clear();
    }
    else if(key == OF_KEY_RETURN){
        if(pdf.getNumPath()>nextChar){
            nextChar++;
        }
    }
}

void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}


void ofApp::drawArt(){
    float app_time = ofGetElapsedTimef();
    float animation_time = fmodf(app_time, 5) / 5;
    
    for (int i = 0; i < nextChar; i++){
        ofPath& path = pdf.getPathAt(i);
        
        vector<ofPolyline>& polys = path.getOutline();
        
        for (int k = 0; k < polys.size(); k++){
            ofPolyline poly = polys[k];
            
            poly = poly.getResampledByCount(100);//滑らかに描画
            
            int target_size = poly.size() * animation_time;//
            poly.resize(target_size);//更新
            
            vector<ofPoint> vec = poly.getVertices();
            for(int i=0 ;i<vec.size();i+=5){
                ofColor c = moodmachine;
                inkSim.stroke(&brush, vec.at(i).x, vec.at(i).y, getInkColor(c.getHueAngle(), 255, 10));
            }
        }
    }
}