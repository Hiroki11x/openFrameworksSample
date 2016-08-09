//
//  testApp.hpp
//  mySketch
//
//  Created by HirokiNaganuma on 2016/08/09.
//
//

#ifndef testApp_hpp
#define testApp_hpp

#include "ofMain.h"
class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    ofBoxPrimitive mBox[100];
    bool b_switch;
};
#endif /* testApp_hpp */
