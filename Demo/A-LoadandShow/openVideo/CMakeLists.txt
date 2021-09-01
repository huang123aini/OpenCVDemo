#设置版本号

cmake_minimum_required(VERSION 3.5)


project(OpenVideo)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 11)

add_executable(OpenVideo openVideo.cpp)

target_link_libraries(OpenVideo ${OpenCV_LIBS})


