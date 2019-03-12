# OBJS specifies which files to compile as part of the project
OBJS = AnimatedGraphic.cpp base64.cpp Camera.cpp Game.cpp GameObjectFactory.cpp GameStateMachine.cpp InputHandler.cpp Level.cpp LevelParser.cpp PlatformerObject.cpp Player.cpp PlayState.cpp TextureManager.cpp TileLayer.cpp main.cpp CollisionManager.cpp ObjectLayer.cpp MainMenuState.cpp StateParser.cpp MenuButton.cpp

# CC specifies which compiler we're using
CC = g++

# COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

# LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -ltinyxml -lz

# OBJ_NAME specifies the name of our executable
OBJ_NAME = main

# This is the target that compiles our executable
build: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

run: build
	./$(OBJ_NAME)
