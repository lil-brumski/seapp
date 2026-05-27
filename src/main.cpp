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
