###MAKEFILE###
#Variavéis
CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
EXEC=arvores

# Selects all the .c files
SRC=$(wildcard *.c)

all: $(SRC)
	@gcc -o $(EXEC) $^ $(CFLAGS)
