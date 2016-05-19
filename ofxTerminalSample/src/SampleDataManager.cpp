//
//  SampleDataManager.cpp
//  ofxTerminalSample
//
//  Created by HirokiNaganuma on 2016/03/03.
//
//

#include "SampleDataManager.hpp"

int SampleDataManager::vertical_margin;
int SampleDataManager::sample_num;
int SampleDataManager::num_of_row;
float SampleDataManager::pivot;
float SampleDataManager::scroll_speed;
bool SampleDataManager::is_loop;
vector<SampleData> SampleDataManager::sampledata;

float SampleDataManager::calc_optimize_pivot(){
    float result = (sample_num / num_of_row)* vertical_margin;
    return result*(-1);
}

void SampleDataManager::init(){
    vertical_margin = 30;
    sample_num = 1000;
    num_of_row = 4;
    pivot = calc_optimize_pivot();
    scroll_speed = 5;
    int i = sample_num;
    while(i>0){
        sampledata.push_back(SampleData(i));
        i--;
    }
}

void SampleDataManager::update(){
    pivot += scroll_speed;
    //TODO Scrollした後にその要素のメモリ解放
}

void SampleDataManager::draw(){
    int x, y;
    for(int i = 0; i<sampledata.size();i++){
        x = ofMap(i%num_of_row, 0, num_of_row-1, 100, ofGetWidth()-250);
        y = (i/num_of_row)* vertical_margin +pivot;
        sampledata.at(i).draw(x,y);
    }
}

