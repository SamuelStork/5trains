#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

typedef struct Heap {
  int *pseudo;
  int *node;
  int front;
  int size;
} Heap;

void doubleHeapSize (Heap *hp);
int removeMin(Heap *hp, int **pos);
void enqueue(int pseudo, int node, Heap *hp, int **pos);
void heapEmptyError();
int isEmptyHeap(Heap h);
Heap makeHeap();
void upheap(Heap *hp, int n, int **pos);
void downheap(Heap *hp, int n, int **pos);
void swap(int *a, int *b);
void freeHeap(Heap hp);
void printHeap(Heap hp);
void heapSort(int n, int arr[]);

#endif
