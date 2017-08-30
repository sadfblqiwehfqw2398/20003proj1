# Sample Makefile with multiple goals
# You can copy this Makefile to use with any other project

# define C compiler & flags
CC = gcc
CFLAGS = -Wall

# define libraries to be linked (for example -lm)
LIB = 


HDR1 = func.h
SRC1 = func.c main.c

# OBJ is the same as SRC, just replace .c with .h
OBJ1 = $(SRC1:.c=.o)

# the executable name
EXE1 = autocomplete1

all: $(EXE1)

$(EXE1): $(OBJ1) Makefile
	$(CC) $(CFLAGS) -o $(EXE1) $(OBJ1) $(LIB)




clean:
	rm -f $(OBJ1) $(EXE1)

$(OBJ1): $(HDR1)
