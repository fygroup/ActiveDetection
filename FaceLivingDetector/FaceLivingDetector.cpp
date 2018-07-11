// FaceLivingDetector.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace dlib;
using namespace std;
using namespace cv;

int main()
{
	frontal_face_detector detector = get_frontal_face_detector();
	Mat img = imread("test.jpg");
	imshow("mat", img);
	waitKey(0);

    return 0;
}

