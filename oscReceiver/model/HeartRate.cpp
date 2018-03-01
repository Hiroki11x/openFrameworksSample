//
//  HeartRate.cpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/01.
//

#include "HeartRate.hpp"

vector<int> HeartRate::heart_rates;
int HeartRate::update_counter;

void HeartRate::init(){
    HeartRate::update_counter = 0;
}

void HeartRate::update(int new_value){
    update_counter++;
    HeartRate::heart_rates.push_back(new_value);
    if(HeartRate::heart_rates.size() > MacroManager::max_buffer_size){
        HeartRate::heart_rates.erase(HeartRate::heart_rates.begin());
    }
}
