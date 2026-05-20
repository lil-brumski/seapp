cmake_minimum_required(VERSION 4.3)

project(seapp
        VERSION 2026.5.18
        LANGUAGES CXX
        DESCRIPTION "FOr Learning!"
)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui)

set(SAN_FLAGS "-fsanitize=address,undefined")

add_executable(${PROJECT_NAME}
        main.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror -Wextra -Wshadow -Wconversion -Wpedantic)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_link_options(${PROJECT_NAME} PRIVATE ${SAN_FLAGS})
endif()

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        opencv_core
        opencv_imgproc
        opencv_highgui
)

