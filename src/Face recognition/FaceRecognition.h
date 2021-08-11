#pragma once 

#ifndef FACERECOGNITION_H
#define FACERECOGNITION_H

#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include "../Utils.h"

class FaceRecognition
{
public:
	FaceRecognition();

	static std::string face_cascade_name;
	
	void LoadCascades();
	void DrawFaceBox(cv::VideoCapture&, cv::Mat&);

private:
	cv::CascadeClassifier cascade;
};

#endif