#cmake_minimum_required(VERSION 3.13)
project(ConvexHull)
#
#set(CMAKE_CXX_STANDARD 17)
#
#add_executable(ConvexHull main.cpp GrahamScan/Graham_scan.cpp GrahamScan/Graham_scan.h)


cmake_minimum_required(VERSION 3.8)
#project(GraphicsDemo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations -Qunused-arguments")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -framework GLUT -framework OpenGL")

set(SOURCE_FILES main.cpp Graphics.cpp Graphics.h GrahamScan/Graham_scan.cpp GrahamScan/Graham_scan.h)
add_executable(ConvexHull ${SOURCE_FILES})