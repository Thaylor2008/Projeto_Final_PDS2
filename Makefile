CC=g++
CFLAGS=-std=c++11 -Wall -no-pie
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj
BIN_DIR=bin

# Davi Santos Rodrigues
all: main
$(OBJ_DIR)/Partidas.o: $(INCLUDE_DIR)/Partidas.hpp $(SRC_DIR)/Partidas.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Partidas.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Partidas.o
$(OBJ_DIR)/Usuario.o: $(INCLUDE_DIR)/Usuario.hpp $(SRC_DIR)/Usuario.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Usuario.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Usuario.o
$(OBJ_DIR)/Admin.o: $(INCLUDE_DIR)/Admin.hpp $(SRC_DIR)/Admin.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Admin.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Admin.o
$(OBJ_DIR)/Jogador.o: $(INCLUDE_DIR)/Usuario.hpp $(INCLUDE_DIR)/Jogador.hpp $(SRC_DIR)/Jogador.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Jogador.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Jogador.o
$(OBJ_DIR)/Ligue4.o: $(INCLUDE_DIR)/JogosTab.hpp $(INCLUDE_DIR)/Ligue4.hpp $(SRC_DIR)/Ligue4.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Ligue4.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Ligue4.o
$(OBJ_DIR)/Reversi.o: $(INCLUDE_DIR)/JogosTab.hpp $(INCLUDE_DIR)/Reversi.hpp $(SRC_DIR)/Reversi.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Reversi.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Reversi.o
$(OBJ_DIR)/JogoVelha.o: $(INCLUDE_DIR)/JogosTab.hpp $(INCLUDE_DIR)/JogoVelha.hpp $(SRC_DIR)/JogoVelha.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/JogoVelha.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/JogoVelha.o
$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/JogoVelha.hpp $(INCLUDE_DIR)/Ligue4.hpp $(INCLUDE_DIR)/Reversi.hpp \
                   $(INCLUDE_DIR)/Admin.hpp $(INCLUDE_DIR)/Jogador.hpp $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o
main: $(OBJ_DIR)/main.o $(OBJ_DIR)/Ligue4.o $(OBJ_DIR)/JogoVelha.o $(OBJ_DIR)/Reversi.o \
      $(OBJ_DIR)/Admin.o $(OBJ_DIR)/Jogador.o $(OBJ_DIR)/Usuario.o $(OBJ_DIR)/Partidas.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/main $^

$(OBJ_DIR)/test_main.o: $(SRC_DIR)/test_main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/test_main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/test_main.o
tests: $(OBJ_DIR)/test_main.o $(OBJ_DIR)/Ligue4.o $(OBJ_DIR)/JogoVelha.o $(OBJ_DIR)/Reversi.o \
       $(OBJ_DIR)/Admin.o $(OBJ_DIR)/Jogador.o $(OBJ_DIR)/Usuario.o $(OBJ_DIR)/Partidas.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/tests $^
run-tests: tests
	$(BIN_DIR)/tests

clean:
ifeq ($(OS),Windows_NT)
	del /Q $(OBJ_DIR)\*.o $(BIN_DIR)\main.exe $(BIN_DIR)\main
else
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/main $(BIN_DIR)\main.exe
endif
