CC = gcc

CFLAGS = -O2 -std=c99 -pedantic -Wall -o -lm

main: main.c pathfinder.c
	$(CC) $(CFLAGS) $^ -o $@


