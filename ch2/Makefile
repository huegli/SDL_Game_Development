##################################################################
# Declare Makefile variables
##################################################################

SDL2_CFLAGS := $(shell sdl2-config --cflags )
SDL2_LIB_PATH := $(shell sdl2-config --libs )

CC = clang++
LANG_STD = -std=c++17
COMPILER_FLAGS = -Wall -Wfatal-errors
SRC_FILES = main.cpp Game.cpp
LINKER_FLAGS = $(SDL2_LIB_PATH)
OBJ_NAME = game

build:
	$(CC) $(COMPILER_FLAGS) $(LANG_STD) $(INCLUDE_PATH) $(SDL2_CFLAGS) $(SRC_FILES) $(LINKER_FLAGS) -o $(OBJ_NAME)

run:
	./gameengine

clean:
	rm ./gameengine
