cmake_minimum_required (VERSION 3.1.0)
project (PokemonEngine CXX)

SET (CMAKE_CXX_FLAGS "-std=c++0x")

include_directories ("${PROJECT_SOURCE_DIR}/../")

SET (SRCS
	Type.cpp
	TypeEfficiency.cpp
)

SET (HDRS
	Type.h
	TypeEfficiency.cpp
)

add_library (Type ${SRCS})
