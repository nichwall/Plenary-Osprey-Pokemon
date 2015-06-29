CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lGL -lGLU -lglut -lsfml-system -lsfml-window -lsfml-graphics
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=pokemon

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
