CC = gcc

CFLAGS = -O2 -std=c99 -pedantic -Wall -o -lm -g

main: main.c pathfinder.c heap.c LibStack.c
	$(CC) $(CFLAGS) $^ -o $@
