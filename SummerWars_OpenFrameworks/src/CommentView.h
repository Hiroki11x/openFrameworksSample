//
//  CommentView.h
//  SummerWars01
//
//  Created by HirokiNaganuma on 2015/08/11.
//
//

#include "ofMain.h"

#ifndef SummerWars01_CommentView_h
#define SummerWars01_CommentView_h


class CommentView{
public:
    //円の大きさ
    float size;
    float ratio;
    
    //角度
    float angle;
    
    //現在の円の中心座標
    float center_x;
    float center_y;
    float center_z;
    
    //移動速度
    float sp_x;
    float sp_y;
    
    //到着すべき目標
    float aim_x;
    float aim_y;
    
    //上(下)部に表示する文字列
    string upperText;
    string lowerText;
    
    //中に表示する画像
    ofImage image;
    
    //塗りつぶしの色
    ofColor color;
    
    //Font
    ofTrueTypeFont font;
    
    CommentView(){
        font.loadFont("03スマートフォントUI.otf", 13);
    };
    
    void setSize(float arg_size);
    void setAngle(float arg_angle);
    void setImage(string arg_string);
    void setCenterPosition(float x , float y);
    void setAimPosition(float x , float y);
    void setSpeed(float speed_x,float speed_y);
    void setString(string args_u, string args_l);
    void setViewColor(ofColor arg_color);
    void update();
    void draw();
    
    
};

#endif
