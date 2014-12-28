#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
void LoadCascadeFile(CascadeClassifier &cascade, string cascade_file);
void OpenVideo(VideoCapture &cap);
void DetectAndOutput(CascadeClassifier &cascade, Mat &frame, string output_filename);
int main(void)
{
	CascadeClassifier face_cascade;
	LoadCascadeFile(face_cascade, "haarcascade_frontalface_alt.xml");
	VideoCapture cap;
	OpenVideo(cap);

	Mat frame;
	char key;
	while (true)
	{
		cap >> frame;
		DetectAndOutput(face_cascade,frame,"data.lw");
		key = waitKey(1);
		if (key == ' ') break;
	}
	destroyAllWindows();
	cap.release();
	cout << "已正常关闭摄像头..." << endl;
}
void LoadCascadeFile(CascadeClassifier &cascade, string cascade_file)
{
	cascade.load(cascade_file);
	if (cascade.empty())
	{
		cout << "没有正确加载文件" << cascade_file << endl;
		system("pause");
		exit(-1);
	}
	cout << "已正确加载文件" << cascade_file << endl;
}
void OpenVideo(VideoCapture &cap)
{
	cap.open(0);
	if (!cap.isOpened())
	{
		cout << "摄像头没有正确打开，请检查设备是否正常！" << endl;
		system("pause");
		exit(-1);
	}
	cout << "摄像头已正常打开..." << endl;
}
void DetectAndOutput(CascadeClassifier &cascade, Mat &frame, string output_filename)
{
	vector<Rect> aims;
	cascade.detectMultiScale(frame, aims, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
	if (aims.size() > 0)
	{ 
		cout << aims[0].x << " " << aims[0].y << endl;
		ofstream fout(output_filename);
		if (fout) fout << aims[0].x << " " << aims[0].y << endl;
		fout.close();
	}
	else
	{
		cout << "没有检测到" << endl;
	}
	for (int i = 0; i < aims.size(); i++)
	{
		Point center(aims[i].x + aims[i].width*0.5, aims[i].y + aims[i].height*0.5);
		circle(frame, center, (aims[i].width + aims[i].height)*0.25, Scalar(0, 0, 255), 3);
	}
	const double new_row = 200;
	double new_col = new_row / frame.rows * frame.cols;
	Size new_size(new_col, new_row);
	resize(frame, frame, new_size);
	imshow("人脸检测结果", frame);
		
}

/*void DetectAndDisplay(Mat frame);
CascadeClassifier face_cascade;

int main(void)
{
	string face_cascade_name = "haarcascade_frontalface_alt.xml";
	face_cascade.load(face_cascade_name);
	if (face_cascade.empty())
		cout << "没有正确加载文件" << face_cascade_name << endl;
	else
		cout << "已正确加载文件" << face_cascade_name << endl;
	
	//打开摄像头
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())
	{
		cout
			<< "摄像头没有正确打开，请检查设备是否正常！" << endl;
		system("pause");
		return -1;
	}
	cout << "摄像头已正常打开..." << endl;

	//捕获图像，检测并显示
	Mat frame;
	char key;
	while (true)
	{
		cap >> frame;
		DetectAndDisplay(frame);
		key=waitKey(1);
		if (key == ' ')
		{
			destroyAllWindows();
			cap.release();
			cout << "已正常关闭摄像头..." << endl;
			break;
		}
	}

	return 0;
}

void DetectAndDisplay(Mat frame)
{
	//原图检测
	vector<Rect> faces;
	
	face_cascade.detectMultiScale(frame, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
	for (int i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
		circle(frame, center, (faces[i].width + faces[i].height)*0.25, Scalar(0, 0, 255), 3);
	}
	imshow("人脸检测结果", frame);
}
*/