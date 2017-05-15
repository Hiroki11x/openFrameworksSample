#include "ofApp.h"

void ofApp::check_malloc_buf(char* buf){
    if (buf == NULL ) {
        free(buf);
        exit();
    }
}


//--------------------------------------------------------------
void ofApp::setup(){
    width = (int)ceil(double(MY_K) / double(BLOCKSIZE));
    height = (int)ceil(double(MY_M) / double(BLOCKSIZE));
    A = new float[width*height];
    ifstream ifs(CSVFILE);
    if(!ifs){
        cout<<"入力エラー";
        return 1;
    }
    int counter = 0;

    max =0;
    average =0;

    //csvファイルを1行ずつ読み込む
    string str;
    while(getline(ifs,str)){
        string token;
        istringstream stream(str);

        //1行のうち、文字列とコンマを分割する
        while(getline(stream,token,',')){
            //すべて文字列として読み込まれるため
            //数値は変換が必要
            float temp = stof(token); //stof(string str) : stringをfloatに変換
            A[counter]=temp;
            average+=temp;
            if(max<temp)max = temp;
            counter++;
        }
    }
    cout << "num of elements: " << counter << endl;

    average/=counter;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetWindowTitle("average:"+ofToString(average));

    int size = 10;
    int offset_y = 0;
    int offset_x = 610;
    int offset_helper;
    int x,y;

    ofDrawBitmapStringHighlight("scale1Conv2D/images_27x147968 BLOCKSIZE:27 THRESHOLD 99% :max_rank: "+ofToString(max), 54,30);
    ofPushMatrix();
    ofTranslate(-400,35);


    ofDrawBitmapStringHighlight("Low Rank", offset_x-70, 30);
    for(int i = 0; i<= BLOCKSIZE; i++){
//        if(i%10==0){
            ofSetColor(ofColor::fromHsb(ofMap(i, 0, BLOCKSIZE, 150, 250), 255, 255));
            ofDrawRectangle(offset_x+i*size, 30-size, size, size);
//        }
    }

    ofDrawBitmapStringHighlight("High Rank", offset_x+(BLOCKSIZE+1)*size+5, 30);

    ofPopMatrix();
    ofTranslate(50,80);

    int j_index;
//
//        for(int j=0; j<width; j++){
//            for(int i=0 ; i < height ;i++){
//                ofSetColor(ofColor::fromHsb(ofMap(A[j+i*width], 0, BLOCKSIZE, 150, 250), 255, 255));
//                x = j*size ;//- offset_helper;
//                y = i*size ;//+ offset_y;
//                ofDrawRectangle(x, y, size, size);
//            }
//            j_index = j;
//        }

    for(int j=0; j*size<ofGetWidth()-100; j++){
        for(int i=0 ; i < height ;i++){
            ofSetColor(ofColor::fromHsb(ofMap(A[j+i*width], 0, BLOCKSIZE, 150, 250), 255, 255));
            x = j*size ;//- offset_helper;
            y = i*size ;//+ offset_y;
            ofDrawRectangle(x, y, size, size);
        }
        j_index = j;
    }


    offset_y += size*(height+1);

    for(int j=j_index; (j-j_index)*size<ofGetWidth()-100; j++){
        for(int i=0 ; i < height ;i++){
            ofSetColor(ofColor::fromHsb(ofMap(A[j+i*width], 0, BLOCKSIZE, 150, 250), 255, 255));
            x = (j-j_index)*size ;//- offset_helper;
            y = i*size + offset_y;
            ofDrawRectangle(x, y, size, size);
        }
    }

    offset_y += size*(height+1);
    j_index += j_index;

    for(int j=j_index; (j-j_index)*size<ofGetWidth()-100; j++){
        for(int i=0 ; i < height ;i++){
            ofSetColor(ofColor::fromHsb(ofMap(A[j+i*width], 0, BLOCKSIZE, 150, 250), 255, 255));
            x = (j-j_index)*size ;//- offset_helper;
            y = i*size + offset_y;
            ofDrawRectangle(x, y, size, size);
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}


