//
//  OSCManager.hpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/01.
//

#ifndef OSCManager_hpp
#define OSCManager_hpp

#include "ofMain.h"
#include "ofxOsc.h"
#include "MacroManager.hpp"
#include "HeartRate.hpp"

class OSCManager{
public:
    static ofxOscReceiver receiver;
    static ofxOscMessage message;
    static int buf;
    static string latest_updated_time;
    static void setup();
    static void update();
    static void draw();
};

#endif /* OSCManager_hpp */
