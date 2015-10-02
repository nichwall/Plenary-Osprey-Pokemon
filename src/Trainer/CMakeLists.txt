cmake_minimum_required (VERSION 2.6)
project (PokemonEngine CXX)

include_directories ("${PROJECT_SOURCE_DIR}/../")

SET (SRCS
	Badges.cpp
	Player.cpp
)

SET (HDRS
	Badges.h
	Player.h
)

add_library (Trainer ${SRCS})
