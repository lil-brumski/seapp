#include <opencv2/opencv.hpp>
#include <argparse/argparse.hpp>
#include "seapp_version.h"

void ImageFn(const std::string& image);
void VideoFn(std::string video);
void WebCamFn();

auto main(int argc, char** argv) -> int {
    std::string pv = R"(seapp )"  + std::to_string(seapp_VERSION_MAJOR) + "." + std::to_string(seapp_VERSION_MINOR) + "." + std::to_string(seapp_VERSION_PATCH)
            + "\n\n" + R"(Written by David Tamaratare Oghenebrume)";

    argparse::ArgumentParser program("seapp", pv);

    program.add_argument("-i", "--image")
        .help("Displays an image")
        .nargs(1)
        ;//.required();

    program.add_argument("-vd", "--video")
        .help("Displays a video")
        .nargs(1)
        ;//.required();

    try{
        program.parse_args(argc, argv);
    }
    catch(const std::exception& error){
        std::cerr << error.what() << "\n" << program << std::endl;
        return 1;
    }

    if(program.is_used("--image")) ImageFn(program.get<std::string>("--image"));
    if(program.is_used("--video")) VideoFn(program.get<std::string>("--video"));

    WebCamFn();

    return 0;
}

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

        if(image.empty()){
            std::cerr << "Empty video" << std::endl;
            return;
        }

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

        if(image.empty()){
            std::cerr << "Empty video" << std::endl;
            return;
        }

        cv::imshow("Video bro", image);
        cv::waitKey(20);
    }

    cv::destroyAllWindows();
}
