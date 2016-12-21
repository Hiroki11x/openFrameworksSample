//
//  TwitterStreamingManager.hpp
//  TwitterStreamingSample
//
//  Created by HirokiNaganuma on 12/21/16.
//
//

#ifndef TwitterStreamingManager_hpp
#define TwitterStreamingManager_hpp

#include "ofMain.h"
#include "TweetJsonReceiver.hpp"
#include "TweetData.hpp"
#include "ofxOpenGLContextScope.h"
#include "JsonReceiveThread.hpp"

class TwitterStreamingManager{
private:
    JsonReceiveThread mJsonReceieveThread;
public:
    void setup();
    void exit();
};
#endif /* TwitterStreamingManager_hpp */
