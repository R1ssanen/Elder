cmake_minimum_required(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
project(ElderTENV VERSION 23.1.0 DESCRIPTION "Elder Engine Test Environment")

add_executable(${PROJECT_NAME}
	entry.cpp
)
set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED TRUE
	VERSION ${PROJECT_VERSION}
)
target_include_directories(${PROJECT_NAME} PRIVATE
	include/
	include/external/
	include/headers/
)

set(DEFAULT_BUILD_TYPE "Debug")

IF(CMAKE_BUILD_TYPE EQUAL "Debug")
	target_compile_options(${PROJECT_NAME} PRIVATE -Wall -g -flto=auto -pg -lpthread)
ELSE()
	target_compile_options(${PROJECT_NAME} PRIVATE -Wall -O2 -flto=auto -pg -lpthread)
ENDIF()

find_library(ELDER Elder PATHS "include/external/elder/libElder.a")
target_link_libraries(${PROJECT_NAME} PUBLIC ${elder})
