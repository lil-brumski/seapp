#include "seapp_version.h"
#include "seapp.hpp"

auto main(int argc, char** argv) -> int {
    std::string pv = R"(seapp )"  + std::to_string(seapp_VERSION_MAJOR) + "." + std::to_string(seapp_VERSION_MINOR) + "." + std::to_string(seapp_VERSION_PATCH)
            + "\n\n" + R"(Written by David Tamaratare Oghenebrume)";

    argparse::ArgumentParser program("seapp", pv);

    program.add_argument("-i", "--image")
        .help("Displays an image")
        .nargs(1);

    program.add_argument("-vd", "--video")
        .help("Displays a video")
        .nargs(1);

    program.add_argument("-wc", "--webcam")
        .help("Displays live webcam")
        .flag();

    program.add_argument("-im", "--imatrix")
        .help("For matrices (\'A\' * x = B")
        .nargs(9)
        .scan<'g', float>();

    program.add_argument("-b", "--b-vectors")
        .help("For the vectors of matrices (A * x = \'B\'")
        .nargs(3)
        .scan<'g', float>();

    try{
        program.parse_args(argc, argv);
    }
    catch(const std::exception& error){
        std::cerr << error.what() << "\n" << program << std::endl;
        return 1;
    }

    if(program.is_used("--imatrix")){
        std::vector<double> Mat(program.get<std::vector<float>>("-im").begin(), program.get<std::vector<float>>("-im").end());
        Eigen::Matrix3d A, A_inv, A_adj, A_trans;
        A = Eigen::Map<Eigen::Matrix<double, 3, 3, Eigen::RowMajor>>(Mat.data());

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

        if(program.is_used("-b")){
            Eigen::Vector3d B(std::vector<double>(program.get<std::vector<float>>("-b").begin(), program.get<std::vector<float>>("-b").end()).data()), x;
            x = A_inv * B;

            std::cout << "\nThe x, y, z values are: \n" << x << "\nrespectively" << std::endl;
            std::cout << "\nA * x = \n" << A * x << std::endl;
        }
    }

    if(program.is_used("--image")) ImageFn(program.get<std::string>("--image"));
    if(program.is_used("--video")) VideoFn(program.get<std::string>("--video"));
    if(program.is_used("--webcam")) WebCamFn();

    return 0;
}
