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
	static std::string captureSource;

	static void log(std::string, uint_fast8_t);
	static void displayImage(cv::Mat);
	static uint openAndReadCapture();
	static void DrawFPSCount(cv::VideoCapture&, cv::Mat&);
	static std::string getFPS(cv::VideoCapture);
	~Utils();
};

#endif