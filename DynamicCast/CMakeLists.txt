cmake_minimum_required(VERSION 3.13)
project(DynamicCast)

set(CMAKE_CXX_STANDARD 17)

add_executable(DynamicCast main.cpp dynamic_cast.h cast_testing.cpp dynamic_cast_bit_mask.h)

add_executable(DinamicCastTest cast_testing.cpp dynamic_cast.h dynamic_cast_bit_mask.h
        gtest/gtest.h
        gtest/gtest-all.cc
        gtest/gtest_main.cc)