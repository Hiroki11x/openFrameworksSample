//
//  FontManager.hpp
//  TwitterStreamingSample
//
//  Created by HirokiNaganuma on 12/21/16.
//
//

#ifndef FontManager_hpp
#define FontManager_hpp

#include "ofMain.h"
#include "ofxTrueTypeFontUL2.h"

class FontManager{
public:

    FontManager(){};

    static ofxTrueTypeFontUL2 mbigfont;
    static ofxTrueTypeFontUL2 msmallfont;

    static void init();

    static void loadSmallFont(const string &arg,const int &size);
    static void loadBigFont(const string &arg,const int &size);

    static void drawSmallString(const string &arg ,const float &x,const float &y);
    static void drawBigString(const string &arg ,const float &x,const float &y);

    static void drawSmallWString(const wstring &arg ,const float &x,const float &y);
    static void drawBigWString(const wstring &arg ,const float &x,const float &y);
};
#endif /* FontManager_hpp */
