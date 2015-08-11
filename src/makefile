CC=g++
CFLAGS=-std=c++11-c -Wall
LDFLAGS=-lGL -lGLU -lsfml-system -lsfml-window -lsfml-graphics -fPIC
SOURCES=$(wildcard *.cpp */*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=pokemon_engine

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
