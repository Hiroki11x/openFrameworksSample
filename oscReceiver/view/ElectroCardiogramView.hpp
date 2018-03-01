//
//  ElectroCardiogramView.hpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/01.
//

#ifndef ElectroCardiogramView_hpp
#define ElectroCardiogramView_hpp

#include "ofMain.h"
#include "HeartRate.hpp"

class ElectroCardiogramView{
public:
    static void init();
    static void update();
    static void draw();
};

#endif /* ElectroCardiogramView_hpp */
