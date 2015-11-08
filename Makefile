CC = g++
OBJS = src/*.cpp
OBJ_NAME = chef
LINKER_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -llua
COMPILER_FLAGS = -std=c++11 -g
WARNING_FLAGS = #-Wall -Wextra
BIN = bin/

#Compile and run
all :
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(WARNING_FLAGS) $(LINKER_FLAGS) -o $(BIN)$(OBJ_NAME)
	$(BIN)$(OBJ_NAME)
