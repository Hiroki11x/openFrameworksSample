//
//  CropImage.hpp
//  IMageCropSample
//
//  Created by HirokiNaganuma on 4/27/17.
//
//

#ifndef CropImage_hpp
#define CropImage_hpp

#include "ofMain.h"

class CropImage{
public:
    void setup();
    void load(string path);
    void update();
    void draw();
    void draw(float x, float y, float size);
    void draw(float x, float y, float w, float h);

private:
    ofImage img;
    ofFbo fbo;
    float center_x;
    float center_y;
    float rad;
    float ratio_x;
    float ratio_y;
};

#endif /* CropImage_hpp */
