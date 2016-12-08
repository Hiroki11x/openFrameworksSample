#pragma once
#define PERSON 192

#include "ofMain.h"

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    float x_p[PERSON];//position of x
    float y_p[PERSON];//position of x
    float potential_i[PERSON];//control size and time of recover
    float immunity[PERSON];//immunity ex people infected ,lessen potential of get sick
    float immunity2[12][16];
    int x,y,num,time,sum,peaktime,record,j;
    bool Q_infected(int i);
    bool infected[PERSON];//if infected true for num value
    bool inf_change[12][16];//if infected true for x y value
    bool inf_temp[12][16];//if infected true temporary value
    bool which; //control key
    bool Q_alive();//function of return death(false) or alive(true)
    bool alive[PERSON];//if dead false for num
    bool alive2[12][16];//if dead false for num
    int num_die;// number of dead people
    int sum_inf;//Number of people experienced infected
    float pos_inf,tmp;
};

