//
//  Polygon3D.cpp
//  MA_Instruction_02
//
//  Created by HirokiNaganuma on 2015/06/07.
//
//

#include "Polygon3D.h"

void Polygon3d::setPolygonPosition(float x, float y, float z){
    mPolygonPosition.set(x, y, z);
}
void Polygon3d::setPolygonPosition(ofPoint position){
    mPolygonPosition = position;
}
void Polygon3d::setPolygonType(int id){//0:Box 1:Sphereで型を指定
    mPolygonType = id;
}
void Polygon3d::setPolygonSize(int size){
    mPolygonSize = size;
}
ofPoint Polygon3d::getPolygonPosition(){
    return mPolygonPosition;
}
int Polygon3d::getPolygonType(){
    return mPolygonType;
}
int Polygon3d::getPolygonSize(){
    return mPolygonSize;
}
