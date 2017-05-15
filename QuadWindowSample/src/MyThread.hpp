//
//  MyThread.hpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/10.
//
//

#ifndef MyThread_hpp
#define MyThread_hpp



#define CAM_WIDTH 400
#define CROP_HEIGHT 300

#include "ofMain.h"
#include "ofxOpenGLContextScope.h"

class MyThread : public ofThread {
public:


    void init(){
        cam.setup(ofGetWidth(), ofGetHeight());
        image.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    }

    // the thread function
    void threadedFunction() {


        ofxOpenGLContextScope scope; // crash if commented out
        // start

        while(isThreadRunning()) {

            cam.update();
            if(cam.isFrameNew()) {

                // lock access to the resource
                lock();

                // load the image
                image.setFromPixels(cam.getPixelsRef());
                // done with the resource
                unlock();
            }
        }

        // done
    }

    ofVideoGrabber cam;  // the cam
    ofImage image;       // the shared resource
};



#endif /* MyThread_hpp */
