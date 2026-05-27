#ifndef SEAPP_HPP
#define SEAPP_HPP

#include <opencv2/opencv.hpp>
#include <argparse/argparse.hpp>
#include <Eigen/Dense>

void ImageFn(const std::string& image);
void VideoFn(std::string video);
void WebCamFn();

#endif // SEAPP_HPP
