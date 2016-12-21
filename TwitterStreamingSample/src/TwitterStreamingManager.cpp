//
//  TwitterStreamingManager.cpp
//  TwitterStreamingSample
//
//  Created by HirokiNaganuma on 12/21/16.
//
//

#include "TwitterStreamingManager.hpp"

//------------------------------------------------------------------------------------
void TwitterStreamingManager::setup(){

    //Twitter初期化はメインスレッドで行う
    if(TweetJsonReceiver::tweetData.size()>0)return;
    TweetJsonReceiver::getInstance().init();

    //別スレッドで画像読み込みも含めてデータ取得する
    ofxOpenGLContextScope::setup();
    mJsonReceieveThread.startThread();
}

//------------------------------------------------------------------------------------
void TwitterStreamingManager::exit(){
    mJsonReceieveThread.stopThread();
}