#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

// #ifdef _DEBUG
// #pragma comment(lib, "E:\\opencv300\\build\\x86\\vc11\\lib\\opencv_world300d.lib")
// #else 
// #pragma comment(lib, "E:\\opencv300\\build\\x86\\vc11\\lib\\opencv_world300.lib")
// #endif

int main(int argc, char* argv[])
{
	Mat frame;
	namedWindow("video", 1);
	VideoCapture cap("http://192.168.12.24:7890/ipvideo.mjpg");
	while ( cap.isOpened() )
	{
	    cap >> frame;
	    if(frame.empty()){
			cout << "empty" << endl;
			break;
		}

	    imshow("video", frame);
	    if(waitKey(30) >= 0) break;
	}   

	return 0;
}