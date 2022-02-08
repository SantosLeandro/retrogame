# Name of the project
PROJ_NAME=game
 
# .c files
#C_SOURCE=$(wildcard ./source/*.c)
C_SOURCE=$(wildcard ./source/*.cpp ./source/core/*.cpp ./source/game/*.cpp ./source/allegro/*.cpp )

 
# .h files
H_SOURCE=$(wildcard ./source/*.h ./source/core/*.h ./source/game/*.h ./source/allegro/*.h )

# Object files
#OBJ=$(subst .cpp,.o,$(subst source,objects,$(C_SOURCE)))
OBJ=$(subst .cpp,.o,$(subst source,objects,$(C_SOURCE)))

# Compiler and linker
CC=g++
 
# Flags for compiler
CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -ansi      \
         -pedantic	\
		 -std=c++17\
		 -O2		\
		 
LIBS= -lallegro -lallegro_primitives -lallegro_image -lallegro_font
 
# Command used at clean target
RM = rm -rf
 
#
# Compilation and linking
#
all: objFolder $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using GCC linker: $@'
	$(CC) $^ $(LIBS) -o ./bin/$@
	@ echo 'Finished building binary: $@'
	@ echo ' '
 
./objects/%.o: ./source/%.cpp ./source/%.h
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(LIBS) $(CC_FLAGS) -o $@ 
	@ echo ' '
 
./objects/main.o: ./source/main.cpp $(H_SOURCE)
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(LIBS) $(CC_FLAGS) -o $@ 
	@ echo ' '
	

 
objFolder:
	@ mkdir -p objects
	@ mkdir -p objects/allegro
	@ mkdir -p objects/game
	@ mkdir -p objects/core
 
run:
	@ ./bin/$(PROJ_NAME)
clean:
	@ $(RM) ./objects/game/*.o $(PROJ_NAME) *~
	@ $(RM) ./objects/core/*.o $(PROJ_NAME) *~
	@ $(RM) ./objects/allegro/*.o $(PROJ_NAME) *~
	@ $(RM) ./objects/*.o $(PROJ_NAME) *~
	@ rmdir objects/game
	@ rmdir objects/core
	@ rmdir objects/allegro
	@ rmdir objects
 
.PHONY: all clean