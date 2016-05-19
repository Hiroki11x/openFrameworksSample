//
//  SampleData.hpp
//  ofxTerminalSample
//
//  Created by HirokiNaganuma on 2016/03/03.
//
//

#ifndef SampleData_hpp
#define SampleData_hpp

#include "ofMain.h"

class SampleData{
private:
    const int LENGTH = 10;
public:
    SampleData(int i){
        this->id = digit_string(ofRandom(9000)+i, 5);
        this->name = generate_random_name(i);
    }
    string id;
    string name;
    string generate_random_name(int i_rand);
    string digit_string(int num, int digit);
    void draw(float x, float y);
};

#endif /* SampleData_hpp */
