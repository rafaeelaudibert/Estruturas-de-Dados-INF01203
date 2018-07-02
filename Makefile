###MAKEFILE###
#Variavéis
CC=gcc
EXEC=trabalhoED

# Selects all the .c files
SRC=$(wildcard *.c)

all: $(SRC)
	@gcc -o $(EXEC) $^
