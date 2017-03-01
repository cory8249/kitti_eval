cmake_minimum_required(VERSION 3.6)
project(kitti_eval)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/evaluate_object.cpp
        src/kitti_tracking.cpp
        src/kitti_tracking.h
        src/typedef.h)

add_executable(kitti_eval ${SOURCE_FILES})