CC=g++
CFLAGS=-std=c++11 -Wall
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj
BIN_DIR = bin
#Davi Santos Rodrigues
all: main
$(OBJ_DIR)/Ligue4.o: $(INCLUDE_DIR)/JogosTab.hpp $(INCLUDE_DIR)/Ligue4.hpp $(SRC_DIR)/Ligue4.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Ligue4.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Ligue4.o
$(OBJ_DIR)/Reversi.o: $(INCLUDE_DIR)/JogosTab.hpp $(INCLUDE_DIR)/Reversi.hpp $(SRC_DIR)/Reversi.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Reversi.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Reversi.o	
$(OBJ_DIR)/JogoVelha.o: $(INCLUDE_DIR)/JogosTab.hpp $(INCLUDE_DIR)/JogoVelha.hpp $(SRC_DIR)/JogoVelha.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/JogoVelha.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/JogoVelha.o
$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/JogoVelha.hpp $(INCLUDE_DIR)/Ligue4.hpp $(INCLUDE_DIR)/Reversi.hpp $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o
main: $(OBJ_DIR)/main.o $(OBJ_DIR)/Ligue4.o $(OBJ_DIR)/JogoVelha.o $(OBJ_DIR)/Reversi.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/main $^
clean:
	rm -f final $(OBJ_DIR)/*.o