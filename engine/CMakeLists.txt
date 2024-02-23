cmake_minimum_required(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
project(Elder VERSION 24.1.0 DESCRIPTION "Elder Engine Corelib")

add_library(${PROJECT_NAME} SHARED
	src/core/log.cpp
	src/core/application.cpp
	src/core/uuid.cpp
)

target_precompile_headers(${PROJECT_NAME} PUBLIC "include/elder/eepch.hpp")
target_include_directories(${PROJECT_NAME} PRIVATE include/)

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED TRUE
	CXX_VISIBILITY_PRESET hidden
	VERSION ${PROJECT_VERSION}
	PUBLIC_HEADER "include/elder/elder.hpp"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SYSTEM}/${CMAKE_BUILD_TYPE}/"
)

IF(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE EQUAL Debug)
	target_compile_options(${PROJECT_NAME} PRIVATE -Wall -g -flto=auto -fPIC -Wl,-E)
ELSE()
	target_compile_options(${PROJECT_NAME} PRIVATE -Wall -O2 -flto=auto -fPIC)
ENDIF()

add_subdirectory(ext/spdlog/)
target_link_libraries(${PROJECT_NAME} spdlog)
