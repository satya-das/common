if (CMAKE_BUILD_TYPE MATCHES Release)
	set(TARGET_SUBDIR Release)
else()
	set(TARGET_SUBDIR Debug)
endif()

if(MSVC)
	SET(CMAKE_CXX_FLAGS "/EHsc")
else()
	SET(CMAKE_CXX_FLAGS "-g -m32 -std=c++17 -fvisibility=hidden -fvisibility-inlines-hidden")
	SET(CMAKE_C_FLAGS "-g -m32 -fvisibility=hidden -fvisibility-inlines-hidden")
endif(MSVC)

# Define DLLEXPORT and DLLIMPORT
if(WIN32 OR CYGWIN )
	if(${CMAKE_CXX_COMPILER_ID} MATCHES "GNU")
		set(DLLEXPORT "__attribute__((dllexport))")
		set(DLLIMPORT "")
	else()
		set(DLLEXPORT "__declspec(dllexport)")
		set(DLLIMPORT "__declspec(dllimport)")
	endif()
else()
	set(DLLEXPORT "__attribute__ ((visibility (\"default\"))")
	set(DLLIMPORT "")
endif()

set(ROOT_DIR ${CMAKE_CURRENT_LIST_DIR}/../..)
set(BASEOUTDIR ${ROOT_DIR}/build_results/${CMAKE_CXX_COMPILER_ID}/${TARGET_SUBDIR})
set(BINDIR ${BASEOUTDIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BASEOUTDIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BASEOUTDIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BASEOUTDIR}/bin)
set(CMAKE_OBJFILE_OUTPUT_DIRECTORY ${BASEOUTDIR}/obj)
