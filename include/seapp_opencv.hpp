#ifndef SEAPP_HPP
#define SEAPP_HPP

#ifdef WITH_OPENCV
    #include <opencv2/opencv.hpp>
#endif

#include <string>
#include <iostream>

void ImageFn(const std::string& image);
void GrayScaleImageFn(const std::string& image);
void GaussianBlurImageFn(const std::string& imagePath);
void ResizeImageFn(const std::string& imagePath, const std::vector<int>& imageSize);
void VideoFn(std::string video);
void WebCamFn();

#endif // SEAPP_HPP
