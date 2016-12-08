//
//  PinHoleManager.hpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#ifndef PinHoleManager_hpp
#define PinHoleManager_hpp

#include "ofMain.h"
#include "FontManager.hpp"

class PinHoleManager{
private:
    const static int size = 500;
public:
    static void drawCustomView(ofImage &img, string discription);
};

#endif /* PinHoleManager_hpp */
