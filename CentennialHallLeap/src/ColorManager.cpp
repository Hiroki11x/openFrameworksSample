//
//  ColorManager.cpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/9/16.
//
//

#include "ColorManager.hpp"

ofVec4f ColorManager::maincolor;
ofVec4f ColorManager::floatcolor;

void ColorManager::init(){
//    maincolor = ofVec4f(255,50,120,220);
//    floatcolor = ofVec4f(1,.2,.47,0.86);
    maincolor = ofVec4f(0,250,120,220);
    floatcolor = ofVec4f(.1,.8,.47,0.86);
}