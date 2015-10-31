cmake_minimum_required (VERSION 2.6)
project (PokemonEngine CXX)

include_directories ("${PROJECT_SOURCE_DIR}/../")

SET (SRCS
    Ribbon.cpp
)

SET (HDRS
    Ribbon.h
)
ADD_DEFINITIONS(
    -std=c++11
)

add_library (Ribbon ${SRCS})
