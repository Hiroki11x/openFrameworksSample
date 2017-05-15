//
//  CameraStreamer.cpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/10.
//
//

#include "CameraStreamer.hpp"


CameraStreamer::CameraStreamer(vector<string> stream_source)
{
    camera_source = stream_source;
    camera_count = camera_source.size();
    isUSBCamera = false;

    startMultiCapture();
}

CameraStreamer::CameraStreamer(vector<int> capture_index)
{
    camera_index = capture_index;
    camera_count = capture_index.size();
    isUSBCamera = true;

    startMultiCapture();
}

CameraStreamer::~CameraStreamer()
{
    stopMultiCapture();
}

void CameraStreamer::captureFrame(int index)
{
    VideoCapture *capture = camera_capture[index];
    while (true)
    {
        Mat frame;
        //Grab frame from camera capture
        (*capture) >> frame;
        //Put frame to the queue
        frame_queue[index]->push_back(frame);
        //relase frame resource
        frame.release();
    }
}

void CameraStreamer::startMultiCapture()
{
    VideoCapture *capture;
    thread *t;
    vector<Mat> *q;
    for (int i = 0; i < camera_count; i++)
    {
        //Make VideoCapture instance
        if (!isUSBCamera){
            string url = camera_source[i];
            capture = new VideoCapture(url);
            cout << "Camera Setup: " << url << endl;
        }
        else{
            int idx = camera_index[i];
            capture = new VideoCapture(idx);
            cout << "Camera Setup: " << to_string(idx) << endl;
        }

        //Put VideoCapture to the vector
        camera_capture.push_back(capture);

        //Make thread instance
        t = new thread(&CameraStreamer::captureFrame, this, i);

        //Put thread to the vector
        camera_thread.push_back(t);

        //Make a queue instance
        q = new vector<Mat>;

        //Put queue to the vector
        frame_queue.push_back(q);
    }
}

void CameraStreamer::stopMultiCapture()
{
    VideoCapture *cap;
    for (int i = 0; i < camera_count; i++)
    {
        cap = camera_capture[i];
        if (cap->isOpened()){
            //Relase VideoCapture resource
            cap->release();
            cout << "Capture " << i << " released" << endl;
        }       
    }
}