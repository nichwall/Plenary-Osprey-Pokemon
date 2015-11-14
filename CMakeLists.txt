cmake_minimum_required (VERSION 3.1.0 FATAL_ERROR)
project (PlenaryOspreyPokemonEngine CXX)

# Version numbers
set (PlenaryOspreyPokemonEngine_VERSION_MAJOR 0)
set (PlenaryOspreyPokemonEngine_VERSION_MINOR 1)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Adding extra libraries for displays and things
set (EXTRA_LIBS ${EXTRA_LIBS} 
		GL
		GLU
		sfml-system
		sfml-window
		sfml-graphics

        Item
		Language
		Move
#		Player
		Pokemon
        Ribbon
		Trainer
		Type
)

set (FOLDERS 
	src/
    src/Items/
	src/Pokemon/
	src/Trainer/
	src/Battles/
	src/Language/
    src/Ribbon/
)

add_subdirectory(src)
#include_directories ("${INCLUDE_DIR}")

add_executable (PlenaryOspreyPokemonEngine
		src/main.cpp
)
target_link_libraries (PlenaryOspreyPokemonEngine ${EXTRA_LIBS})

# Make sure that we are compiling with C++11
#target_compile_features(PlenaryOspreyPokemonEngine PRIVATE cxx_range_for)
