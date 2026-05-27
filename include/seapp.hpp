#ifndef SEAPP_HPP
#define SEAPP_HPP

#include <opencv2/opencv.hpp>
#include <argparse/argparse.hpp>
#include <Eigen/Core>

void ImageFn(const std::string& image);
void VideoFn(std::string video);
void WebCamFn();

#endif // SEAPP_HPP
