//
//  TweetData.hpp
//  TwitterStreamingSample
//
//  Created by HirokiNaganuma on 12/21/16.
//
//

#ifndef TweetData_hpp
#define TweetData_hpp

#include "ofMain.h"

class TweetData{

public:
    wstring tweet_text; //twwet contents
    wstring user_name;  //user name
    string twitter_id;  //screen_name @account name
    string icon_url;    //icon image url

    int friends_count;  //number of following
    int statuses_count; //number of tweet
    int followers_count;//number of follower

    ofImage image;      //to store icon image

    TweetData();
    TweetData(const wstring &tweet_text,
                   const wstring &user_name,
                   const string &twitter_id,
                   const string &icon_url,
                   const int &friends_count,
                   const int &statuses_count,
                   const int &followers_count);
};

#endif /* TweetData_hpp */
