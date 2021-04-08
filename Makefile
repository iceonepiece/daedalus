OBJS = ./src/Main.cpp ./src/core/*.cpp ./src/game/*.cpp ./src/vendor/*/*.cpp
CC = g++
COMPILER_FLAGS = -w -std=c++17
LINKER_FLAGS = -lSDL2 -lbox2d -lGLEW -framework OpenGL
OBJ_NAME = game.exe

build: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

run:
	./$(OBJ_NAME)
