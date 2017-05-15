//
//  CameraStreamer.hpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/10.
//
//

#ifndef CameraStreamer_hpp
#define CameraStreamer_hpp

#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <vector>
//#include <concurrent_queue.h>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

using namespace std;
using namespace cv;
//using namespace concurrency;

class CameraStreamer{
public:
    //this holds camera stream urls
    vector<string> camera_source;
    //this holds usb camera indices
    vector<int> camera_index;
    //this holds OpenCV VideoCapture pointers
    vector<VideoCapture*> camera_capture;
    //this holds queue(s) which hold images from each camera
    vector<std::vector<Mat>*> frame_queue;
    //this holds thread(s) which run the camera capture process
    vector<thread*> camera_thread;

    //Constructor for IP Camera capture
    CameraStreamer(vector<string> source);
    //Constructor for USB Camera capture
    CameraStreamer(vector<int> index);
    //Destructor for releasing resource(s)
    ~CameraStreamer();

private:
    bool isUSBCamera;
    int camera_count;
    //initialize and start the camera capturing process(es)
    void startMultiCapture();
    //release all camera capture resource(s)
    void stopMultiCapture();
    //main camera capturing process which will be done by the thread(s)
    void captureFrame(int index);
};

#endif /* CameraStreamer_hpp */
