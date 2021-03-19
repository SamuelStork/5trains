#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */
#include <limits.h> /* INT_MAX */
#include <string.h>
#include "pathfinder.h"
#include "heap.c"
#include "LibStack.c"

ListPointer newNode(int weight, int des){
	ListPointer newNode = malloc(sizeof(ListNode));
	newNode->designation = des;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}
/*
ListPointer newGraph(int nodeNumber){
	ListPointer new = malloc(sizeof(ListNode));
	new->start = malloc(nodeNumber*sizeof(struct ListNode*));
	for (int i = 0; i < nodeNumber; i++){
		newGraph->start[i] = NULL;
	}
	return newGraph;
}
*/
void connect(ListPointer *master, int start, int destination, int weight){
	ListPointer edge;

	edge = newNode(weight, destination);
	edge->next = master[start];
	master[start] = edge;

	edge = newNode(weight, start);
  edge->next = master[destination];
	master[destination] = edge;

}

void printGraph(ListPointer *graph){
  for(int i = 0; i < 12; i++){
    ListPointer temp = graph[i];
    printf("\n Vertex %d:\n ", i);
    while(temp != NULL){
      printf("%d -> ", temp->designation);
      temp = temp->next;
    }
    printf("\n");
  }
}

void findPath(ListPointer *graph, int v, int w){
	int n = 12;
  int *pos = malloc(n * sizeof(int));
  int u;
//  int *path = calloc(n, sizeof(int));
  int distance[n];
	int parent[n];
  Heap s = makeHeap();

  for(int i = 0; i < 12; i++){
    if(i == v){
      distance[i] = 0;
    }
    else{
      distance[i] = INT_MAX;
    }
    enqueue(distance[i], i, &s, pos);
  }
//
  while(!isEmptyHeap(s)){
    u = removeMin(&s, pos);
//		printf("u = %d\n", u);
//		printHeap(s);
    if(u == w){
      while(u != v){
//				for(int i = 0; i < 3; i++){
        printf("%d\n", u);
        u = parent[u];
      }
			printf("%d\n", v);
      printf("1\n");
      return;
    } else {
      ListPointer z = graph[u];
      while(z != NULL){
//				printf("node = %d\n", z->designation);
//				printf("3: %d\n", s.node[pos[11]]);
//				printf("%d %d\n", pos[8], pos[11]);
        if(distance[z->designation] > distance[u] + z->weight){
//					printf("old weight %d\n", distance[z->designation]);
//					printf("new weight %d\n", (distance[u]+ z->weight));
          parent[z->designation] = u;
          distance[z->designation] = distance[u] + z->weight;
//					printf("p1 = %d\n", s.pseudo[pos[z->designation]]);
//					printf("modified weight %d\n", s.node[pos[z->designation]]);
					s.pseudo[pos[z->designation]] = distance[u] + z->weight;
					upheap(&s, (pos[z->designation]), pos);
//					printf("3: %d\n", s.node[pos[11]]);
//					printHeap(s);
//					printf("p2 = %d\n", s.node[pos[z->designation]]);
        }
//				printf("%d -> ", z->designation);
        z = z->next;
      }
//			printf("\n");
    }
  }
}
