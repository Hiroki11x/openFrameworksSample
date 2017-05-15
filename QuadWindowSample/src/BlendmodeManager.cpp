//
//  BlendmodeManager.cpp
//  ofxVJComponent
//
//  Created by HirokiNaganuma on 2016/05/29.
//
//

#include "BlendmodeManager.hpp"

void BlendmodeManager::init(){
    blendmodeIndex = 0;
}

void BlendmodeManager::nextIndex(){
    blendmodeIndex = (blendmodeIndex+1)%6;
    switch (blendmodeIndex) {
        case 0:
            ofEnableBlendMode(OF_BLENDMODE_ADD);
            cout << "OF_BLENDMODE_ADD" << endl;
            break;
        case 1:
            ofEnableBlendMode(OF_BLENDMODE_ALPHA);
            cout << "OF_BLENDMODE_ALPHA" << endl;
            break;
        case 2:
            ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
            cout << "OF_BLENDMODE_SUBTRACT" << endl;
            break;
        case 3:
            ofEnableBlendMode(OF_BLENDMODE_SCREEN);
            cout << "OF_BLENDMODE_SCREEN" << endl;
            break;
        case 4:
            ofEnableBlendMode(OF_BLENDMODE_DISABLED);
            cout << "OF_BLENDMODE_DISABLED" << endl;
            break;
        case 5:
            ofDisableBlendMode();
            cout << "OF_DISABLE_BLENDMODE" << endl;
            break;
        default:
            break;
    }
}

string BlendmodeManager::getBlendmodeName(){
    switch (blendmodeIndex) {
        case 0:
            return "OF_BLENDMODE_ADD";
            break;
        case 1:
            return "OF_BLENDMODE_ALPHA";
            break;
        case 2:
            return "OF_BLENDMODE_SUBTRACT";
            break;
        case 3:
            return  "OF_BLENDMODE_SCREEN";
            break;
        case 4:
            return "OF_BLENDMODE_DISABLED";
            break;
        case 5:
            return "OF_DISABLE_BLENDMODE";
            break;
        default:
            break;
    }
}