cmake_minimum_required(VERSION 3.0.0)
project(VideoStore VERSION 1.0.0)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(VideoStore ${SOURCES})