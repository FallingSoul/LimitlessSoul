cmake_minimum_required(VERSION 3.0.0)
project(LimitlessSoul VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third-party/glad)

file(GLOB_RECURSE SOURCE_LIST src/*.cpp include/*.h)
foreach(file IN LISTS SOURCE_LIST)
    message("${PROJECT_NAME}: ${file}")
endforeach()

add_executable(${PROJECT_NAME} ${SOURCE_LIST})
message("Project: ${PROJECT_NAME}")
target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    include
    third-party/glad/include
    third-party/glfw/include
    )
target_link_directories(
    ${PROJECT_NAME}
    PUBLIC
    third-party/glfw/lib
)
target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    glfw3
    opengl32
)