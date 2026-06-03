#include "seapp_opencv.hpp"

void ImageFn([[maybe_unused]] const std::string& imagePath){
#ifdef WITH_OPENCV
    cv::Mat image = cv::imread(imagePath);
    cv::imshow("Image bro", image);

    cv::waitKey(0);
    cv::destroyAllWindows();
#else
    std::cout << "You haven't build WITH_OPENCV and you want to use this function?" << std::endl;
#endif

}

void VideoFn([[maybe_unused]] std::string video){
#ifdef WITH_OPENCV
    cv::VideoCapture vid(video);
    cv::Mat image;

    while(true){
        vid.read(image);

        cv::imshow("Video bro", image);
        cv::waitKey(20);
    }

    cv::destroyAllWindows();
#else
    std::cout << "You haven't build WITH_OPENCV and you want to use this function?" << std::endl;
#endif
}

void WebCamFn(){
#ifdef WITH_OPENCV
    cv::VideoCapture vid(0);
    cv::Mat image;

    while(true){
        vid.read(image);

        cv::imshow("Video bro", image);
        cv::waitKey(1);
    }

    cv::destroyAllWindows();
#else
    std::cout << "You haven't build WITH_OPENCV and you want to use this function?" << std::endl;
#endif
}