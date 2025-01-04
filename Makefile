CC = g++
CFLAGS = -std=c++11 -Wall
HEADERS = JogosTab.hpp Reversi.hpp Ligue4.hpp JogoVelha.hpp
SOURCES = main.cpp Reversi.cpp Ligue4.cpp JogoVelha.cpp
OBJECTS = $(SOURCES:.cpp = .o)
main: $(OBJECTS)
$(CC) $(CFLAGS) -o main $(OBJECTS) 
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm- f $(OBJECTS) main

run: main
	./main
.PHONY: all clean run
all: run