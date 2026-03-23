cmake_minimum_required(VERSION 3.10)

project(SB3DGS)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/third_party)

add_executable (${PROJECT_NAME} ${SOURCES})

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
#find_package(glad CONFIG REQUIRED)

add_library(glad STATIC ${CMAKE_CURRENT_SOURCE_DIR}/third_party/src/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/third_party/include)


target_link_libraries(${PROJECT_NAME}
OpenGL::GL 
glfw
glm::glm
glad)
