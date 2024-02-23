cmake_minimum_required(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
project(app VERSION 24.1.0 DESCRIPTION "Elder Engine Test Environment")

add_executable(${PROJECT_NAME}
	src/entry.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED TRUE
	VERSION ${PROJECT_VERSION}
)
target_include_directories(${PROJECT_NAME} PRIVATE
	../engine/include/
	../engine/ext/spdlog/include/
	include/
	include/headers/
)

IF(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE EQUAL "Debug")
	target_compile_options(${PROJECT_NAME} PRIVATE -Wall -g -flto=auto)
ELSE()
	target_compile_options(${PROJECT_NAME} PRIVATE -Wall -O2 -flto=auto)
ENDIF()

find_library(ELDER Elder PATHS "../engine/build/Linux-6.7.5-arch1-1/Debug/" NAMES elder Elder)
target_link_libraries(${PROJECT_NAME} PRIVATE ${ELDER})
