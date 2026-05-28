cmake_minimum_required(VERSION 4.3)

project(seapp
        VERSION 2026.5.28
        LANGUAGES CXX
        DESCRIPTION "For Learning!"
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(WITH_OPENCV "Build with OpenCV support" OFF)
option(WITH_SYSTEM_EIGEN "Build with system-installed Eigen3" OFF)

configure_file(seapp_version.h.in seapp_version.h)

if(WITH_SYSTEM_EIGEN)
        find_package(Eigen3 REQUIRED NO_MODULE)
else()
        include(FetchContent)

        FetchContent_Declare(
                Eigen3
                GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
                GIT_TAG master
                GIT_SHALLOW    TRUE
                EXCLUDE_FROM_ALL
        )

        set(EIGEN_BUILD_DOC OFF CACHE BOOL "" FORCE)
        set(EIGEN_BUILD_TESTING OFF CACHE BOOL "" FORCE)
        set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
        set(EIGEN_BUILD_PKGCONFIG OFF CACHE BOOL "" FORCE)

        FetchContent_MakeAvailable(Eigen3)
endif(WITH_SYSTEM_EIGEN)

add_subdirectory(third_party/argparse)

set(SAN_FLAGS "-fsanitize=address,undefined")

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/seapp.cpp
)

if(WITH_OPENCV)
        find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui)
        target_compile_definitions(${PROJECT_NAME} PUBLIC "WITH_OPENCV")
        target_link_libraries(${PROJECT_NAME}
                PRIVATE
                opencv_core
                opencv_imgproc
                opencv_highgui
        )
        message(NOTICE "Building with OpenCV support right now...")
endif(WITH_OPENCV)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror -Wextra -Wshadow -Wconversion -Wpedantic)
        target_link_options(${PROJECT_NAME} PRIVATE ${SAN_FLAGS})
endif()

target_include_directories(${PROJECT_NAME} PRIVATE include ${PROJECT_BINARY_DIR})

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        argparse::argparse
        Eigen3::Eigen
)

