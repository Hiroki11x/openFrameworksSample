//
//  MovieThread.hpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/11.
//
//

#ifndef MovieThread_hpp
#define MovieThread_hpp


#include "ofMain.h"
#include "ofxOpenGLContextScope.h"
#include <opencv2/opencv.hpp>
#include "ofxCv.h"
#include "ofxOpenCv.h"

class MovieThread : public ofThread {
public:

    ofImage img;       // the shared resource
    cv::VideoCapture cap;
    cv::Mat frame;

    void init(int index){
        switch(index){
            case 1:

                cap = cv::VideoCapture("http://192.168.149.88:8080/?action=stream");
                break;
            case 0:
//                cap = cv::VideoCapture("http://192.168.149.229:7890/ipvideo.mjpg");
                cap = cv::VideoCapture("http://192.168.158.44:8080/?action=stream");
                break;
            case 2:
                cap = cv::VideoCapture("http://192.168.150.181:8080/?action=stream");
                break;
            case 3:
                cap = cv::VideoCapture("http://192.168.152.22:8080/?action=stream");
                break;
            default:
                break;
        }

        cap.set(CV_CAP_PROP_BUFFERSIZE, 3); // internal buffer will now store only 3 frames
        cap.set(CV_CAP_PROP_FPS, 60);
        img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    }

    // the thread function
    void threadedFunction() {

        ofxOpenGLContextScope scope; // crash if commented out
        // start

        while(isThreadRunning()) {


            if (cap.isOpened() ){
                // lock access to the resource
                lock();

                cap >> frame;
                if(frame.empty()){
                    cout << "empty" << endl;
                    //                    break;
                }else{
                    img.setFromPixels(frame.ptr(), frame.cols, frame.rows, OF_IMAGE_COLOR);//RaspPiからの入力はBGRじゃないのでfalseを引数に入れない
                }

                if(cv::waitKey(30) >= 0) {break;}

                // done with the resource
                unlock();
            }
        }
    }
};



#endif /* MovieThread_hpp */
