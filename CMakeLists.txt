cmake_minimum_required(VERSION 3.29)

project(
    roguelike_tutorial 
    LANGUAGES C CXX
)

file(GLOB_RECURSE SOURCES_FILE
	${PROJECT_SOURCE_DIR}/src/*.cpp
	)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(include/vendored/libtcod EXCLUDE_FROM_ALL)
#add_subdirectory(include/vendored/SDL EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME} ${SOURCES_FILE})

# Ensure the C++20 standard is available.
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

include_directories(include)
link_directories(include)

target_link_libraries(${PROJECT_NAME} 
	PRIVATE  
	#SDL3::SDL3
	libtcod::libtcod
)