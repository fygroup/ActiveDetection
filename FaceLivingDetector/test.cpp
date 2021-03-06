// FaceLivingDetector.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <time.h>
#include "FaceLivingDetector.h"
#include <type_traits>
using namespace std;
using namespace cv;

void FindFaceTest()
{
	VideoCapture cp(0);
	Mat frame;
	while (true) {
		cp >> frame;
		if (frame.empty()) continue;
		Rect face_rect = FaceLivingDetector::findFaceRect(frame);
		rectangle(frame, face_rect, Scalar(0, 255, 0));
		imshow("frame", frame);
		waitKey(10);
	}
}

void ActiveTest()
{
	bool begin = true;
	VideoCapture cp(0);
	Mat frame;
	stringstream ss;
	while (true) {
		cp >> frame;
		if (frame.empty()) continue;
		int ret = FaceLivingDetector::aliveDetect(frame, FaceLivingDetector::Action::shake, 10000, begin);
		begin = false;
		cout << ret << endl;
		imshow("frame", frame);
		waitKey(10);
	}
}

void CompareTest()
{
	
	string path1 = "";
	string path2 = "";
	Mat img1 = imread(path1);
	Mat img2 = imread(path2);
	time_t start = clock();
	double ret = 0;
	ret = FaceLivingDetector::faceCompare(img1, img2); 
	cout << ret << " " << clock() - start << endl;
}

int main()
{
	const string detector_model_path = "..\\models\\shape_predictor_68_face_landmarks.dat";
	const string resnet_model_path = "..\\models\\dlib_face_recognition_resnet_model_v1.dat";
	FaceLivingDetector::initDetector(detector_model_path, resnet_model_path);
	ActiveTest();
    return 0;
}

