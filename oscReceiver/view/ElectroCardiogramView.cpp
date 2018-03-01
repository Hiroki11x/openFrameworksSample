//
//  ElectroCardiogramView.cpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/01.
//

#include "ElectroCardiogramView.hpp"

void ElectroCardiogramView::init(){
    ofBackground(0);
    ofNoFill();
    ofSetLineWidth(1.0);
    ofSetColor(255);
}

void ElectroCardiogramView::update(){

}

void ElectroCardiogramView::draw(){
    ofPushMatrix();

    ofDrawRectangle(50,50,ofGetWidth()-100,ofGetHeight()-100);

    ofBeginShape();
    for(int i = 0 ; i < HeartRate::heart_rates.size(); i++){
        ofVertex(ofMap(i, 0, MacroManager::max_buffer_size, 50+50,ofGetWidth()-100-50),
                 ofMap(HeartRate::heart_rates.at(i), MacroManager::heart_rate_max, MacroManager::heart_rate_min, 50+50, ofGetHeight()-100-50));
    }
    ofEndShape();


    for(int i = 0 ; i < HeartRate::heart_rates.size(); i++){
        ofDrawCircle(ofMap(i, 0, MacroManager::max_buffer_size, 50+50,ofGetWidth()-100-50),
                     ofMap(HeartRate::heart_rates.at(i), MacroManager::heart_rate_max, MacroManager::heart_rate_min, 50+50, ofGetHeight()-100-50),
                     5);
        ofDrawBitmapString(ofToString(HeartRate::heart_rates.at(i)),
                           ofMap(i, 0, MacroManager::max_buffer_size, 50+50,ofGetWidth()-100-50),
                           ofMap(HeartRate::heart_rates.at(i), MacroManager::heart_rate_max, MacroManager::heart_rate_min, 50+50, ofGetHeight()-100-50));
    }

    ofPopMatrix();
}
