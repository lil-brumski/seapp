cmake_minimum_required(VERSION 4.3)

project(seapp
        VERSION 2026.5.27
        LANGUAGES CXX
        DESCRIPTION "For Learning!"
)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui)
find_package(Eigen3 REQUIRED MO_MODULE)
add_subdirectory(third_party/argparse)

set(SAN_FLAGS "-fsanitize=address,undefined")

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/seapp.cpp
)

configure_file(seapp_version.h.in seapp_version.h)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror -Wextra -Wshadow -Wconversion -Wpedantic)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_link_options(${PROJECT_NAME} PRIVATE ${SAN_FLAGS})
endif()

target_include_directories(${PROJECT_NAME} PRIVATE include ${PROJECT_BINARY_DIR})

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        argparse::argparse
        Eigen3::Eigen
        opencv_core
        opencv_imgproc
        opencv_highgui
)

