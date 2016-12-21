//
//  WStringConverter.hpp
//  TwitterStreamingSample
//
//  Created by HirokiNaganuma on 12/21/16.
//
//  This was quoted from @YoshimasaSakuragi

#ifndef WStringConverter_hpp
#define WStringConverter_hpp

#include "ofMain.h"

class WStringConverter{
public:
    static string removeWSpace(string src);
    static wstring convToWString(string src);
    template <class T>
    static wstring convToUCS4(basic_string<T> src);
};

#endif /* WStringConverter_hpp */
