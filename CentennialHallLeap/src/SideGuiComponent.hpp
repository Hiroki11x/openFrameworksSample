//
//  SideGuiComponent.hpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#ifndef SideGuiComponent_hpp
#define SideGuiComponent_hpp

#include "ofMain.h"
#include "ofxPDF.h"
#include "ColorManager.hpp"

class SideGuiComponent{
private:
    int index;
    ofxPDF mPDF;
    ofPath mPath;
public:
    void load(string path);
    void init();
    void update();
    void draw();
};

#endif /* SideGuiComponent_hpp */
