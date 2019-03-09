# OBJS specifies which files to compile as part of the project
OBJS = main.cpp InputHandler.cpp TextureManager.cpp Game.cpp GameStateMachine.cpp PlayState.cpp AnimatedGraphic.cpp SDLGameObject.cpp Player.cpp

# CC specifies which compiler we're using
CC = g++

# COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

# LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

# OBJ_NAME specifies the name of our executable
OBJ_NAME = main

# This is the target that compiles our executable
build: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

run: build
	./$(OBJ_NAME)
