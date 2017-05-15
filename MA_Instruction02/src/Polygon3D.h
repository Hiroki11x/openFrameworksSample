//
//  Polygon3D.h
//  MA_Instruction_02
//
//  Created by HirokiNaganuma on 2015/06/07.
//
//
#include "ofMain.h"

class Polygon3d {
    
private:
    ofPoint mPolygonPosition = ofPoint(0,0,0);
    int mPolygonType = 0; //0:Box 1:Sphere
    int mPolygonSize = 0; //10~100
    
public:
    Polygon3d(){};
    ~Polygon3d(){};
    /* また、クラスにはそのクラスがdelete演算子で消去される際に実行される特別な関数を定義することも可能です。
     * この消去の際の関数を「デストラクタ (destructer)」と呼びます。
     * デストラクタはクラス名の先頭にチルダ「~」をつけて関数名とします。
     * vectorは、デストラクタが呼び出されると、メモリの解放が行われます。
     * インスタンスのスコープを抜ける時、解体の直前で自動的に呼び出されます。
     * 最終的には解放されます。
     *
     */
    void setPolygonPosition(float x, float y, float z);
    void setPolygonPosition(ofPoint position);
    void setPolygonType(int id);
    void setPolygonSize(int size);
    ofPoint getPolygonPosition();
    int getPolygonType();
    int getPolygonSize();
};

