//
//  OSCManager.cpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/01.
//

#include "OSCManager.hpp"

ofxOscReceiver OSCManager::receiver;
ofxOscMessage OSCManager::message;

// 表示するデータ
int OSCManager::buf;

// OSC最終受信時刻を保持
string OSCManager::latest_updated_time;

//--------------------------------------------------------------
void OSCManager::setup(){
    // receriver初期化
    receiver.setup(MacroManager::osc_port_num);

    // windowのtitleを設定
    ofSetWindowTitle("listening for osc messages on port" + ofToString(MacroManager::osc_port_num));

    // OSC listen on the given port
    cout << "listening for osc messages on port " << MacroManager::osc_port_num << "\n";

    // OSC最終受信時刻の初期化
    latest_updated_time = "";
}

//--------------------------------------------------------------
void OSCManager::update(){

    receiver.getNextMessage(message);
    //untill all address of osc are got.

    if(message.getAddress() == "/data"){

        // OSCでデータを取得
        // OSC最終受信時刻の取得
        string osc_update_time = message.getArgAsString(1);

        // OSCの受信時刻が更新された場合、それは新しい値なので心拍数のupdate
        if(osc_update_time != latest_updated_time){

            // 受信時刻更新
            latest_updated_time = osc_update_time;

            // 心拍数の更新
            int osc_input_data = message.getArgAsInt(0);
            OSCManager::buf = osc_input_data;
            HeartRate::update(osc_input_data);
        }
    }
};


//--------------------------------------------------------------
void OSCManager::draw(){
    // OSCで取得したデータを表示
    ofDrawBitmapString(ofToString(buf) + " / num of data :" + ofToString(HeartRate::heart_rates.size()), 10, 20);
}
