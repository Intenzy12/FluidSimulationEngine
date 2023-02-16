cmake_minimum_required(VERSION 3.1.0)
project(FluidSimulations) 

macro(GroupTree sources)
	file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${sources}/ ${PROJECT_SOURCE_DIR}/${sources}/*)
	foreach(child ${children})
		if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${sources}/${child})
			GroupTree(${sources}/${child})
		else()
			string(REPLACE "/" "\\" gname ${sources})
			source_group(${gname} FILES ${PROJECT_SOURCE_DIR}/${sources}/${child})
		endif()
	endforeach()
endmacro()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${PROJECT_SOURCE_DIR}/src/
	${PROJECT_SOURCE_DIR}/vendors/glfw/include/
	${PROJECT_SOURCE_DIR}/vendors/glad/include/
	${PROJECT_SOURCE_DIR}/vendors/imgui/
	${PROJECT_SOURCE_DIR}/vendors/glm/)

add_subdirectory(${PROJECT_SOURCE_DIR}/vendors)

file(GLOB_RECURSE PROJECT_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE PROJECT_HEADERS ${PROJECT_SOURCE_DIR}/src/*.h)

GroupTree(src)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})

target_link_libraries(${PROJECT_NAME} glfw glad imgui)
