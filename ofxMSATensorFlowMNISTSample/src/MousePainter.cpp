//
//  MousePainter.cpp
//  ofxMSATensorFlowMNISTSample
//
//  Created by HirokiNaganuma on 2016/03/28.
//
//

#include "MousePainter.hpp"

// fboにメモリ確保
void MousePainter::setup(int size) {
    fbo.allocate(size, size);
    clear();
}

// fboをクリア
void MousePainter::clear() {
    fbo.begin();
    ofClear(0, 0, 0, 255);
    fbo.end();
}

// mouseがPressされた時
void MousePainter::penDown(ofVec2f p, bool do_erase) {
    ofPushStyle();
    
    // 左クリックだったら paint_color(白)
    // 右クリックだったら erase_color(黒//二本指クリック)
    ofSetColor(do_erase ? erase_color : paint_color);
    float r = do_erase ? 2 * radius : radius;   // 消す時は半径を二倍に
    
    // fboに縁で書き込みを行って更新
    fbo.begin();
    ofDrawCircle(p, r);
    fbo.end();
    
    ofPopStyle();
    last_point = p; // 直近の座標を保存
}

// mouseがDragされた時
void MousePainter::penDrag(ofVec2f p, bool do_erase) {
    ofPushStyle();
    ofSetColor(do_erase ? erase_color : paint_color);
    float r = do_erase ? 2 * radius : radius;  // 消す時は半径を二倍に
    
    fbo.begin();
    // lines can't be wide enough, so painting with a rotated rectangle, innit
    ofPushMatrix();
    ofTranslate(last_point);
    ofVec2f diff(p - last_point);
    ofRotate(ofRadToDeg(atan2(diff.y, diff.x)));
    ofDrawRectangle(0, -r, diff.length(), 2 * r);
    ofPopMatrix();
    
    fbo.end();
    ofPopStyle();
    
    // also draw a circle to cover up the ugly joins
    penDown(p, do_erase);
}

void MousePainter::penUp() {
    
}

void MousePainter::draw() {
    ofPushStyle();
    ofSetColor(255);
    fbo.draw(0, 0);
    ofNoFill();
    ofDrawRectangle(0, 0, fbo.getWidth(), fbo.getHeight());
    ofPopStyle();
}

const ofPixels& MousePainter::get_pixels() {
    fbo.readToPixels(pixels);
    return pixels;
}

int MousePainter::getWidth() {
    return fbo.getWidth();
}

int MousePainter::getHeight() {
    return fbo.getHeight();
}
