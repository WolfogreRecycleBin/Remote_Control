#include "ofApp.h"
#include <cmath>
#include <fstream>
const double damp=0.99;
class Ball
{
//private:
public:
	double x,y,r,vx,vy;
	ofColor color;
public:
	Ball(double x_=100,double y_=100,double r_=20,double vx_=0,double vy_=0,ofColor color_=ofColor(0,0,0))
	{
		x=x_;y=y_;r=r_;vx=vx_;vy=vy_;color=color_;
	};
	~Ball(){};
	void Draw()
	{
		ofSetColor(color);
		ofCircle(x,y,r);
	}
	void Update(double ax=0,double ay=0)
	{
		vx+=ax;
		vy+=ay;
		vx*=damp;
		vy*=damp;
		if(x>=800) vx=-abs(vx);
		if(x<=0) vx=abs(vx);
		if(y>=600) vy=-abs(vy);
		if(y<=0) vy=abs(vy);
		x+=vx;
		y+=vy;
	}
};

Ball aim(800/2,600/2,30,-5,20);
int ex_fase_x=-1,ex_fase_y=-1;
int fase_x=-1,fase_y=-1;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
	ofBackground(200,200,200);

}

//--------------------------------------------------------------
void ofApp::update(){
    ifstream fin("data.lw");
    if (fin)
    {
        cout << "文件有效,";
        if(fin>>fase_x>>fase_y)
            cout << "读到" << fase_x<<" "<<fase_y << endl;
        else
        {
            cout << "没有读到" << endl;
        }
    }
    else
    {
        cout << "文件无效" << endl;
    }
    if(ex_fase_x==-1 && ex_fase_x==-1)
    {
        ex_fase_x=fase_x;
        ex_fase_y=fase_y;
        aim.Update();
    }
    else
    {
        aim.Update(fase_x-ex_fase_x,fase_y-ex_fase_y);
        ex_fase_x=fase_x;
        ex_fase_y=fase_y;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofDrawBitmapString("FPS:"+ofToString(ofGetFrameRate()), 10, 15);
    ofDrawBitmapString("x:"+ofToString(aim.x), 10, 25);
    ofDrawBitmapString("y:"+ofToString(aim.y), 10, 35);
    aim.Draw();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
