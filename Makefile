CC = gcc
CFLAGS = -g -std=c99 -w -pipe -O3

all: lab26

deque:    deque.o
	$(CC) $^ -o $@

lab26:  deque.o lab26.o
	$(CC) $^ -o $@

clean:
	rm -f *.o

cleanall:
	rm -f lab26 *.o

