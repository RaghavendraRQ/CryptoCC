cmake_minimum_required(VERSION 3.30)
project(CryptoCPP)

set(CMAKE_CXX_STANDARD 20)


include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(CryptoCPP main.cpp
        include/classic/caeser.h
        src/classic/caeser.cc)
