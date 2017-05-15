//
//  CameraStreamerSample.cpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/10.
//
//

#include "CameraStreamerSample.hpp"

//--------------------------------------------------------------
void CameraStreamerSample::setup(){
    //IP camera URLs
    vector<string> capture_source = {
        "http://52.197.48.133:8080/?action=stream&type=mjpg",
        "http://52.197.48.133:8082/?action=stream&type=mjpg"
    };

    //USB Camera indices
    vector<int> capture_index = { 0, 1 };

    //Highgui window titles
    vector<string> label;
    for (int i = 0; i < capture_source.size(); i++)
    {
        string title = "CCTV " + to_string(i);
        label.push_back(title);
    }

    //Make an instance of CameraStreamer
    CameraStreamer cam(capture_source);

    while (cv::waitKey(20) != 27)
    {
        //Retrieve frames from each camera capture thread
        for (int i = 0; i < capture_source.size(); i++)
        {
            cv::Mat frame;
            //Pop frame from queue and check if the frame is valid
            if (!cam.frame_queue[i]->empty()){
                frame = cam.frame_queue[i]->back();
                cam.frame_queue[i]->erase(cam.frame_queue[i]->end());
                //Show frame on Highgui window
                imshow(label[i], frame);
            }
        }
    }

}

//--------------------------------------------------------------
void CameraStreamerSample::exit() {

}

//--------------------------------------------------------------
void CameraStreamerSample::update(){


}

//--------------------------------------------------------------
void CameraStreamerSample::draw(){
}


//--------------------------------------------------------------
void CameraStreamerSample::keyPressed(int key){

}

//--------------------------------------------------------------
void CameraStreamerSample::keyReleased(int key){

}

//--------------------------------------------------------------
void CameraStreamerSample::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void CameraStreamerSample::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void CameraStreamerSample::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void CameraStreamerSample::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void CameraStreamerSample::windowResized(int w, int h){

}

//--------------------------------------------------------------
void CameraStreamerSample::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void CameraStreamerSample::dragEvent(ofDragInfo dragInfo){
    
}