//
//  CommentView.cpp
//  SummerWars01
//
//  Created by HirokiNaganuma on 2015/08/11.
//
//

#include "CommentView.h"

void CommentView::update(){
//    if(center_y<0||center_y>ofGetWidth()){
//        sp_x*=-1;
//    }
//    if(center_y<0||center_y>ofGetHeight()){
//        sp_y*=-1;
//    }
    
    if(abs(center_y)<400||abs(center_y)<200){
        center_x += sp_x;
        center_y += sp_y;
    }
    
    
    center_x += (aim_x-center_x)/128;
    center_y += (aim_y-center_y)/128;
    
//    if(ofDist(center_x,center_y,
//              aim_x,aim_y)<100){
//        sp_x*=0.9;
//        sp_y*=0.9;
//    }
    if(ratio<1){
        ratio += 0.01;
    }
    
}

void CommentView::setSpeed(float speed_x,float speed_y){
    sp_x=speed_x;
    sp_y=speed_y;
}

void CommentView::setSize(float argSize){
//    center_x=x;
//    center_y=y;
    size = argSize;
}

void CommentView::setCenterPosition(float x,float y){
    center_x=x;
    center_y=y;

}

void CommentView::setAimPosition(float x,float y){
    aim_x=x;
    aim_y=y;
}

void CommentView::setString(string args_u, string args_l){
    upperText = args_u;
    lowerText = args_l;
}

void CommentView::setImage(string filename){
    image.loadImage(filename);
}

void CommentView::setAngle(float arg_angle){
    angle = arg_angle;
}

void CommentView::setViewColor(ofColor arg_color){
    color = arg_color;
}

void CommentView::draw(){
    float tempSize = size;
    size *= ratio;
    ofFill();
    ofSetColor(color);
    ofCircle(center_x,center_y,size);
    ofSetColor(255);
    image.draw(center_x-size*0.75,center_y-size*0.5,1.5*size,size);
//    ofSetColor(50);
    font.drawString(upperText, center_x-size/1.9, center_y+size/1.9); //時刻表示
    font.drawString(lowerText, center_x-size/6, center_y-size/1.4);//国名表示
    size = tempSize;
    
//    ofSetLineWidth(2);
//    ofNoFill();
//    ofSetColor(100);
//    ofCircle(center_x,center_y,size);
    
    

//    ofNoFill();
//    ofSetColor(255);
//    ofSetLineWidth(2);
//    
//    //Angle=0からの線
//    ofBezier(center_x+size/2*2*cos((float)180/180*PI), center_y+size/2*sin((float)180/180*PI),
//             ofGetWidth()/2,ofGetHeight()/2,
//             ofGetWidth()/2,ofGetHeight()/2,
//             ofGetWidth()/2, ofGetHeight()/2);
//    //Angle=180からの線
//    ofBezier(center_x+size/2*2*cos((float)0/180*PI), center_y+size/2*sin((float)0/180*PI),
//             ofGetWidth()/2,ofGetHeight()/2,
//             ofGetWidth()/2,ofGetHeight()/2,
//             ofGetWidth()/2, ofGetHeight()/2);
//    
//    for(int i=0;i<360;i++){
//        ofVertex(center_x+size*2*1.9*cos((float)i/180*PI),center_y+size*1.9*sin((float)i/180*PI));
//    }
//    
//    ofDrawBitmapString(text,center_x,center_y);
//    ofFill();
//    ofSetColor(255);
//    ofBeginShape();
//    for(int i=0;i<360;i++){
//        ofVertex(center_x+size*2*cos((float)i/180*PI),center_y+size*sin((float)i/180*PI));
//    }
//    ofEndShape();
    
}