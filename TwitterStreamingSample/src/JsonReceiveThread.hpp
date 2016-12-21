//
//  JsonReceiveThread.hpp
//  TwitterStreamingSample
//
//  Created by HirokiNaganuma on 12/21/16.
//
//

#ifndef JsonReceiveThread_hpp
#define JsonReceiveThread_hpp

#include "ofMain.h"
#include "TweetJsonReceiver.hpp"
#include "ofxOpenGLContextScope.h"

class JsonReceiveThread : public ofThread{

public:
    void threadedFunction(){
        ofxOpenGLContextScope scope;
        while (isThreadRunning()) {
            if(lock()){
                TweetJsonReceiver::getInstance().update();
                unlock();
                sleep(100);
            }
        }
    }
};

#endif /* JsonReceiveThread_hpp */
