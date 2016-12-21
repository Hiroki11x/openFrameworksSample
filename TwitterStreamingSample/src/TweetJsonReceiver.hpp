//
//  TweetJsonReceiver.hpp
//  TwitterStreamingSample
//
//  Created by HirokiNaganuma on 12/21/16.
//
//

//保持するtweetのデータの最大値
#define DATA_MAX_NUM 10

#ifndef TweetJsonReceiver_hpp
#define TweetJsonReceiver_hpp

#include "ofxJSONElement.h"
#include "TweetData.hpp"
#include "ofMain.h"
#include "WStringConverter.hpp"

class TweetJsonReceiver {
public:
    int64_t cachedTweetId;
    ofxJSONElement jsonElement;
    static int data_num;
    static vector<TweetData> tweetData;
    static TweetJsonReceiver &getInstance();

    TweetJsonReceiver(){}
    TweetJsonReceiver &operator=(const TweetJsonReceiver &other){}

    vector<TweetData> getTweetData();
    bool checkUpdateJson();
    void parseJson();
    void init();
    void update();
    bool receive();
};

#endif /* TweetJsonReceiver_hpp */
