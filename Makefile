NC_DIR 	:= headers
SRC_DIR := src
OBJ_DIR := build

CC 			:= g++
CPPFLAGS 	:= -I$(INC_DIR) -MMD -MP 	# linker flags
CXXFLAGS 	:= -Wall 					# compiler flags
LDLIBS 		:= -lSDL2 -lSDL2_image -lSDL2_ttf -ltinyxml -lz


SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS    := $(wildcard $(OBJ_DIR)/*.d)

.PHONY: clean

run: $(OBJS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean: ; $(RM) $(DEPS) $(OBJECTS)

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(OUTPUT_OPTION) $<

include $(DEPS)

$(MAKEFILE_LIST): ;
%:: %,v
%:: RCS/%,v
%:: RCS/%
%:: s.%
%:: SCCS/s.%%  
