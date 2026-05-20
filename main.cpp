#include <opencv2/opencv.hpp>

auto main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) -> int {
    cv::Mat image = cv::imread(static_cast<std::string>(argv[1]));
    cv::imshow("Image bro", image);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

