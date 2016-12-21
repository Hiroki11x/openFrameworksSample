//
//  FontManager.cpp
//  TwitterStreamingSample
//
//  Created by HirokiNaganuma on 12/21/16.
//
//

#include "FontManager.hpp"

ofxTrueTypeFontUL2 FontManager::msmallfont;
ofxTrueTypeFontUL2 FontManager::mbigfont;

//--------------------------------------------------------------------------------
void FontManager::init(){
    setlocale(LC_CTYPE,"");
    if(msmallfont.isLoaded())return;
    FontManager::loadSmallFont("font/smartfont.otf", 12);
    FontManager::loadBigFont("font/smartfont.otf", 22);
}

//--------------------------------------------------------------------------------
void FontManager::loadSmallFont(const string &arg,const int &size){
    msmallfont.loadFont(arg, size);
}

//--------------------------------------------------------------------------------
void FontManager::drawSmallString(const string &arg ,const float &x,const float &y){
    msmallfont.drawString(arg, x, y);
}

//--------------------------------------------------------------------------------
void FontManager::drawSmallWString(const wstring &arg ,const float &x,const float &y){
    msmallfont.drawString(arg, x, y);
    msmallfont.useProportional(true);
    msmallfont.useVrt2Layout(true);
}

//--------------------------------------------------------------------------------
void FontManager::loadBigFont(const string &arg,const int &size){
    mbigfont.loadFont(arg, size);
}

//--------------------------------------------------------------------------------
void FontManager::drawBigString(const string &arg ,const float &x,const float &y){
    mbigfont.drawString(arg, x, y);
}

//--------------------------------------------------------------------------------
void FontManager::drawBigWString(const wstring &arg ,const float &x,const float &y){
    mbigfont.drawString(arg, x, y);
    mbigfont.useProportional(true);
    mbigfont.useVrt2Layout(true);
}