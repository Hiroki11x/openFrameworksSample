//
//  CustomGalleryImageView.cpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#include "CustomGalleryImageView.hpp"
void CustomGalleryImageView::drawCustomView(ofImage &img, string discription){
    ofSetColor(255);
    ofDrawBitmapString(discription, 0, size+5);
    ofSetColor(0);
    ofDrawRectangle(0, size, size, 20);
    ofSetColor(255);
    img.draw(0,0,size,size);
}