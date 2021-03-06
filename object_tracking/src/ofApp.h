#pragma once

#include "ofMain.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    void draw_matrix();
    void update_scene();
    void draw_scene();

    void update_scene_A();
    void update_scene_B();
    void update_scene_C();
    void update_scene_D();
    void update_scene_E();

    void draw_scene_A();
    void draw_scene_B();
    void draw_scene_C();
    void draw_scene_D();
    void draw_scene_E();

    int scene_frag; //

    float m_box_z;//box及びカメラ移動のために使う、z座標
    float z_offset;//マトリックスを無限に表示させるために
    float matrix_size;//下にある格子状のやつ(マトリックス)
    ofVec3f m_box_pos;//box及びカメラの座標基準
    ofBoxPrimitive m_box;//boxの実体
    ofCamera m_camera;//カメラの実体
};
