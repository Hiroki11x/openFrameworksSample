//
//  HeartRate.hpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/01.
//

#ifndef HeartRate_hpp
#define HeartRate_hpp

#include "ofMain.h"
#include "MacroManager.hpp"

class HeartRate{
public:
    HeartRate(){};
    static int update_counter;
    static vector<int> heart_rates;
    static void init();
    static void update(int new_value);
};

#endif /* HeartRate_hpp */
