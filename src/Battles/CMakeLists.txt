cmake_minimum_required (VERSION 2.6)
project (PokemonEngine CXX)

include_directories ("${PROJECT_SOURCE_DIR}/../")

SET (SRCS
	BattleHandler.cpp
)

SET (HDRS
	BattleHandler.h
)

add_library(Battles ${SRCS})

