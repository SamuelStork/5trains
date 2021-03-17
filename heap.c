#include "heap.h"

Heap makeHeap() {
  Heap h;
  h.array = malloc(1 * sizeof(int));
  assert(h.array != NULL);
  h.front = 1;
  h.size = 1;
  return h;
}

int isEmptyHeap(Heap h) {
  return (h.front == 1);
}

void heapEmptyError() {
  printf("heap empty\n");
  abort();
}

void doubleHeapSize (Heap *hp) {
  int newSize = hp->size * 2;
  hp->array = realloc(hp->array, newSize*sizeof(int));
  hp->size = newSize;
}

void upheap(Heap *hp, int n) {
  if (n == 1){
    return;
  }

  if(hp->array[n] > hp->array[n / 2]){
    swap(&(hp->array[n]), &(hp->array[n / 2]));
    upheap(hp, n / 2);
  }
}

void downheap(Heap *hp, int n) {
  if(2 * n >= hp->front){
    return;
  }

  int *lp = &(hp->array[2 * n]), *rp = &n;
  if(2 * n + 1 >= hp->front){
    rp = lp;
  } else {
    rp = &(hp->array[2 * n + 1]);
  }
  int bigger = (*lp >= *rp ? 2 * n : 2 * n + 1);
  if(hp->array[n] < hp->array[bigger]){
    swap(&(hp->array[n]), &(hp->array[bigger]));
    downheap(hp, bigger);
  }
}


void enqueue(int n, Heap *hp) {
  int fr = hp->front;
  if (fr == hp->size) {
    doubleHeapSize(hp);
  }
  hp->array[fr] = n;
  upheap(hp, fr);
  hp->front = fr + 1;
}

int removeMax(Heap *hp) {
  int n;
  if (isEmptyHeap(*hp)) {
    heapEmptyError();
  }
  n = hp->array[1];
  hp->front--;
  hp->array[1] = hp->array[hp->front];
  downheap(hp, 1);
  return n;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void freeHeap(Heap hp) {
  free(hp.array);
}

void printHeap(Heap hp) {

  for (int idx = 1; idx < hp.front; ++idx) {
    printf("%d ", hp.array[idx]);
  }
  printf("\n");
}
