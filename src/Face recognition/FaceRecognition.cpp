#include "FaceRecognition.h"

std::string FaceRecognition::face_cascade_name;
cv::CascadeClassifier cC;
FaceRecognition::FaceRecognition() 
{
	LoadCascades();
	cC = cascade;
}

/// <summary>
/// This is responsible for recognising faces within the image and drawing a box around the faces.
/// </summary>
/// <param name="videoCapture">This is the video capture feed.</param>
/// <param name="frame">This is the frame we want to draw too.</param>
void FaceRecognition::DrawFaceBox(cv::VideoCapture& videoCapture, cv::Mat& frame)
{
    double scale = 1;
	std::vector<cv::Rect> faces;
    cv::Mat smallImg;

	cC.detectMultiScale(smallImg, faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

    for (size_t i = 0; i < faces.size(); i++)
    {
        cv::Rect r = faces[i];
        cv::Point center;
        cv::Scalar colour = cv::Scalar(255, 0, 0); // Color for Drawing tool
        int radius;

        double aspect_ratio = (double)r.width / r.height;

        if (0.75 < aspect_ratio && aspect_ratio < 1.3)
        {
            center.x = cvRound((r.x + r.width * 0.5) * scale);
            center.y = cvRound((r.y + r.height * 0.5) * scale);
            radius = cvRound((r.width + r.height) * 0.25 * scale);
            circle(frame, center, radius, colour, 3, 8, 0);
        }

        else
          rectangle(frame, cv::Point(cvRound(r.x * scale), cvRound(r.y * scale)),  cv::Point(cvRound((r.x + r.width - 1) * scale), cvRound((r.y + r.height - 1) * scale)), colour, 3, 8, 0);
    }
}

void FaceRecognition::LoadCascades()
{
	cascade.load(face_cascade_name);
}