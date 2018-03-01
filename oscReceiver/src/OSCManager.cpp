//
//  OSCManager.cpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/01.
//

#include "OSCManager.hpp"

ofxOscReceiver OSCManager::receiver;
ofxOscMessage OSCManager::message;
string OSCManager::buf;


//--------------------------------------------------------------
void OSCManager::setup(){
    receiver.setup(MacroManager::osc_port_num);
    buf = "listening for osc messages on port" + ofToString(MacroManager::osc_port_num);

    // OSC listen on the given port
    cout << "listening for osc messages on port " << MacroManager::osc_port_num << "\n";
}

//--------------------------------------------------------------
//initial
void OSCManager::update(){

    string initial;
    string image_url;
    int gender;
    int style;

    receiver.getNextMessage(message);
    //untill all address of osc are got.

    if(message.getAddress() == "/data"){
        //initital/gender/style/image_url
        // both the arguments are int32's
        string data = message.getArgAsString(0);

        string str = data.substr(0, 2);//Mk
        int n = (int)str.find("/");
        if(n==0){//if OSC dont have initial
            initial = "";
        }else if(n==1){//if OSC have one charactor
            initial = str.substr(0,1);
        }else{
            transform(str.begin(), str.end(), str.begin(), ::toupper);//MK
            str.insert(str.begin() + 1, '.');//M.K
            initial = str;
        }

        int pos = (int)data.find("/");
        gender = stoi(data.substr(pos+1,1));

        pos = (int)data.find("/",pos+1);
        style = stoi(data.substr(pos+1,1));

        pos = (int)data.find("/",pos+1);
        data.erase(data.begin(),data.begin()+(int)pos+1);
        image_url = data;
        if(image_url=="image_url"){//if image_url is default
            image_url = MacroManager::test_image_url;
        }else{
            image_url="image_store/"+data;
        }

        UserData::userdata.push_back(UserData(initial,image_url,gender,style));
        cout << "get address " << UserData::userdata.size() << endl;
        if(MovieManager::is_video_state_loop){
            MovieManager::bFadeLoop = true;
        }
    }
};



//--------------------------------------------------------------
void OSCManager::draw(){
    //    OSC
    ofDrawBitmapString(buf, 10, 20);
}
