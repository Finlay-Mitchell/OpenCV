#include "Utils.h"
#include "Face recognition/FaceRecognition.h"

Utils::Utils() {}

Utils::~Utils() {}

std::string Utils::frameTitle;
std::string Utils::captureSource;

/// <summary>
/// This is just a simple logging function which can either log to the console and text file or just the console.
/// </summary>
/// <param name="message">The message we want to print to the console.</param>
/// <param name="loggingLevel">This is the level of logging we want to use. 1 being to just console, 2 being to console & file.</param>
void Utils::log(std::string message, uint_fast8_t loggingLevel)
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t in_time_t = std::chrono::system_clock::to_time_t(now);

    switch (loggingLevel)
    {
    case 1:
        std::cout << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X") << " " << message << std::endl;
        break;
    case 2:
        std::cout << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X") << " " << message << std::endl;
        //also log to text file.
        break;
    }
}

/// <summary>
/// This function displays the frame.
/// </summary>
/// <param name="frame">The frame we want to show.</param>
/// <returns>Return an integer to determine whether error occurs.</returns>
void Utils::displayImage(cv::Mat frame)
{
    Utils::log(frameTitle, 1);
    cv::imshow(frameTitle, frame);
    //cv::namedWindow(frameTitle/*, cv::WINDOW_AUTOSIZE*/);
}
 
/// <summary>
/// This opens the video feed we want and checks whether it opens.
/// </summary>
/// <returns>An integer which shows whether an error has occurred.</returns>
uint Utils::openAndReadCapture()
{
    cv::VideoCapture capture(captureSource);

    if (!capture.isOpened())
    {
        std::cerr << "Cannot open the video cam\n";
        return -1;
    }

    /*double dWidth = videoCapture.get(cv::CAP_PROP_FRAME_WIDTH);
    double dHeight = videoCapture.get(cv::CAP_PROP_FRAME_HEIGHT);
    std::cout << "Frame size : " << dWidth << " x " << dHeight << std::endl;*/
    FaceRecognition* facialRecognition = new FaceRecognition();

    while (true)
    {

        cv::Mat frame;
        bool videoCaptureReadSuccess = capture.read(frame);

        if (!videoCaptureReadSuccess)
        {
            std::cout << "Cannot read a frame from video stream" << std::endl;
            break;
        }


       /* DrawFPSCount(videoCapture, frame);*/
        facialRecognition->DrawFaceBox(capture, frame);
        
 
       Utils::displayImage(frame);

        if (cv::waitKey(30) == 27)
        {
            std::cout << "esc key is pressed by user" << std::endl;
            return 1;
        }
    }

    delete facialRecognition;
    capture.release();
    return 0;
}

/// <summary>
/// This draws the frame rate counter at the top left of the screen.
/// </summary>
/// <param name="videoCapture">This is the video capture feed.</param>
/// <param name="frame">This is the frame that we want to write too.</param>
void Utils::DrawFPSCount(cv::VideoCapture& videoCapture, cv::Mat& frame)
{
    cv::putText(frame, Utils::getFPS(videoCapture), cv::Point(0, 25), cv::FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255, 255), 2);
}

std::string Utils::getFPS(cv::VideoCapture videoCapture)
{
    int getfps = videoCapture.get(cv::CAP_PROP_FPS);
    std::string fps = std::to_string(getfps) + "fps";
    return fps;
}