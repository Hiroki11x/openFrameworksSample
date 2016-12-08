//
//  SideUIManager.hpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#ifndef SideUIManager_hpp
#define SideUIManager_hpp

#include "ofMain.h"
#include "GraphGuiComponent.hpp"
#include "TargetGuiComponent.hpp"
#include "RotateCircleGuiComponent.hpp"
#include "GridGuiComponent.hpp"
#include "CenterCircleGuiComponent.hpp"
#include "SideGuiComponent.hpp"

class SideUIManager{
private:
public:
    void init();
    void drawGui();
    void update();
    void initCenterCircle();

    GraphGuiComponent mGraphGui;
    RotateCircleGuiComponent mRotateCircleGui[3];
    GridGuiComponent mGridGui;
    CenterCircleGuiComponent mCenterCircleGui;
    SideGuiComponent mSideGui;
};

#endif /* SideUIManager_hpp */
