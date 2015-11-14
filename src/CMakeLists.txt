cmake_minimum_required (VERSION 3.1.0 FATAL_ERROR)
project (PokemonEngine CXX)

set (FOLDERS
	Battles
    Items
	Language
	Pokemon
	Trainer
    Ribbon
)

# All cxx to include in root dir
set (SRCS
	main.cpp
)

# All headers to include in root dir
set (HDRS
	Defines.h
)

# More includes
include_directories (".")

# Check that we're not using MSCV
if (NOT MSCV)
	foreach(folder ${FOLDERS})
		add_subdirectory(${folder})
	endforeach()
	
#	list(APPEND SOURCE "${SRCS}")
#	list(APPEND SOURCE "${HDRS}")
endif()

# Generate list of all source files
set(ALLFILES "${SRCS}" "${HDRS}")
foreach(folder ${FOLDERS})
	get_directory_property(FOLDER_SRCS DIRECTORY ${folder} DEFINITION SRCS)
	foreach (src ${FOLDER_SRCS})
		list(APPEND ALLFILES "${folder}/${src}")
	endforeach(src)
	get_directory_property(FOLDER_HDRS DIRECTORY ${folder} DEFINITION HDRS)
	foreach (hdr ${FOLDER_HDRS})
		list(APPEND ALLFILES "${folder}/${hdr}")
	endforeach(hdr)
endforeach(folder)
foreach(arg ${ALLFILES})
	set(ALLFILESLINES "${ALLFILESLINES}${ARG}\n")
endforeach()
FILE(WRITE "AllFiles.lst" "${ALLFILESLINES}")
