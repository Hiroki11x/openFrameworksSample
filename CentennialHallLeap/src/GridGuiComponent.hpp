//
//  GridGuiComponent.hpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#ifndef GridGuiComponent_hpp
#define GridGuiComponent_hpp

#include "ofMain.h"
#include "ColorManager.hpp"

class GridGuiComponent{
private:
    ofColor backCrossColor = ofColor(ColorManager::maincolor.x,
                                     ColorManager::maincolor.y,
                                     ColorManager::maincolor.z,
                                     ColorManager::maincolor.w);
public:
    void draw();
};


#endif /* GridGuiComponent_hpp */
