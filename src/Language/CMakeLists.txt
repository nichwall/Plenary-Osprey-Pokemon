cmake_minimum_required (VERSION 2.6)
project (PokemonEngine)

SET (CMAKE_CXX_FLAGS "-std=c++0x")

include_directories ("${PROJECT_SOURCE_DIR}/../")

SET (SRCS
	Language.cpp
)

SET (HDRS
	Language.h
)

add_library (Language ${SRCS})
