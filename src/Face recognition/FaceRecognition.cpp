#include "FaceRecognition.h"

std::string FaceRecognition::face_cascade_name;

FaceRecognition::FaceRecognition() {}

void FaceRecognition::DrawFaceBox(cv::Mat frame) 
{
	cv::CascadeClassifier faceCascade = cv::CascadeClassifier(face_cascade_name);
	std::vector<cv::Rect> faces;
	faceCascade.detectMultiScale(frame, faces, 1.1, 5, cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

	for (std::vector<cv::Rect>::iterator it = faces.begin(); it != faces.end(); it++)
	{	
		cv::Rect r = *it;
		cv::putText(frame, "Face detected", cv::Point(r.x, r.y - 10), cv::FONT_HERSHEY_SIMPLEX, 0.9, (36, 255, 12), 2);
		cv::rectangle(frame, *it, cv::Scalar(0, 255, 0), 2);
	}

	cv::putText(frame, "test", cv::Point(0, 25), cv::FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255, 255), 2);

	imshow("Face Detection", frame);

}