#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */
#include <limits.h> /* INT_MAX */
#include <string.h>
#include "pathfinder.h"
#include "heap.h"

// newNode creates a new graph node
ListPointer newNode(int weight, int des){
	ListPointer newNode = malloc(sizeof(ListNode));
	newNode->designation = des;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

// freeGraph frees memory allocated for graph
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

// Create connections between cities (has to be done both ways)
void connect(ListPointer *master, int start, int destination, int weight) {
	ListPointer edge;

	edge = newNode(weight, destination);
	edge->next = master[start];
	master[start] = edge;

	edge = newNode(weight, start);
  edge->next = master[destination];
	master[destination] = edge;
}

// Remove connection between cities
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

// Print shortest path
void printPath(int u, int v, int parent[], char **cities){
	if(u == v){
		printf("%s\n", cities[u]);
	}
	else{
		printPath(parent[u], v, parent, cities);
		printf("%s\n", cities[u]);
	}
}

// findPath function makes use of the Djikstra algorithm
void findPath(ListPointer *graph, int v, int w, char **cities){
	int n = 12; // Predefined number of cities
  int u; // Current node
  int distance[n], parent[n];	// Arrays to store the pseudo distance & parent of current node
  Heap s = makeHeap(); // Inverse heap represents the to do list

	// Set pseudo distance of first node to 0, all other nodes to infinity and add nodes to heap
  for(int i = 0; i < n; i++){
    if(i == v){
      distance[i] = 0;
    }
    else{
      distance[i] = INT_MAX;
    }
    enqueue(distance[i], i, &s);
  }

	// Iterate through to do ListPointer
  while(!isEmptyHeap(s)){
    u = removeMin(&s); // Node with the shortest pseudo distance

		// If last node is reached
    if(u == w){
			// Check if goal is reachable
			if(distance[u] == INT_MAX){
				printf("UNREACHABLE\n");
				freeHeap(s);
				return;
			}
			printPath(u, v, parent, cities);
			printf("%d\n", distance[w]);
			freeHeap(s);
			return;
    } else { //Go through all other nodes connected to u
      ListPointer z = graph[u];
      while(z != NULL){
				// Check if goal is reachable
				if(distance[u] == INT_MAX){
					printf("UNREACHABLE\n");
					freeHeap(s);
					return;
				}
				// Relaxation step: modifies pseudo distance if shorter one is found
        if(distance[z->designation] > distance[u] + z->weight){
          parent[z->designation] = u;
          distance[z->designation] = distance[u] + z->weight;
					// Modifies pseudo distance in heap
					for(int i = 1; i < n; i++){
						if(s.node[i] == z->designation){
							s.pseudo[i] = distance[z->designation];
							upheap(&s, i);
							break;
						}
					}
        }
        z = z->next;
      }
    }
  }
}
