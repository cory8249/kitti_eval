cmake_minimum_required(VERSION 3.7)
project(eval_ap)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    evaluate_object.cpp
        )

add_executable(eval_ap ${SOURCE_FILES})