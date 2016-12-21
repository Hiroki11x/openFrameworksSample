//
//  TweetJsonReceiver.cpp
//  TwitterStreamingSample
//
//  Created by HirokiNaganuma on 12/21/16.
//
//

#include "TweetJsonReceiver.hpp"

vector<TweetData> TweetJsonReceiver::tweetData;
int TweetJsonReceiver::data_num;

//--------------------------------------------------------------------------------------------
TweetJsonReceiver &TweetJsonReceiver::getInstance() {
    static TweetJsonReceiver instance;
    return instance;
}

//--------------------------------------------------------------------------------------------
vector<TweetData> TweetJsonReceiver::getTweetData(){
    return tweetData;
}

//--------------------------------------------------------------------------------------------
bool TweetJsonReceiver::checkUpdateJson(){
    if(jsonElement["id"].asInt64() != cachedTweetId){
        cachedTweetId = jsonElement["id"].asInt64();
        return true;
    }else{
        return false;
    }
}

//--------------------------------------------------------------------------------------------
void TweetJsonReceiver::init(){
    data_num = 0;
    TweetJsonReceiver::tweetData.clear();
    bool parsingSuccessful = jsonElement.openLocal("../../../TweetStream/twitter.json");//Nodeで取得したJSON
    if (parsingSuccessful){
        cout << "Parsing Successful" << endl;
        cachedTweetId = jsonElement["id"].asInt64();
    }else{
        cout << "Failed to parse JSON" << endl;
    }
}

//--------------------------------------------------------------------------------------------
void TweetJsonReceiver::parseJson(){
    string tmptext = jsonElement["text"].asCString() ;
    string tmpusername = jsonElement["user"]["name"].asCString();
    wstring wtmptext = WStringConverter::convToWString(tmptext);
    wstring wtmpusername = WStringConverter::convToWString(tmpusername);

    tweetData.push_back((TweetData){
        WStringConverter::convToWString(tmptext),
        WStringConverter::convToWString(tmpusername),
        jsonElement["user"]["screen_name"].asCString(),
        jsonElement["user"]["profile_image_url"].asCString(),
        jsonElement["user"]["friends_count"].asInt(),
        jsonElement["user"]["statuses_count"].asInt(),
        jsonElement["user"]["followers_count"].asInt()
    });
    data_num++;
    return;
}


//--------------------------------------------------------------------------------------------
//Jsonの数に変化があればその分をtweetDataに追加
void TweetJsonReceiver::update(){

    //tweetDataが無限にたまらないようにFIFOさせる
    if(TweetJsonReceiver::tweetData.size()>DATA_MAX_NUM){
        TweetJsonReceiver::tweetData.erase(TweetJsonReceiver::tweetData.begin());
        cout << "CLear data" <<endl;
    }
    receive();
}


//--------------------------------------------------------------------------------------------
bool TweetJsonReceiver::receive(){
    bool parsingSuccessful = jsonElement.openLocal("../../../TweetStream/twitter.json");//Nodeで取得したJSON
    if (parsingSuccessful){
        if(checkUpdateJson()){
            parseJson();
            return true;
        }
    }else{
        cout << "Failed to parse JSON" << endl;
    }
    return false;
}

