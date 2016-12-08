//
//  SampleDataManager.hpp
//  ofxTerminalSample
//
//  Created by HirokiNaganuma on 2016/03/03.
//
//

#ifndef SampleDataManager_hpp
#define SampleDataManager_hpp

#include "ofMain.h"
#include "SampleData.hpp"

class SampleDataManager{
public:
    static int vertical_margin;
    static int sample_num;
    static int num_of_row;
    static float pivot;
    static float scroll_speed;
    static bool is_loop;
    static vector<SampleData> sampledata;
    
    void init();
    void update();
    void draw();
    float calc_optimize_pivot();

};

#endif /* SampleDataManager_hpp */
