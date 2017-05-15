//
//  TreeNode.cpp
//  mySketch
//
//  Created by HirokiNaganuma on 5/13/17.
//
//

#include "TreeNode.hpp"

TreeNode::TreeNode(int gen_stage,ofVec2f pre_pos,float radius){
    this->gen_stage = gen_stage;
    this-> pos = pre_pos + gen_stage * standard_node_length * ofVec2f(sin(radius),cos(radius));;
    this->radius = radius;
}