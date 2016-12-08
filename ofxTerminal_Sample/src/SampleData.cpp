//
//  SampleData.cpp
//  ofxTerminalSample
//
//  Created by HirokiNaganuma on 2016/03/03.
//
//

#include "SampleData.hpp"

void SampleData::draw(float x, float y){
    ofDrawBitmapString(ofToString(this->id)+" "+this->name, x, y);
}

string SampleData::generate_random_name(int i_rand){
    srand((unsigned)time(NULL));
    char c[LENGTH];
    char material[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for(int i=0;i<LENGTH-1;i++){
        srand(ofGetElapsedTimeMillis()*i+ofRandom(100)*i_rand);
        c[i] = material[rand()%(sizeof(material)-1)];
    }
    string result = c;
    return result;
}

string SampleData::digit_string(int num, int digit) {
    char c[32];
    sprintf(c, "%d", num);
    string result = c;
    while (result.length() < digit) {
        result = "0" + result;
    }
    return result;
}