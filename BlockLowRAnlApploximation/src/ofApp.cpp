#include "ofApp.h"

void ofApp::import_matrix(FILE* fp,float* dist_matrix, const char * filename){
    char *buf;
    char *token;
    char seps[] = ",";// [,]文字による区切り-->CSVファイル
    // ファイルからの読込み
    int counter = 0;
    buf = (char *)malloc(11 * M * N * sizeof(char) );
    check_malloc_buf(buf);
    fp = fopen(filename,"r");
    while ( fgets(buf,11*M*N,fp) ) {
        token = (char*)strtok(buf,seps);
        while ( token != NULL ) { // buf にトークンがなくなるまで繰り返す
            sscanf(token,"%f",&dist_matrix[counter]);//float型でscan
            token = (char*)strtok(NULL,seps); // 次のトークンを取得
            // printf( "element: %f\n" ,dist_matrix[counter] );
            counter++;
        }
    }
    fclose(fp);
    if(buf!=NULL)free(buf);
    printf( "num of elements: %d\n" ,counter );
}

void ofApp::check_malloc_buf(char* buf){
    if (buf == NULL ) {
        free(buf);
        exit();
    }
}


//--------------------------------------------------------------
void ofApp::setup(){
    A = (float *)malloc( M*K*sizeof(float) );
    FILE *fp;
    import_matrix(fp,A,CSVFILE);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            ofSetColor(ofMap(A[j+i*N], 0, 5, 0, 255));
            ofDrawRectangle(j*2, i*2, 2, 2);
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


