#pragma once

#include "ofMain.h"
#include "Polygon3D.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofBoxPrimitive boxPrimitive;//あらかじめ宣言しておくことでコンピュータに対する負荷を減らす。
    ofSpherePrimitive spherePrimitive;//あらかじめ宣言しておくことでコンピュータに対する負荷を減らす。
    ofCamera camera;
    ofEasyCam cam;
    
    vector<Polygon3d *> polygons;
    //ポインタ型で宣言,Polygon3dクラスのオブジェクトをさしているポインタを格納する配列なので、ポインタ型で宣言
    
    ofLight light;
    float objectSizeScale = 1.0;
    double cameraSpeed = 0.0;
    double cameraPosition = 0.0;
    bool accelFlag = false;//加速させるかどうか
    bool lineMode =false;
};
