cmake_minimum_required(VERSION 3.4)

if (CMAKE_BUILD_TYPE MATCHES Release)
	set(TARGET_SUBDIR Release)
else()
	set(TARGET_SUBDIR Debug)
endif()

if(MSVC)
	SET(CMAKE_CXX_FLAGS "/EHsc")
endif(MSVC)

set(BASEOUTDIR ${CMAKE_CURRENT_LIST_DIR}/../../../../build_results/${CMAKE_CXX_COMPILER_ID}/${TARGET_SUBDIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BASEOUTDIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BASEOUTDIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BASEOUTDIR}/bin)

project(boost)

# BOOST FILESYSTEM
file(GLOB_RECURSE FS_SOURCES
	../libs/filesystem/src/*.cpp
)
add_library(boost_filesystem STATIC ${FS_SOURCES})
target_include_directories(boost_filesystem PUBLIC .. ../libs/filesystem/src)

# BOOST PROGRAM OPTIONS

file(GLOB_RECURSE PO_SOURCES
	../libs/program_options/src/*.cpp
)
add_library(boost_program_options STATIC ${PO_SOURCES})
target_include_directories(boost_program_options PUBLIC .. ../libs/program_options/src)

# BOOST PYTHON
#[[
file(GLOB_RECURSE PY_SOURCES
	../libs/python/src/*.cpp
	../libs/python/src/*.hpp
)
add_library(boost_python STATIC ${PY_SOURCES})
target_include_directories(boost_python PUBLIC .. ../libs/python/src)
]]

# BOOST SYSTEM

file(GLOB_RECURSE SYS_SOURCES
	../libs/system/src/*.cpp
)
add_library(boost_system STATIC ${SYS_SOURCES})
target_include_directories(boost_system PUBLIC .. ../libs/system/src)
