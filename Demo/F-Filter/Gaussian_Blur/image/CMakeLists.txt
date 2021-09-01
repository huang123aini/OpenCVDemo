#设置版本号

cmake_minimum_required(VERSION 3.5)


project(GaussianBlur)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 11)

add_executable(GaussianBlur GaussianBlur.cpp)

target_link_libraries(GaussianBlur ${OpenCV_LIBS})

