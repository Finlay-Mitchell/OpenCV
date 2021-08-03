#include "FaceRecognition.h"

std::string FaceRecognition::face_cascade_name;

FaceRecognition::FaceRecognition() {}

void FaceRecognition::DrawFaceBox(cv::VideoCapture videoCapture)
{
	cv::Mat frame;
	videoCapture.read(frame);

	cv::putText(frame, Utils::getFPS(videoCapture), cv::Point(0, 25), cv::FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255, 255), 2);
	imshow("Face Detection", frame);
}