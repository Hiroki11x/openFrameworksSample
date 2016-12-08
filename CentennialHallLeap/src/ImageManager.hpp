//
//  ImageManager.hpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#ifndef ImageManager_hpp
#define ImageManager_hpp
#define MY_WINDOW_W 1800
#define MY_WINDOW_H 800

#include "ofMain.h"
#include "CustomGalleryImageView.hpp"

class ImageManager{
private:
public:
    static vector<ofImage> images;
    static void loadImages();
    static void drawImages();
};

#endif /* ImageManager_hpp */
