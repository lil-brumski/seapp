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

void GrayScaleImageFn([[maybe_unused]] const std::string& imagePath){
#ifdef WITH_OPENCV
    cv::Mat image = cv::imread(imagePath);
    cv::Mat grayScaledImage;
    //cv::imshow("Image bro", image);

    cv::cvtColor(image, grayScaledImage, cv::COLOR_RGBA2GRAY);
    cv::imshow("Grayscale image", grayScaledImage);

    cv::waitKey(0);
    cv::destroyAllWindows();
#else
    std::cout << "You haven't build WITH_OPENCV and you want to use this function?" << std::endl;
#endif
}

void ResizeImageFn(const std::string& imagePath, const std::vector<int>& imageSize){
#ifdef WITH_OPENCV
    cv::Mat image = cv::imread(imagePath);
    cv::Mat newSize;

    std::cout << imageSize.size() << std::endl;

    cv::resize(image, newSize, cv::Size(imageSize[0], imageSize[1]));
    cv::imshow("New Image Size", newSize);

    cv::waitKey(0);
    cv::destroyAllWindows();
#else
    std::cout << "You haven't build WITH_OPENCV and you want to use this function?" << std::endl;
#endif
}

void GaussianBlurImageFn([[maybe_unused]] const std::string& imagePath){
#ifdef WITH_OPENCV
    cv::Mat image = cv::imread(imagePath);
    cv::Mat gaussianBlurImage, cannyImage, dilateImage, erodeImage;

    std::cout << "Image size: " << image.size() << std::endl;

    cv::GaussianBlur(image, gaussianBlurImage, cv::Size(7, 7), 5, 0);
    cv::imshow("Blurred image", gaussianBlurImage);

    cv::Canny(gaussianBlurImage, cannyImage, 25, 75);
    cv::imshow("Edge detector", cannyImage);

    cv::dilate(cannyImage, dilateImage, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));
    cv::imshow("Dilated image", dilateImage);

    cv::erode(dilateImage, erodeImage, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));
    cv::imshow("Eroded image", erodeImage);

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