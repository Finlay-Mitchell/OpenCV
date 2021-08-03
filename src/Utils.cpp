#include "Utils.h"
#include "Face recognition/FaceRecognition.h"

Utils::Utils() {}

Utils::~Utils() {}

std::string Utils::frameTitle;
std::string Utils::captureSource;

void Utils::log(std::string message, uint_fast8_t loggingLevel)
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t in_time_t = std::chrono::system_clock::to_time_t(now);

    switch (loggingLevel)
    {
    case 1:
        std::cout << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X") << " test" << std::endl;
        break;
    }
}

uint Utils::displayImage(cv::Mat frame)
{
    Utils::log("test", 1);
    cv::imshow(frameTitle, frame);
    cv::namedWindow(frameTitle, cv::WINDOW_AUTOSIZE);

    if (cv::waitKey(30) == 27)
    {
        std::cout << "esc key is pressed by user" << std::endl;
        return 1;
    }
}

uint Utils::openAndReadCapture()
{
    cv::VideoCapture videoCapture(captureSource);

    if (!videoCapture.isOpened()) 
    {
        std::cerr << "Cannot open the video cam\n";
        return -1;
    }

    double dWidth = videoCapture.get(cv::CAP_PROP_FRAME_WIDTH);
    double dHeight = videoCapture.get(cv::CAP_PROP_FRAME_HEIGHT);
    std::cout << "Frame size : " << dWidth << " x " << dHeight << std::endl;
    FaceRecognition* facialRecognition = new FaceRecognition();

    while (1)
    {

        cv::Mat frame;
        bool videoCaptureReadSuccess = videoCapture.read(frame);

        if (!videoCaptureReadSuccess)
        {
            std::cout << "Cannot read a frame from video stream" << std::endl;
            break;
        }

        uint displayResult = Utils::displayImage(frame);

        if (displayResult == 1)
        {
            break;
        }

        facialRecognition->DrawFaceBox(frame);
    }

    delete facialRecognition;
    return 0;
}