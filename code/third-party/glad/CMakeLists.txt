cmake_minimum_required(VERSION 3.0.0)

project(glad VERSION 4.6)

file(GLOB_RECURSE SOURCE_LIST src/*.c include/*.h)
foreach(file IN LISTS SOURCE_LIST)
    message("${PROJECT_NAME}: ${file}")
endforeach()

add_library(${PROJECT_NAME} STATIC ${SOURCE_LIST})
target_include_directories(${PROJECT_NAME} PUBLIC include)