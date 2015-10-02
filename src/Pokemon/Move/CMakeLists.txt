cmake_minimum_required (VERSION 3.1.0)
project (PokemonEngine CXX)
#add_library (Move Move.cpp)

SET (CMAKE_CXX_FLAGS "-std=c++0x")

include_directories ("${PROJECT_SOURCE_DIR}/../")

SET (SRCS
	Move.cpp
	Move_Metadata.cpp
	Move_Damage_Class.cpp
)

SET (HDRS
	Move.h
	Move_Metadata.h
	Move_Damage_Class.h
)

add_library (Move ${SRCS})
