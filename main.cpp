#include <opencv2/opencv.hpp>
#include <filesystem>

void ImageFn(const std::string& image);
void VideoFn(std::string video);
void WebCamFn();

auto main(int argc, char** argv) -> int {
    if(argc != 3) {
        std::cerr << "Enter one argument: image location" << std::endl;
        return 1;
    }

    std::cout << std::boolalpha << argv[2] << " exists: " << std::filesystem::exists(argv[2]) << std::endl;

    ImageFn(static_cast<std::string>(argv[1]));
    VideoFn(static_cast<std::string>(argv[2]));
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
