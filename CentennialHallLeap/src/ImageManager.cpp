//
//  ImageManager.cpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#include "ImageManager.hpp"

vector<ofImage> ImageManager::images;

//--------------------------------------------------
void ImageManager::loadImages(){
    string fileName;
    for(int i = 0 ;i<=70;i++){
        char char1[32];
        sprintf(char1, "picture/%04d.jpg", i);
        fileName = ofToString(char1);
        ImageManager::images.push_back(ofImage());
        ImageManager::images.back().load(fileName);
    }
}

//--------------------------------------------------
void ImageManager::drawImages(){
    int x,y;
    int size = 200;
    string fileName;
    int index = 0;
    char char1[32];
    for(auto img: ImageManager::images){
        sprintf(char1, "%04d.jpg", index);
        fileName = ofToString(char1);
        x = ((index * size) % MY_WINDOW_W);
        y = (int)( (index * size) / MY_WINDOW_W) * size;
        ofPushMatrix();
        ofTranslate(x,y);
        CustomGalleryImageView::drawCustomView(img, fileName);
        ofPopMatrix();
        index ++;
    }
}