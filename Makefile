OBJS = ./src/*.cpp ./src/*/*.cpp
CC = g++
COMPILER_FLAGS = -w -std=c++17
LINKER_FLAGS = -lSDL2 -lSDL2_image -lbox2d
OBJ_NAME = game.exe

build: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

run:
	./$(OBJ_NAME)
