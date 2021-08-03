#pragma once

#ifndef UTILS_H
#define UTILS_H
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <chrono>
#include <iostream>
#include <ctime>
#include <iomanip>

#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

class Utils
{
public:
	Utils();

	static std::string frameTitle;
	static std::string face_cascade_name;
	static std::string eyes_cascade_name;
	static std::string captureSource;

	static void log(std::string, uint_fast8_t);
	static uint displayImage(cv::Mat);
	static uint openAndReadCapture();

	~Utils();
};

#endif