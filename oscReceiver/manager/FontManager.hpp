//
//  FontManager.hpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/01.
//

#ifndef FontManager_hpp
#define FontManager_hpp

#include "ofMain.h"
#include "ofxTrueTypeFontUL2.h"

class FontManager{
public:

    FontManager(){};

    static ofxTrueTypeFontUL2 mbigfont;
    static ofxTrueTypeFontUL2 mfont;
    static ofxTrueTypeFontUL2 msmallfont;
    static ofxTrueTypeFontUL2 guifont;

    static void init();

    static void loadGuiFont(const string &arg,const int &size);
    static void drawGuiString(const string &arg ,const float &x,const float &y);

    static void loadFont(const string &arg,const int &size);
    static void drawString(const string &arg ,const float &x,const float &y);

    static void loadSmallFont(const string &arg,const int &size);
    static void drawSmallString(const string &arg ,const float &x,const float &y);
    static void drawSmallWString(const wstring &arg ,const float &x,const float &y);

    static void loadBigFont(const string &arg,const int &size);
    static void drawBigString(const string &arg ,const float &x,const float &y);
    static void drawBigWString(const wstring &arg ,const float &x,const float &y);
};
#endif /* FontManager_hpp */
