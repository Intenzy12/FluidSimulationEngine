cmake_minimum_required(VERSION 3.1.0)
project(libs)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
add_subdirectory(${PROJECT_SOURCE_DIR}/glfw/)

add_subdirectory(${PROJECT_SOURCE_DIR}/glm)

file(GLOB GLAD_SOURCES ${PROJECT_SOURCE_DIR}/glad/src/glad.c)
file(GLOB GLAD_HEADERS ${PROJECT_SOURCE_DIR}/glad/include/*.h)
add_library(glad ${GLAD_SOURCES} ${GLAD_HEADERS})
target_include_directories(glad PRIVATE ${PROJECT_SOURCE_DIR}/glad/include/)

file(GLOB IMGUI_SOURCES ${PROJECT_SOURCE_DIR}/imgui/*.cpp ${PROJECT_SOURCE_DIR}/imgui/backends/imgui_impl_opengl3.cpp ${PROJECT_SOURCE_DIR}/imgui/backends/imgui_impl_glfw.cpp)
file(GLOB IMGUI_HEADERS ${PROJECT_SOURCE_DIR}/imgui/*.h)
add_library(imgui ${IMGUI_SOURCES} ${IMGUI_HEADERS})
target_include_directories(imgui PRIVATE ${PROJECT_SOURCE_DIR}/imgui/)
