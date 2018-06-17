###MAKEFILE###
#Variavéis
CC=gcc
CFLAGS=-W -Wall
EXEC=trabalhoED

# Selects all the .c files
SRC=$(wildcard *.c)

all: $(SRC)
	@gcc -o $(EXEC) $^
