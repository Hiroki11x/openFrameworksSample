//
//  TreeNode.hpp
//  mySketch
//
//  Created by HirokiNaganuma on 5/13/17.
//
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include "ofMain.h"

class TreeNode{
public:
    TreeNode();
    TreeNode(int gen_stage,ofVec2f pre_pos,float radius);
    int gen_stage;
    ofVec2f pos;
    const float standard_node_length = -50;
    float radius;
};

#endif /* TreeNode_hpp */
