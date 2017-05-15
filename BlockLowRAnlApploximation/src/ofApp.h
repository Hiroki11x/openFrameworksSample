#pragma once


//#define A_CSVFILE "scale1Conv2D/A.csv"
//#define B_CSVFILE "scale1Conv2D/B.csv"

 #define CSVFILE "output.csv"

#define min(x,y) (((x) < (y)) ? (x) : (y))
#define max(x,y) (((x) > (y)) ? (x) : (y))



#define MIN_GEMM_SIZE 4
#define MAX_GEMM_SIZE min(M,N)

 #define M 16/MIN_GEMM_SIZE
 #define K 27/MIN_GEMM_SIZE
 #define N 147968/MIN_GEMM_SIZE

#define F_A_LDA K
#define F_A_LDU K
#define F_A_LDVT M

#define F_B_LDB N
#define F_B_LDU N
#define F_B_LDVT K


#include "ofMain.h"

float *A;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    //行列のCSVからのロードを行う
    void import_matrix(FILE* fp,
                              float* dist_matrix,
                              const char * filename);

     void check_malloc_buf(char* buf);

};
