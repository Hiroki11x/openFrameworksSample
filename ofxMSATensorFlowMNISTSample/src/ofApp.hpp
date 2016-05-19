//
//  ofApp.hpp
//  example-mnist
//
//  Created by HirokiNaganuma on 2016/03/28.
//
//

#ifndef ofApp_hpp
#define ofApp_hpp

#include "ofMain.h"
#include "ofxMSATensorFlow.h"
#include "MousePainter.hpp"

class ofApp : public ofBaseApp {
public:
    
    // classifies pixels
    // check the src of this class (ofxMSATFImageClassifier) to see how to do more generic stuff with ofxMSATensorFlow
    msa::tf::ImageClassifier classifier;
    
    // simple visualization of weights layer,
    // only really meaningful on the single layer simple model
    // deeper networks need more complex visualization ( see http://arxiv.org/abs/1311.2901 )
    msa::tf::LayerVisualizer layer_viz;
    
    // class for painting with mouse, used as input image
    MousePainter mouse_painter;
    
    // which model to use
    bool use_deep_model;
    
    void init_classifier(bool use_deep_model);
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

};
#endif /* ofApp_hpp */
