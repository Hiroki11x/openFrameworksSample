//
//  RandomPositionGenerator.hpp
//  Loveandsheep
//
//  Created by HirokiNaganuma on 12/28/16.
//
//

#ifndef RandomPositionGenerator_hpp
#define RandomPositionGenerator_hpp

#include "ofMain.h"

namespace ranposgen{
    
    static ofVec2f generateVec2f(float minX, float minY, float maxX, float maxY){
        return ofVec2f(ofRandom(minX,maxX),ofRandom( minY,maxY));
    }

    static ofVec3f generateVec3f(float minX, float minY, float minZ, float maxX, float maxY,float maxZ){
        return ofVec3f(ofRandom(minX,maxX),ofRandom(minY,maxY),ofRandom(minZ,maxZ));
    }
}

#endif /* RandomPositionGenerator_hpp */
