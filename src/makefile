CC=g++
CFLAGS=-std=c++11-c -Wall
LDFLAGS=-lGL -lGLU -lglut -lsfml-system -lsfml-window -lsfml-graphics -fPIC
SOURCES=$(wildcard *.cpp */*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=pokemon

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
