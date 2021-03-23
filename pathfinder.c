#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */
#include <limits.h> /* INT_MAX */
#include <string.h>
#include "pathfinder.h"
#include "heap.h"
//#include "LibStack.h"

ListPointer newNode(int weight, int des){
	ListPointer newNode = malloc(sizeof(ListNode));
	newNode->designation = des;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

void freeGraph(ListPointer *graph) {
	for(int i = 0; i < 12; i++){
		ListPointer g1;
		while ( graph[i] != NULL ) {
			g1 = graph[i]->next;
			free(graph[i]);
			graph[i] = g1;
		}
	}
  return;
}

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

void printPath(int u, int v, int parent[], char **cities){
	if(u == v){
		printf("%s\n", cities[u]);
	}
	else{
		printPath(parent[u], v, parent, cities);
		printf("%s\n", cities[u]);
	}
}

void findPath(ListPointer *graph, int v, int w, char **cities){
	int n = 12;
  int pos[n];
  int u;
  int distance[n];
	int parent[n];
//	memset(parent, 0, n*sizeof(int));
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

			if(distance[u] == INT_MAX){
				printf("UNREACHABLE\n");
				freeHeap(s);
				return;
			}
			printPath(u, v, parent, cities);
			printf("%d\n", distance[w]);
			freeHeap(s);
			return;
    } else {
      ListPointer z = graph[u];
      while(z != NULL){
				if(distance[u] == INT_MAX){
					printf("UNREACHABLE\n");
					freeHeap(s);
					return;
				}
        if(distance[z->designation] > distance[u] + z->weight){
          parent[z->designation] = u;
          distance[z->designation] = distance[u] + z->weight;
					s.pseudo[pos[z->designation]] = distance[z->designation];
					upheap(&s, (pos[z->designation]), pos);
        }
        z = z->next;
      }
    }
  }
	printf("UNREACHABLE\n");
	freeHeap(s);
}
