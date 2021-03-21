#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */
#include <limits.h> /* INT_MAX */
#include <string.h>
#include "pathfinder.h"
#include "heap.h"
#include "LibStack.h"

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
void connect(ListPointer *master, int start, int destination, int weight) {
	ListPointer edge;

	edge = newNode(weight, destination);
	edge->next = master[start];
	master[start] = edge;

	edge = newNode(weight, start);
  edge->next = master[destination];
	master[destination] = edge;

}

void disconnect(ListPointer *master, int start, int destination) {
	ListPointer temp = master[start];
	ListPointer prev;

	if(temp != NULL && temp->designation == destination){
		master[start] = temp->next;
		free(temp);
		return;
	}

	while(temp != NULL && temp->designation != destination){
		prev = temp;
		temp = temp->next;
	}

	prev->next = temp->next;
	free(temp);
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
//
void findPath(ListPointer *graph, int v, int w, char cities[][12]){
	int n = 12;
  int *pos = malloc(n * sizeof(int));
  int u;
  int distance[n];
	int parent[n];
  Heap s = makeHeap();

  for(int i = 0; i < n; i++){
    if(i == v){
      distance[i] = 0;
    }
    else{
      distance[i] = INT_MAX;
    }
    enqueue(distance[i], i, &s, pos);
  }

  while(!isEmptyHeap(s)){
    u = removeMin(&s, pos);
    if(u == w){
			Stack path = newStack(n);
      while(u != v){
				push(u, &path);
//        printf("%d\n", u);
        u = parent[u];
      }
			push(v, &path);
			while(!isEmptyStack(path)){
				int s1 = pop(&path);
				printf("%s\n", cities[s1]);
			}
			printf("%d\n", distance[w]);
      return;
    } else {
      ListPointer z = graph[u];
      while(z != NULL){
				if(distance[u] == INT_MAX){
					printf("UNREACHABLE\n");
					return;
				}
        if(distance[z->designation] > distance[u] + z->weight){
          parent[z->designation] = u;
          distance[z->designation] = distance[u] + z->weight;
					s.pseudo[pos[z->designation]] = distance[u] + z->weight;
					upheap(&s, (pos[z->designation]), pos);
        }
        z = z->next;
      }
    }
  }
}
