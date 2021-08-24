PROJ_NAME=program
SOURCE_FILES=$(shell find . -name "*.c")
S_OBJ=$(patsubst %.c, %.o, $(SOURCE_FILES))
COMPILER=gcc
CXXFLAGS=-c -g -Wall -Wextra

all: $(PROJ_NAME)

$(PROJ_NAME): $(S_OBJ)
	@echo Linking objects...
	@$(COMPILER) -o $@ $^

%.o: %.c %.h
	@echo Compiling and generating object $@ ...
	@$(COMPILER) $< $(CXXFLAGS) -o $@

main.o: main.c
	@echo Compiling and generating object $@ ...
	@$(COMPILER) $< $(CXXFLAGS)

clean:
	@echo Removing secondary things
	@rm -r -f objects $(S_OBJ) $(PROJ_NAME)
	@echo Done!
