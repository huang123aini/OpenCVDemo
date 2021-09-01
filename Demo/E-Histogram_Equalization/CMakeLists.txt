#设置版本号

cmake_minimum_required(VERSION 3.5)


project(histogramEqualization)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 11)

add_executable(histogramEqualization histogramEqualization.cpp)

target_link_libraries(histogramEqualization ${OpenCV_LIBS})

