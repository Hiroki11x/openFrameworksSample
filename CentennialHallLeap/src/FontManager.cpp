//
//  FontManager.cpp
//  CentennialHallLeap
//
//  Created by HirokiNaganuma on 12/8/16.
//
//

#include "FontManager.hpp"

ofxTrueTypeFontUL2 FontManager::mfont;
ofxTrueTypeFontUL2 FontManager::msmallfont;
ofxTrueTypeFontUL2 FontManager::mbigfont;
ofxTrueTypeFontUL2 FontManager::guifont;

void FontManager::init(){
    setlocale(LC_CTYPE,"");
    if(mfont.isLoaded())return;
    FontManager::loadFont("font/smartfont.otf", 80);
    FontManager::loadSmallFont("font/digital_counter_7_italic.ttf", 12);
    FontManager::loadBigFont("font/smartfont.otf", 22);
    FontManager::loadGuiFont("font/smartfont.otf", 10);
}

void FontManager::loadGuiFont(const string &arg,const int &size){
    guifont.loadFont(arg, size);
}

void FontManager::drawGuiString(const string &arg ,const float &x,const float &y){
    guifont.drawString(arg, x, y);
}

void FontManager::loadFont(const string &arg,const int &size){
    mfont.loadFont(arg, size);
}

void FontManager::drawString(const string &arg ,const float &x,const float &y){
    glPushMatrix();
    glRotatef(180, 1, 0, 0);
    glTranslated(0,-500,0);
    mfont.drawString(arg, x, y);
    glPopMatrix();
}

void FontManager::loadSmallFont(const string &arg,const int &size){
    msmallfont.loadFont(arg, size);
    //    msmallfont.loadSubFont("font/smartfont.otf");
}

void FontManager::drawSmallWString(const wstring &arg ,const float &x,const float &y){
    msmallfont.drawString(arg, x, y);
    msmallfont.useProportional(true);
    msmallfont.useVrt2Layout(true);
}

void FontManager::drawSmallString(const string &arg ,const float &x,const float &y){
    msmallfont.drawString(arg, x, y);
}

void FontManager::loadBigFont(const string &arg,const int &size){
    mbigfont.loadFont(arg, size);
}

void FontManager::drawBigString(const string &arg ,const float &x,const float &y){
    mbigfont.drawString(arg, x, y);
}

void FontManager::drawBigWString(const wstring &arg ,const float &x,const float &y){
    mbigfont.drawString(arg, x, y);
    mbigfont.useProportional(true);
    mbigfont.useVrt2Layout(true);
}