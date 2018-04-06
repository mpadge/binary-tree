CFILE = bst
OBJ = junk
CPP = clang++

CPPFLAGS = --std=c++11 -fsanitize=undefined -Wall -pedantic -Wconversion
#CPPFLAGS = --std=c++11 -Wall -pedantic -Wconversion

all: compile run

compile: $(CFILE).cpp
	$(CPP) $(CFILE).cpp $(CPPFLAGS) -o $(OBJ)

val: $(OBJ)
	valgrind --tool=memcheck --leak-check=full ./$(OBJ)

run: $(OBJ)
	./$(OBJ)
