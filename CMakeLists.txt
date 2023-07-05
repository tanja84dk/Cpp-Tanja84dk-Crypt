# CMakeLists.txt for Crypt Collection
#
# © 2021-2023 by Tanja84DK

if (TARGET tanja84dk_crypt)
	return()
endif()

cmake_minimum_required(VERSION 3.8)

project(tanja84dk_crypt LANGUAGES CXX VERSION 0.1.0)

set(BUILD_SHARED_LIBS OFF)

set(tanja84dk_crypt_BUILD_TESTING OFF)

set(tanja84dk_crypt_HEADERS
  include/Tanja84dk/crypt/base64/base64.h
  include/Tanja84dk/crypt/binary/binary.h
  include/Tanja84dk/crypt/ceasar/ceasar.h
)

set(tanja84dk_crypt_SOURCES
  src/base64/base64.cpp
  src/binary/binary.cpp
  src/ceasar/ceasar.cpp
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(cmake/CPM.cmake)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
	find_package(tanja84dk_tools REQUIRED)
	find_package(cpp-base64 REQUIRED)
else()
	include(CMakeFindDependencyMacro)
	find_dependency(tanja84dk_tools)
	find_dependency(cpp-base64)
endif()

add_library(tanja84dk_crypt ${tanja84dk_crypt_SOURCES} ${tanja84dk_crypt_HEADERS})

add_library(Tanja84dk::crypt ALIAS tanja84dk_crypt)

target_link_libraries(tanja84dk_crypt
	PRIVATE
		Tanja84dk::tools
		cpp-base64
)

target_include_directories(tanja84dk_crypt
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>

	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(tanja84dk_crypt
	PRIVATE
		cxx_std_20
)

set_target_properties(tanja84dk_crypt
	PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
		VERSION ${tanja84dk_crypt_VERSION}
		SOVERSION ${tanja84dk_crypt_VERSION_MAJOR}
)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
	set_target_properties(tanja84dk_crypt PROPERTIES LINK_FLAGS_RELEASE -s)
endif()

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR OR tanja84dk_crypt_BUILD_TESTING STREQUAL ON)
	add_subdirectory(test)
endif()