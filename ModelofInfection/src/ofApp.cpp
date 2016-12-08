#include "ofApp.h"
#define RADIUS 20
#define RATE 3 //Renew screen per (RATE/60) second

//--------------------------------------------------------------
void ofApp::setup(){
    
    //Initialize
    num=0;
    time=0;
    num_die=0;
    peaktime=0;
    record=0;
    sum_inf=0;
    which=false;
    pos_inf=0.20;//set number >0.15
    
    //Calculate Infected possibility
    tmp=1;
    for (j; j<8; j++) {
        tmp*=(1.0-pos_inf);
    }
    tmp=1-tmp;
    
    //enable alpha
	ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofEnableSmoothing();
    ofSetFrameRate(60);
   
    //Initialize
    for (y=0; y<12; y++) {
        for (x=0; x<16; x++){
            x_p[num]=((ofGetWidth()*((float)x/16))+60);
            y_p[num]=((ofGetHeight()*((float)y/12))+50);
            infected[num]=false;
            inf_change[y][x]=false;
            inf_temp[y][x]=false;
            alive[num]=true;
            alive2[y][x]=true;
            potential_i[num]=1;
            immunity[num]=0.0;
            immunity2[y][x]=0.0;
            num++;
            sum_inf=0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    if(time%RATE==0){//Renew per one second
        num=0;
        sum_inf=0;
        sum=0;  //Count infected peoples
        
        //Copy immunity[num] to immunity2[y][x]
        for (y=0; y<12; y++) {
            for (x=0; x<16; x++){
                immunity2[y][x]=immunity[num];
                num++;
            }
        }
        num=0;
        for (y=0; y<12; y++) {
            for (x=0; x<16; x++){
                
                //if people have sick , he affect around people
                if((inf_change[y][x]==true)&&(alive2[y][x]==true)&&(immunity[num]<10.0)){
                
                    //copy inf_change to inf_temp
                    inf_temp[y][x]=true;
                
                    alive2[y][x]==true;
                    
                    //infect around person(y,x)
                    //if you are (3,3), you have 8 risk at most. 8 is number of around infected people
                    
                    //(-1,+1)
                    if((x!=15)&&(y!=0)&&(inf_change[y-1][x+1]==false)&&(alive2[y-1][x+1]==true)&&(immunity2[y-1][x+1]<10.0)){
                        inf_temp[y-1][x+1]=Q_infected(num);
                        if(Q_alive()==false){
                            num_die++;
                            alive2[y-1][x+1]=false;
                        }
                    }
                    //(+1,+1)
                    if((x!=15)&&(y!=11)&&(inf_change[y+1][x+1]==false)&&(alive2[y+1][x+1]==true)&&(immunity2[y+1][x+1]<10.0)){
                       inf_temp[y+1][x+1]=Q_infected(num);
                        if(Q_alive()==false){
                            num_die++;
                            alive2[y+1][x+1]=false;
                        }
                    }
                    //(-1,-1)
                    if((x!=0)&&(y!=0)&&(inf_change[y-1][x-1]==false)&&(alive2[y-1][x-1]==true)&&(immunity2[y-1][x-1]<10.0)){
                        inf_temp[y-1][x-1]=Q_infected(num);
                        if(Q_alive()==false){
                            num_die++;
                            alive2[y-1][x-1]=false;
                        }
                    }
                    //(+1,-1)
                    if((x!=0)&&(y!=11)&&(inf_change[y+1][x-1]==false)&&(alive2[y+1][x-1]==true)&&(immunity2[y+1][x-1]<10.0)){
                        inf_temp[y+1][x-1]=Q_infected(num);
                        if(Q_alive()==false){
                            num_die++;
                            alive2[y+1][x-1]=false;
                        }
                    }
                    //(0,+1)
                    if((x!=15)&&(inf_change[y][x+1]==false)&&(alive2[y][x+1]==true)&&(immunity2[y][x+1]<10.0)){
                        inf_temp[y][x+1]=Q_infected(num);
                        if(Q_alive()==false){
                            num_die++;
                            alive2[y][x+1]=false;
                        }
                    }
                    //(+1,0)
                    if((y!=11)&&(inf_change[y+1][x]==false)&&(alive2[y+1][x]==true)&&(immunity2[y+1][x]<10.0)){
                        inf_temp[y+1][x]=Q_infected(num);
                        if(Q_alive()==false){
                            num_die++;
                            alive2[y+1][x]=false;
                        }
                    }
                    //(-1,0)
                    if((y!=0)&&(inf_change[y-1][x]==false)&&(alive2[y-1][x]==true)&&(immunity2[y-1][x]<10.0)){
                        inf_temp[y-1][x]=Q_infected(num);
                        if(Q_alive()==false){
                            num_die++;
                            alive2[y-1][x]=false;
                        }
                    }
                    //(0,-1)
                    if((x!=0)&&(inf_change[y][x-1]==false)&&(alive2[y][x-1]==true)&&(immunity2[y][x-1]<10.0)){
                        inf_temp[y][x-1]=Q_infected(num);
                        if(Q_alive()==false){
                            num_die++;
                            alive2[y][x-1]=false;
                        }
                    }
               
                    //immunity people get more immunity
                    immunity[num]+=0.015;
                    
                    
                    //increment
                    num++;
                    sum++;
                 
                }//if statement of true finish
                
            }//for statement of X
        }//for statement of Y
        
        //initialize
        num=0;
        for (y=0; y<12; y++) {
            for (x=0; x<16; x++){
                
                //Syncronize immunity[num] to immunity2[y][x]
                immunity2[y][x]=immunity[num];
                
                if(potential_i[num]!=1)sum_inf++;//Count experienced infected peoples
                
                //copy to inf_change
                inf_change[y][x]=inf_temp[y][x];
                
                //copy inf_change to infected
                infected[num]=inf_change[y][x];
                
                //copy alive2 to alive
                alive[num]=alive2[y][x];
               
                //to people revive & visual of infect
                if(infected[num]==true){
                    
                    //increment
                    potential_i[num]+=1;
                    
                    if((potential_i[num])>10){
                        
                        //initialize
                        potential_i[num]/=2;
                        
                        //recover
                        infected[num]=false;
                        inf_change[y][x]=false;
                        inf_temp[y][x]=false;
                        
                    
                    }//if statement finish
                }//if statement of to people revive & visual of infect finish
                
                //increment
                num+=1;
                
            }//for statement of x
        }//for statement of y
    }//finish if statement  of Renew per one second
    time++;
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,0,0);
    for(num=0;num<PERSON;num++){
        
        //if people don't have sick
        if((infected[num]==false)&&(alive[num]==true)&&(immunity[num]<10.0)){
            ofSetColor(0,255,255,250);
            ofCircle(x_p[num], y_p[num], RADIUS/8);
            ofSetColor(0,200,200,150);
            ofCircle(x_p[num], y_p[num], RADIUS/4);
            ofSetColor(0,150,150,70);
            ofCircle(x_p[num], y_p[num], RADIUS/2);
            ofSetColor(0,150,150,25);
            ofCircle(x_p[num], y_p[num], RADIUS*(potential_i[num]));
            
            //key control
            if(which==true){
                
                ofSetColor(20, 20,0,10);
                ofCircle(mouseX, mouseY, 10);
            }
        
        //if people have sick
        }else if((infected[num]==true)&&(alive[num]==true)&&(immunity[num]<10.0)){
            ofSetColor(255,20,20,250);
            ofCircle(x_p[num], y_p[num], RADIUS/4);
            ofSetColor(255,20,20,100);
            ofCircle(x_p[num], y_p[num], RADIUS/2);
            ofSetColor(200,20,20,25);
            ofCircle(x_p[num], y_p[num], RADIUS*((potential_i[num])/2));
            
        //if people died
        }else if(alive[num]==false){
            
            ofSetColor(255,0,255,255);
            ofCircle(x_p[num], y_p[num], RADIUS/4);
            ofSetColor(255,0,255,120);
            ofCircle(x_p[num], y_p[num], RADIUS/2);
            ofSetColor(200,0,255,40);
            ofCircle(x_p[num], y_p[num], RADIUS*2);
            
        //people who injected Vaccine
        }else if((immunity[num]>=10)&&(infected[num]==false)){
            ofSetColor(0,255,0,255);
            ofCircle(x_p[num], y_p[num], RADIUS/4);
            ofSetColor(0,255,0,125);
            ofCircle(x_p[num], y_p[num], RADIUS/2);
            ofSetColor(0,255,0,40);
            ofCircle(x_p[num], y_p[num], RADIUS*2);
        }
    }
    //Display number data
    ofSetColor(255,255,255,255);
    
    //theme
    ofDrawBitmapString("Infection Model Simulation:v.0.1.1", ofGetWidth()-300, ofGetHeight()-30);
    
    //Current term
    ofDrawBitmapString("Now tern:"+ofToString((time/RATE),0), 20, 20);
    
    //Number of Normal people
    ofDrawBitmapString("Non virus carier person:"+ofToString(PERSON-sum-num_die,0), 20, 100);
    
    //Number of infected people
    ofDrawBitmapString("Infected person:"+ofToString(sum,0), 20, 80);
    
    //Number of died people
    ofDrawBitmapString("Died person:"+ofToString(num_die,0), 20, 60);
    
    //Number of people who experienced infection
    ofDrawBitmapString("Have infected person:"+ofToString(sum_inf,0), 20, 120);
    
    if((sum+num_die)>record){
        peaktime=time;
        record=(sum+num_die);
    }
    
    //Peak time
    ofDrawBitmapString("Peak tern:"+ofToString((peaktime/RATE),0), 20, 40);

    //Infect possibility
    ofDrawBitmapString("Infected possibility:"+ofToString(tmp*100,0)+"%", 20, 140);

}
//--------------------------------------------------------------
bool ofApp::Q_infected(int i){
    //if one turm person infected he get 0.015 immunity ,so when recover he has 0.15 immunity
    //Namely one person get sick again 5(=20-15) persent
    if(((ofRandom(0, 1))+immunity[i])>pos_inf){
        return false;
    }else{
        return true;
    }
}

bool ofApp::Q_alive(){
    //possibility of death is 0.05 persent
    if((ofRandom(0, 1))>0.9995){
        return false;
    }else{
        return true;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='v'){
        which=false;
    }else if(key=='i'){
        which=true;
    }else if(key == 'f') {
		ofToggleFullscreen();
    }
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
    if(which==false){
        
        //----------------------------User put virus to person who you choose----------------------------
        for (num=0; num<PERSON; num++) {
            if(((x_p[num]-RADIUS)<x)&&((y_p[num]-RADIUS)<y)&&((x_p[num]+RADIUS)>x)&&((y_p[num]+RADIUS)>y)){
                //make people infected
                infected[num]=true;
            }
        }
        //Initialize
        num=0;
        for (y=0; y<12; y++) {
            for (x=0; x<16; x++){
                
                //copy bool from infected[num] to inf_change[y][x]
                inf_change[y][x]=infected[num];
                num++;
            }
        }
        //--------------------------------------------------------------------------------------------------
    }else if (which==true){
        
        //------------------------------------------Inject Vaccine------------------------------------------
        for (num=0; num<PERSON; num++) {
            if(((x_p[num]-RADIUS)<x)&&((y_p[num]-RADIUS)<y)&&((x_p[num]+RADIUS)>x)&&((y_p[num]+RADIUS)>y)){
                immunity[num]=20.0;
                infected[num]=false;
            }
        }
        num=0;
        for (y=0; y<12; y++) {
            for (x=0; x<16; x++){
                immunity2[y][x]=immunity[num];
                num++;
            }
        }
        //--------------------------------------------------------------------------------------------------
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
