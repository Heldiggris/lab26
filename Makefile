CC = gcc
CFLAGS = -std=c99 
NAME = main

all:
	$(CC) $(CFLAGS) -o $(NAME) *.c