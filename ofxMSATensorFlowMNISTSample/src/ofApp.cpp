//
//  ofApp.cpp
//  example-mnist
//
//  Created by HirokiNaganuma on 2016/03/28.
//
//

#include "ofApp.hpp"
    
    //--------------------------------------------------------------
// 分類器 の初期化
void ofApp::init_classifier(bool use_deep_model) {
        this->use_deep_model = use_deep_model;
        
        // initialize the image classifier, lots of params to setup
        // イメージの分類器の初期化、よくわからないけどたくさんSettingとかいうのを初期化する
        msa::tf::ImageClassifier::Settings settings;
   
        settings.image_dims = { 28, 28, 1 };
        settings.itensor_dims = { 1, 28 * 28 };
        settings.labels_path = "";
        settings.input_layer_name = "x_inputs";
        settings.output_layer_name = "y_outputs";
        settings.dropout_layer_name = "";
        settings.varconst_layer_suffix = "_VARHACK";
        settings.norm_mean = 0;
        settings.norm_stddev = 0;
        
        // settings which are specific to the individual models
        // この関数の引数がtrueの時は、deep_modelと言うのを使うらしい
        if(use_deep_model) {
            settings.model_path = "model-deep/mnist-deep.pb";   // load appropiate model file
            settings.dropout_layer_name = "keep_prob";    // this model has dropout, so need to set keep probability to 1.0
        } else {
            // そうでない時はsimpleモデルらしい
            settings.model_path = "model-simple/mnist-simple.pb";   // load appropiate model file
            settings.dropout_layer_name = "";   // this model doesn't have dropout, so ignore
        }
        
        // initialize classifier with these settings
        // 分類器をSettingをもとに初期化
        classifier.setup(settings);
        
        // initialize layer visualizer
        // layer-visualizerというGUIっぽいのを初期化してるらしい
        layer_viz.setup(classifier.getSession(), classifier.getGraphDef(), "VIZ_VARHACK");
    }
    
    
    //--------------------------------------------------------------
void ofApp::setup() {
        ofLogNotice() << "Initializing... ";
        ofBackground(50);
        ofSetVerticalSync(true);
        
        // setup mouse painter
        // mouse_painterを初期化
        mouse_painter.setup(256);
        
        // initialize classifier
        // 分類器を初期化
        init_classifier(true);
        
        ofLogNotice() << "Init successfull";
    }
    
    
    //--------------------------------------------------------------
void ofApp::update() {
        if(classifier.isReady()) {//識別器が準備できたら
            classifier.classify(mouse_painter.get_pixels());//手書き文字をpixel列として入力
        }
    }
    
    
    //--------------------------------------------------------------
void ofApp::draw() {
        // draw mouse painter
        mouse_painter.draw();//手書き文字を入力する
        
        stringstream str_outputs;
    
        //識別器の準備ができてる^何らかの分類結果が出ると
        if(classifier.isReady() && classifier.getNumClasses() > 0) {
            
            float cur_y = mouse_painter.getHeight() + 10;
            ofSetColor(255);
            
            // DRAW LAYER PARAMETERS (only really useful for the single layer version, deeper networks need more complex visualization)
            // よく分からないけど、layerを描画？
            // もやもやしてるとこ
            cur_y += layer_viz.draw(0, cur_y, ofGetWidth());
            
            
            // 出力のバーの描画
            float box_spacing = ofGetWidth() / classifier.getNumClasses();
            float box_width = box_spacing * 0.8;
            
            for(int i=0; i<classifier.getNumClasses(); i++) {
                float p = classifier.getClassProbs()[i]; // probability of this label
                
                // 可能性の棒を描画
                float h = (ofGetHeight() - cur_y) * p;
                float x = ofMap(i, 0, classifier.getNumClasses()-1, 0, ofGetWidth() - box_spacing);
                x += (box_spacing - box_width)/2;
                
                // 可能性のパーセンテージを四角形で描画
                ofSetColor(ofLerp(50.0, 255.0, p), ofLerp(100.0, 0.0, p), ofLerp(150.0, 0.0, p));
                ofDrawRectangle(x, ofGetHeight(), box_width, -h);
                
                str_outputs << ofToString(classifier.getClassProbs()[i], 3) << " ";
                
                // draw text
                ofDrawBitmapString(ofToString(i) + ": " + ofToString(p, 2), x, ofGetHeight() - h - 10);
            }

            
            // 棒の上限の線を描画
            ofSetColor(200);
            ofDrawLine(0, cur_y, ofGetWidth(), cur_y);
        }
    
    
        // 情報を描画
        stringstream str;
        str << "Paint in the box" << endl;
        str << "Rightclick to erase" << endl;
        str << "'c' to clear" << endl;
        str << endl;
        str << "'m' to toggle model. Currently using " << classifier.settings.model_path << endl;
        str << endl;
        str << "Outputs: " << str_outputs.str() << endl;
        str << endl;
        str << "fps: " << ofToString(ofGetFrameRate(), 2) << endl;
        
        ofSetColor(255);
        ofDrawBitmapString(str.str(), mouse_painter.getWidth() + 20, 30);
    }
    
    //--------------------------------------------------------------
void ofApp::keyPressed(int key) {
        switch(key) {
            // 描画してるものをclear
            case 'c': mouse_painter.clear(); break;
            // deep_model,simple_modelをセットしなおす
            case 'm': init_classifier( !use_deep_model); break; // toggle model between deep and simple
        }
    }
    
    //--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
        // Dragする時、MousePainter#penDragメソッドで、それをMousePainterに入力
        mouse_painter.penDrag(ofVec2f(x, y), button==2);
    }
    
    //--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
        // Pressした時、MousePainter#penDownメソッドで、それをMousePainterに入力
        mouse_painter.penDown(ofVec2f(x, y), button==2);
    }
    
    //--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
        // Releadeした時、MousePainter#penUpメソッドで、それをMousePainterに入力
        mouse_painter.penUp();
    }

