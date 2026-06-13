#include "seapp_version.h"
#include <argparse/argparse.hpp>
#include <Eigen/Dense>

#ifdef WITH_OPENCV
    #include "seapp_opencv.hpp"
#endif

auto main(int argc, char** argv) -> int {
    std::string pv = R"(seapp )"  + std::to_string(seapp_VERSION_MAJOR) + "." + std::to_string(seapp_VERSION_MINOR) + "." + std::to_string(seapp_VERSION_PATCH);

    argparse::ArgumentParser program("seapp", pv);
    program.add_description("A free application for Computer Vision and Numerical Computation");
    program.add_epilog("Written by David Tamaratare Oghenebrume");

#ifdef WITH_OPENCV
    auto compv = argparse::ArgumentParser("compvn");
    auto& compv_group = compv.add_mutually_exclusive_group(false);

    compv.add_description("For computer vision related tasks");
    compv.add_epilog("Written by David Tamaratare Oghenebrume");

    compv_group.add_argument("-vd", "--video")
        .help("Displays a video")
        .nargs(1);

    compv_group.add_argument("-wc", "--webcam")
        .help("Displays live webcam")
        .flag();

    auto compvn_image = argparse::ArgumentParser("image");
    compvn_image.add_description("Image-only Computer Vision");
    compvn_image.add_epilog("Written by David Tamaratare Oghenebrume");

    auto& compvn_image_group = compvn_image.add_mutually_exclusive_group(true);

    compvn_image_group.add_argument("-f", "--file")
        .help("Displays an image")
        .nargs(1);

    compvn_image_group.add_argument("-gs", "--grayscale")
        .help("Displays a grayscale image")
        .nargs(1);

    compvn_image_group.add_argument("-gb", "--gaussian-blur")
        .help("Displays a gaussian blur image")
        .nargs(1);

    compv.add_subparser(compvn_image);

#endif

    auto num = argparse::ArgumentParser("num");
    num.add_description("For numerical computation and linear algebra");
    num.add_epilog("Written by David Tamaratare Oghenebrume");

    num.add_argument("-im", "--imatrix")
        .help("For matrices (\'A\' * x = B")
        .nargs(9)
        .scan<'g', float>();

    num.add_argument("-b", "--b-vectors")
        .help("For the vectors of matrices (A * x = \'B\'")
        .nargs(3)
        .scan<'g', float>();

#ifdef WITH_OPENCV
    program.add_subparser(compv);
#endif
    program.add_subparser(num);

    try{
        program.parse_args(argc, argv);
    }
    catch(const std::exception& error){
        std::cerr << error.what() << "\n" << program << std::endl;
        return 1;
    }

    if(program.is_subcommand_used("num") && num.is_used("-im")){
        const auto Mat = num.get<std::vector<float>>("-im");
        std::vector<double> MatD(Mat.begin(), Mat.end());

        Eigen::Matrix3d A, A_inv, A_adj, A_trans;
        A = Eigen::Map<Eigen::Matrix<double, 3, 3, Eigen::RowMajor>>(MatD.data());

        A_inv = A.inverse();
        A_adj = A.adjoint();
        A_trans = A.transpose();

        std::cout << "Matrix is: \n" << A << std::endl;

        if(A.determinant() == 0){
            std::cout << "\nMatrix does not have an inverse" << std::endl;
        }else{
            std::cout << "\nInverse of matrix is: \n" << A_inv << std::endl;
            std::cout << "\nA * A^-1 = \n" << A * A_inv << std::endl;
        }

        std::cout << "\nAdjoint of matrix is: \n" << A_adj << std::endl;
        std::cout << "\nTranspose of matrix is: \n" << A_trans << std::endl;

        std::cout << "SON\n";

        if(num.is_used("--b-vectors")){
            const auto tmp = num.get<std::vector<float>>("--b-vectors");
            std::vector<double> tmpD(tmp.begin(), tmp.end());

            Eigen::Vector3d B(tmpD.data()), x;
            x = A_inv * B;

            std::cout << "\nThe x, y, z values are: \n" << x << "\nrespectively" << std::endl;
            std::cout << "\nA * x = \n" << A * x << std::endl;
        }
    }

#ifdef WITH_OPENCV
    if(program.is_subcommand_used("compvn")){
        if(compv.is_subcommand_used("image")){
            if(compvn_image.is_used("--file")) ImageFn(compvn_image.get<std::string>("--file"));
            else if(compvn_image.is_used("--grayscale")) GrayScaleImageFn(compvn_image.get<std::string>("--grayscale"));
            else if(compvn_image.is_used("--gaussian-blur")) GaussianBlurImageFn(compvn_image.get<std::string>("--gaussian-blur"));
        }

        else if(compv.is_used("--video")) VideoFn(compv.get<std::string>("--video"));
        else if(compv.is_used("--webcam")) WebCamFn();
    }
#endif

    return 0;
}
