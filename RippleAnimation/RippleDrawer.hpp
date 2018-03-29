//
//  RippleDrawer.hpp
//  ofxVJComponent
//
//  Created by HirokiNaganuma on 2016/04/04.
//
//

#ifndef RippleDrawer_hpp
#define RippleDrawer_hpp

#include "SceneElement.hpp"
#include "RingRippleAnimation.hpp"

class RippleDrawer : public SceneElement {
    void init() override;
    void update() override;
    void draw() override;
    void keyPressed(int key);
    void init(ofVec2f pos, ofVec2f speed);
    vector<RingRippleAnimation *> rings;
};


#endif /* RippleDrawer_hpp */
