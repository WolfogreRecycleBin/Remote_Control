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
	cout << "�������ر�����ͷ..." << endl;
}
void LoadCascadeFile(CascadeClassifier &cascade, string cascade_file)
{
	cascade.load(cascade_file);
	if (cascade.empty())
	{
		cout << "û����ȷ�����ļ�" << cascade_file << endl;
		system("pause");
		exit(-1);
	}
	cout << "����ȷ�����ļ�" << cascade_file << endl;
}
void OpenVideo(VideoCapture &cap)
{
	cap.open(0);
	if (!cap.isOpened())
	{
		cout << "����ͷû����ȷ�򿪣������豸�Ƿ�������" << endl;
		system("pause");
		exit(-1);
	}
	cout << "����ͷ��������..." << endl;
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
		cout << "û�м�⵽" << endl;
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
	imshow("���������", frame);
		
}

/*void DetectAndDisplay(Mat frame);
CascadeClassifier face_cascade;

int main(void)
{
	string face_cascade_name = "haarcascade_frontalface_alt.xml";
	face_cascade.load(face_cascade_name);
	if (face_cascade.empty())
		cout << "û����ȷ�����ļ�" << face_cascade_name << endl;
	else
		cout << "����ȷ�����ļ�" << face_cascade_name << endl;
	
	//������ͷ
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())
	{
		cout
			<< "����ͷû����ȷ�򿪣������豸�Ƿ�������" << endl;
		system("pause");
		return -1;
	}
	cout << "����ͷ��������..." << endl;

	//����ͼ�񣬼�Ⲣ��ʾ
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
			cout << "�������ر�����ͷ..." << endl;
			break;
		}
	}

	return 0;
}

void DetectAndDisplay(Mat frame)
{
	//ԭͼ���
	vector<Rect> faces;
	
	face_cascade.detectMultiScale(frame, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
	for (int i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
		circle(frame, center, (faces[i].width + faces[i].height)*0.25, Scalar(0, 0, 255), 3);
	}
	imshow("���������", frame);
}
*/