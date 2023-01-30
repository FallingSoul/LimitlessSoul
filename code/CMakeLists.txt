cmake_minimum_required(VERSION 3.0.0)

file(GLOB_RECURSE SOURCE_LIST src/*.cpp include/*.h)
message("Source:${SOURCE_LIST}")

add_executable(${PROJECT_NAME} ${SOURCE_LIST})