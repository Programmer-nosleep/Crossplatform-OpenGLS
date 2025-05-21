cmake_minimum_required(VERSION 3.15)

file(GLOB StaticLibrariesRenderer 
	./*.cpp
	./*.h
)
#
# add_library(${PROJECT_NAME} STATIC ${StaticLibrariesRenderer})
# target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
