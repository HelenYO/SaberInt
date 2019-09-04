cmake_minimum_required(VERSION 3.13)
project(MinBoundingBox)
cmake_minimum_required(VERSION 3.8)

#set(CMAKE_CXX_STANDARD 17)

#add_executable(MinBoundingBox main.cpp Graphics.cpp Graphics.h MainScene.cpp MainScene.h MBB/MBBox.cpp MBB/MBBox.h)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations -Qunused-arguments")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -framework GLUT -framework OpenGL")

set(SOURCE_FILES main.cpp MBB/MBBox.cpp MBB/MBBox.h)
#set(SOURCE_FILES main.cpp Graphics.cpp Graphics.h hulllib.cpp hulllib.h)

add_executable(MinBoundingBox ${SOURCE_FILES})