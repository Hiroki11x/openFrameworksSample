//
//  MacroManager.hpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/01.
//

#ifndef MacroManager_hpp
#define MacroManager_hpp

#include <stdio.h>
#include <string>

namespace MacroManager {
//    const int projectorWidth = 1920;
//    const int projectorHeight = 1080;

    const int heart_rate_max = 100;
    const int heart_rate_min = 85;

    const int max_buffer_size = 10;
    const int osc_port_num = 8002;

    const std::string higashiome_gothicfont_path = "font/HigashiOme-Gothic.ttf";
    const std::string helveticafont_path = "font/HelveticaNeueLTStd-Md.ttf";
}

#endif /* MacroManager_hpp */
