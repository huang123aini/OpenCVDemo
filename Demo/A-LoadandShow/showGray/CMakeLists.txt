#设置版本号

cmake_minimum_required(VERSION 3.5)


project(ShowGray)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 11)

add_executable(ShowGray showGray.cpp)

target_link_libraries(ShowGray ${OpenCV_LIBS})


