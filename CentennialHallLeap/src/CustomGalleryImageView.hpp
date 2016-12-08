//
//  CustomGalleryImageView.hpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#ifndef CustomGalleryImageView_hpp
#define CustomGalleryImageView_hpp
#include "ofMain.h"

class CustomGalleryImageView{
private:
    const static int size = 200;
public:
    static void drawCustomView(ofImage &img, string discription);
};

#endif /* CustomGalleryImageView_hpp */
