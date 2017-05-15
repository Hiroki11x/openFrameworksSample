//
//  CvParallelThread.hpp
//  QuadWindowSample
//
//  Created by HirokiNaganuma on 2016/06/10.
//
//

#ifndef CvParallelThread_hpp
#define CvParallelThread_hpp

//#define CHROMAKEY

#define CAM_WIDTH 200
#define CROP_HEIGHT 150

#include "ofMain.h"
#include "ofxOpenGLContextScope.h"

#include <opencv2/opencv.hpp>
#include "ofxCv.h"
#include "ofxOpenCv.h"
#include "ofxChromaKeyShader.h"
#include "ofxGui.h"
#include "BlendmodeManager.hpp"

class CvParallelThread : public ofThread {
public:
    bool selfIndex;

#ifdef CHROMAKEY
    //-------------------Chromakey-----------------
    ofImage bg_image;
    ofxChromaKeyShader *chromakey;
    int camW, camH;
    ofxPanel chromaGui;
    bool bUpdateBgColor;
    //-------------------Chromakey-----------------
#endif


    //-------------------mjpg Connection-----------------
    ofImage img;
    ofFbo screenFbo;

    cv::VideoCapture cap;
    cv::Mat frame;
    //-------------------mjpg Connection-----------------

    void setup(int i){
        selfIndex = i;

        //---------------------------mjpg Connection-------------------------------------

        if(!img.isAllocated()){
            img.allocate(CAM_WIDTH, CROP_HEIGHT, OF_IMAGE_COLOR);
        }else{
            cout << "Already allocated" << endl;
        }
        screenFbo.allocate(CAM_WIDTH, CROP_HEIGHT);

        cap.set(CV_CAP_PROP_BUFFERSIZE, 3); // internal buffer will now store only 3 frames
        cap.set(CV_CAP_PROP_FPS, 0);

        switch(i){
            case 0:
                cap = cv::VideoCapture("http://52.197.48.133:8080/?action=stream&type=mjpg");
                break;
            case 1:
                cap = cv::VideoCapture("http://52.197.48.133:8082/?action=stream&type=mjpg");
                break;
            case 2:
                cap = cv::VideoCapture("http://52.197.48.133:8081/?action=stream&type=mjpg");
                break;
            case 3:
                cap = cv::VideoCapture("http://52.197.48.133:8083/?action=stream&type=mjpg");
                break;
            default:
                break;

        }
        //---------------------------mjpg Connection--------------------------------------

#ifdef CHROMAKEY
        //-----------------------------------Chromakey Shader--------------------------------
        bUpdateBgColor = true;

        //以下取得する画像の大きさの比に合わせる
        chromakey = new ofxChromaKeyShader(CAM_WIDTH, CROP_HEIGHT);

        // maskee
        bg_image.load("black.jpg");//真っ黒背景(問題ないきがする)
        //-----------------------------------Chromakey Shader--------------------------------

        //---------------------GUI---------------------
        chromaGui.setDefaultHeight(24);
        chromaGui.setDefaultWidth(camW/2);
        chromaGui.setup();
        chromaGui.add(chromakey->generalParams);
        chromaGui.add(chromakey->positionParams);
        chromaGui.setPosition(0, 0);
        //---------------------GUI---------------------
#endif
    }

    void update(){

        //-------------取得した videocapture をchromakeyにセット--------------
        if (cap.isOpened() ){
            cap >> frame;
            if(frame.empty()){
                cout << "empty" << endl;
                //                    break;
            }else{
                cout << "open video" << endl;
                img.setFromPixels(frame.ptr(), frame.cols, frame.rows, OF_IMAGE_COLOR,FALSE);//RaspPiからの入力はBGRじゃないのでfalseを引数に入れない
#ifdef CHROMAKEY
                if(bUpdateBgColor && img.isAllocated())
                    chromakey->updateBgColor(img.getPixels());//Chromakeyに新しいPixelを入れる
                chromakey->updateChromakeyMask(img.getTexture(), bg_image.getTexture());
#endif
            }
            if(cv::waitKey(30) >= 0) {
                //                    break;
            }
        }

        //-------------取得した videocapture をchromakeyにセット--------------

    }

    void draw(){

    }

    // the thread function
    void threadedFunction() {

        ofxOpenGLContextScope scope; // crash if commented out
        // start

        while(isThreadRunning()) {

            // lock access to the resource
            lock();

            // load the image
            update();

            //            draw(selfIndex);
            // done with the resource
            unlock();
        }
        
        // done
#ifdef CHROMAKEY
        delete chromakey;//exit()に相当
#endif
    }
    
};

#endif /* CvParallelThread_hpp */
