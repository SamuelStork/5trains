#include "heap.h"

Heap makeHeap() {
  Heap h;
  h.pseudo = malloc(1 * sizeof(int));
  assert(h.pseudo != NULL);
  h.node = malloc(1 * sizeof(int));
  assert(h.node != NULL);
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
  hp->pseudo = realloc(hp->pseudo, newSize*sizeof(int));
  hp->node = realloc(hp->node, newSize*sizeof(int));
  hp->size = newSize;
}

void upheap(Heap *hp, int n) { //for reverse heap
  if (n == 1){
    return;
  }

  if(hp->pseudo[n] < hp->pseudo[n / 2]){
    swap(&(hp->pseudo[n]), &(hp->pseudo[n / 2]));
    swap(&(hp->node[n]), &(hp->node[n / 2]));
    upheap(hp, n / 2);
  }
}

void downheap(Heap *hp, int n) { //for reverse heap
  if(2 * n >= hp->front){
    return;
  }

  int *lp = &(hp->pseudo[2 * n]), *rp = &n;
  if(2 * n + 1 >= hp->front){
    rp = lp;
  } else {
    rp = &(hp->pseudo[2 * n + 1]);
  }
  int smaller = (*lp <= *rp ? 2 * n : 2 * n + 1);
  if(hp->pseudo[n] > hp->pseudo[smaller]){
    swap(&(hp->pseudo[n]), &(hp->pseudo[smaller]));
    swap(&(hp->node[n]), &(hp->node[smaller]));
    downheap(hp, smaller);
  }
}


void enqueue(int pseudo, int node, Heap *hp) {
  int fr = hp->front;
  if (fr == hp->size) {
    doubleHeapSize(hp);
  }
  hp->pseudo[fr] = pseudo;
  hp->node[fr] = node;
  upheap(hp, fr);
  hp->front = fr + 1;
}

int removeMin(Heap *hp) {
  int n;
  if (isEmptyHeap(*hp)) {
    heapEmptyError();
  }
  n = hp->node[1];
  hp->front--;
  hp->pseudo[1] = hp->pseudo[hp->front];
  hp->node[1] = hp->node[hp->front];
  downheap(hp, 1);
  return n;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void freeHeap(Heap hp) {
  free(hp.pseudo);
  free(hp.node);
}

void printHeap(Heap hp) {

  for (int idx = 1; idx < hp.front; ++idx) {
    printf("%d-%d ", hp.pseudo[idx], hp.node[idx]);
  }
  printf("\n");
}
