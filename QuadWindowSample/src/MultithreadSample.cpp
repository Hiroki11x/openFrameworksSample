//
//  MultithreadSample.cpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/10.
//
//

#include "MultithreadSample.hpp"


void *WebCam(void *arg ){

    VideoCapture cap(0);
    for (; ; ) {
        Mat frame;
        cap >> frame;
        flip(frame, frame, 1);

        imshow("frame", frame);

        if(waitKey(30) >= 0)
            break;
    }
    pthread_exit(NULL);
}

//--------------------------------------------------------------
void MultithreadSample::setup(){
    //IP camera URLs
    vector<string> capture_source = {
        "http://52.197.48.133:8080/?action=stream&type=mjpg",
        "http://52.197.48.133:8082/?action=stream&type=mjpg"
    };


    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, &WebCam, NULL);
    pthread_join(thread1, NULL);

}

//--------------------------------------------------------------
void MultithreadSample::exit() {

}

//--------------------------------------------------------------
void MultithreadSample::update(){


}

//--------------------------------------------------------------
void MultithreadSample::draw(){
}


//--------------------------------------------------------------
void MultithreadSample::keyPressed(int key){

}

//--------------------------------------------------------------
void MultithreadSample::keyReleased(int key){

}

//--------------------------------------------------------------
void MultithreadSample::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void MultithreadSample::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void MultithreadSample::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void MultithreadSample::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void MultithreadSample::windowResized(int w, int h){

}

//--------------------------------------------------------------
void MultithreadSample::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void MultithreadSample::dragEvent(ofDragInfo dragInfo){
    
}