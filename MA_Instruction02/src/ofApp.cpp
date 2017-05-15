#include "ofApp.h"
#define INITIAL_NUM_OF_POLYGONS 10

/*
 * ofAppクラスのsetup()メソッドを定義する。
 * ::は「スコープ解決演算子」と呼ばれるもので、名前空間のduplicate(重複)をさける役割があります。
 * namespace(名前空間)もしくはClassで分ける。
 * C++ において、::(スコープ解決)演算子は、スコープ外の変数名または関数名のグローバル識別子です。
 * どのクラスのsetup()なのかを明示しています。
 */

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetSphereResolution(100);
    ofEnableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    //ofToggleFullscreen();
    for (int i=0; i<INITIAL_NUM_OF_POLYGONS; i++){
        polygons.push_back(new Polygon3d());//動的配列生成
        /*
         * 動的配列Polygon3d型のpolygonsの最後尾に引数のとデータを付け足します。
         * 「new演算子」を使用することで、オブジェクトを任意のタイミングで動的に生成することが可能となります。
         * new演算子は、記憶領域の空き領域(ヒープ heap)から指定したクラスを大きさの領域を確保します。
         * その際、new演算子は確保した領域のアドレスを返します。
         * この動的な記憶領域のエイリアスを使用するために、ポインタを利用します。
         * 上記の場合、new Polygon3d()で生成されるものは 
         * Polygon3dクラスのオブジェクトそのものではなく、Polygon3dクラスのオブジェクトをさしているポインタです。
         */
    }
    for (int i=0; i<polygons.size(); i++) {
        polygons.at(i)->setPolygonPosition(ofRandom(-2000, 2000),ofRandom(-2000, 2000),ofRandom(-2000, 2000));//動的配列の要素の座標を初期化
        /*
         * vector.at(x)はx番目の動的配列データへのアクセスを行う、vector[x]でも同じ動作を実行できる
         * 今回生成されて、配列に格納されているのは、オブジェクトへのポインタであるから、アロー演算子を使う
         * (動的に生成したオブジェクトのポインタから、そのメンバであるメソッドやプロパティを参照するには、ドット演算子「.」の代わりに、アロー演算子「->」を用います。)
         */
        polygons.at(i)->setPolygonType(floor(ofRandom(11)));
        //Floor関数で(0,2)のランダムの数値を50%の確率を維持したまま0または1に数値変換
        polygons.at(i)->setPolygonSize(floor(ofRandom(10,30)));
        //図形のサイズを初期化
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    if (accelFlag) cameraSpeed += 0.005; //accelFlagはfalseで初期化されている
    else if (cameraSpeed > 0) cameraSpeed -= 0.020; //accelFlagがtrueかつ、speedが正のとき、慣性をつけるために、実装
    else cameraSpeed = 0; //もし負になってしまえばスピードをゼロに初期化
    cameraPosition += cameraSpeed;//cameraPositionを更新
    
    camera.setPosition(2000*sin(cameraPosition), 0, 2000*cos(cameraPosition));
    //cameraPositionをパラメーターとして円軌道で移動
    camera.lookAt(ofVec3f(0, 0, 0));
    //カメラを移動させてもずっと、中心の座標(0,0,0)を見るようにカメラの 向きを自動調整してくれます。
    light.setPosition(2000*cos(cameraPosition), 0, 2000*sin(cameraPosition));
    light.lookAt(ofVec3f(0,0,0));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(ofColor::fromHsb((ofGetFrameNum())%255,255,255));
    ofPushMatrix();//座標系を保存
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    light.enable();
    camera.begin();
    float temp = ofRandom(0,1);
    for (int i = 0; i<polygons.size(); i++) {
        
        if(lineMode){
            ofLine(ofPoint(0,0,0), polygons.at(i)->getPolygonPosition());
        }else if(i!=0){
            ofLine(polygons.at(i-1)->getPolygonPosition(),polygons.at(i)->getPolygonPosition());
        }
        
        switch (polygons.at(i)->getPolygonType()) {//getPolygonTypeによって描画の図形を判定
            case 0://ボックスを描画
                boxPrimitive.setPosition(polygons.at(i)->getPolygonPosition());
                boxPrimitive.set(polygons.at(i)->getPolygonSize());
                boxPrimitive.draw();
                break;
            case 1://球体を描画
                spherePrimitive.setPosition(polygons.at(i)->getPolygonPosition());
                spherePrimitive.setRadius(polygons.at(i)->getPolygonSize()/2);
                spherePrimitive.draw();
            default:
                break;
        }
    }
    camera.end();
    light.disable();
    ofPopMatrix();//保存していた座標系を復元
    ofSetColor(255);
    ofDrawBitmapString("OBJECT COUNT:"+ofToString(polygons.size()),50,50);
    ofDrawBitmapString("CAMERA SPEED:"+ofToString(cameraSpeed),50,70);
    ofDrawBitmapString("ADD OBJECT:KEY_UP",50,90);
    ofDrawBitmapString("REMOVE OBJECT:KEY_DOWN",50,110);
    ofDrawBitmapString("SWITCH LINEMODE:KEY_RETURN",50,130);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
        accelFlag = true;
    } else if (key == 'f') {
        ofToggleFullscreen();
    }else if(key==OF_KEY_DOWN && polygons.size()>0){
        /* 動的に生成されたオブジェクトは、delete演算子を用いて破棄することが可能ですが、
         * detele演算子でオブジェクトを破棄することで、
         * 確保された領域は解放されまたヒープ領域(空領域)に戻され、再利用できるようになります。
         * new演算子とdelete演算子を適切なタイミングで使用することで、
         * メモリを効率良く使用しながらプログラムを実行することが可能となります。
         * 今回はpop_back()を使っています。
         */
        polygons.pop_back();
    }else if(key==OF_KEY_UP){
        polygons.push_back(new Polygon3d());
        polygons.back()->setPolygonPosition(ofRandom(-2000, 2000),ofRandom(-2000, 2000),ofRandom(-2000, 2000));
        polygons.back()->setPolygonType(floor(ofRandom(1)));
        polygons.back()->setPolygonSize(floor(ofRandom(20,300)));
    }else if(key==OF_KEY_RETURN){
        lineMode= !lineMode;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == ' '){
        accelFlag = false;
    }
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
