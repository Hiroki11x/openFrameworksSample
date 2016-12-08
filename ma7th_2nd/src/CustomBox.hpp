//
//  CustomBox.hpp
//  ma7th_2nd
//
//  Created by HirokiNaganuma on 2016/02/13.
//
//

#ifndef CustomBox_hpp
#define CustomBox_hpp

#include "ofMain.h"

class CustomBox{
public:
    void init();//初期化
    void update();//数値更新
    void draw();//描画
    ofVec3f get_position();
    
private:
    ofBoxPrimitive mbox;
    ofColor mcolor;
    ofVec3f box_position;//座標
    ofVec3f box_speed;//スピード
};

#endif /* CustomBox_hpp */
