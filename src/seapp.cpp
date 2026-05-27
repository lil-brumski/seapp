#include "seapp.hpp"

void ImageFn(const std::string& imagePath){

    cv::Mat image = cv::imread(imagePath);
    cv::imshow("Image bro", image);

    cv::waitKey(0);
    cv::destroyAllWindows();

}

void VideoFn(std::string video){

    cv::VideoCapture vid(video);
    cv::Mat image;

    while(true){
        vid.read(image);

        cv::imshow("Video bro", image);
        cv::waitKey(20);
    }

    cv::destroyAllWindows();
}

void WebCamFn(){

    cv::VideoCapture vid(0);
    cv::Mat image;

    while(true){
        vid.read(image);

        cv::imshow("Video bro", image);
        cv::waitKey(1);
    }

    cv::destroyAllWindows();
}