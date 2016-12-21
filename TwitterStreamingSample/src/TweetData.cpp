//
//  TweetData.cpp
//  TwitterStreamingSample
//
//  Created by HirokiNaganuma on 12/21/16.
//
//

#include "TweetData.hpp"

//------------------------------------------------------------------------------------
TweetData::TweetData(){

}

//------------------------------------------------------------------------------------
TweetData::TweetData(const wstring &tweet_text,
                               const wstring &user_name,
                               const string &twitter_id,
                               const string &icon_url,
                               const int &friends_count,
                               const int &statuses_count,
                               const int &followers_count){
    cout << twitter_id << endl;  // output console
    this->tweet_text = tweet_text;
    this->user_name = user_name;
    this->twitter_id = twitter_id;
    this->icon_url = icon_url;
    this->friends_count = friends_count;
    this->statuses_count = statuses_count;
    this->followers_count = followers_count;
    this->image.load(this->icon_url);
}
