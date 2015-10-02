cmake_minimum_required (VERSION 3.1.0 FATAL_ERROR)
project (PokemonEngine CXX)

#SET (CMAKE_CXX_FLAGS "-std=c++11")

include_directories ("${PROJECT_SOURCE_DIR}/../")

SET (FOLDERS
	Type/
	Move/
)
SET (SRCS
	Pokemon.cpp
)

SET (HDRS
	Pokemon.h
)
ADD_DEFINITIONS(
	-std=c++11
)

#target_compile_features (PokemonEngine PRIVATE cxx_range_for)
add_library (Pokemon ${SRCS})

foreach (folder ${FOLDERS})
	add_subdirectory (${folder})
endforeach()
