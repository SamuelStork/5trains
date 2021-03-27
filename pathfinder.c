#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */
#include <limits.h> /* INT_MAX */
#include <float.h>
#include <math.h>
#include <string.h>
#include "pathfinder.h"
#include "heap.h"

long double heuristic(long double x1, long double y1, long double x2, long double y2, long double distance){
	long double pi = 3.14159265358979323846;
	x1 = (pi / 180) * x1;
	y1 = (pi / 180) * y1;
	x2 = (pi / 180) * x2;
	y2 = (pi / 180) * y2;
	long double dlat = fabs(y1 - y2);
	long double dlon = fabs(x1 - x2);
	long double ans = pow(sin(dlat / 2), 2) + cos(y1) * cos(y2) * pow(sin(dlon / 2), 2);
	ans = 2 * asin(sqrt(ans));
	long double r = 6371;
//	printf("%Lf\n", ans*r);
	return (ans * r) + distance;
}

// newNode creates a new graph node
ListPointer newNode(long double weight, int des){
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
void connect(ListPointer *master, int start, int destination, long double weight) {
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
void findPath(ListPointer *graph, int v, int w, char **cities, long double *x, long double *y){
	int n = 12; // Predefined number of cities
  int u; // Current node
  long double distance[n];
	int parent[n];	// Arrays to store the pseudo distance & parent of current node
  Heap s = makeHeap(); // Inverse heap represents the to do list

	// Set pseudo distance of first node to 0, all other nodes to infinity and add nodes to heap
  for(int i = 0; i < n; i++){
    if(i == v){
      distance[i] = 0;
			long double temp = heuristic(x[i], y[i], x[w], y[w], distance[i]);
			enqueue(temp, i, &s);
    }
    else{
      distance[i] = LDBL_MAX;
			enqueue(distance[i], i, &s);
    }
  }

	// Iterate through to do ListPointer
  while(!isEmptyHeap(s)){
    u = removeMin(&s); // Node with the shortest pseudo distance

		// If last node is reached
    if(u == w){
			// Check if goal is reachable
			if(distance[u] == LDBL_MAX){
				printf("UNREACHABLE\n");
				freeHeap(s);
				return;
			}
			printPath(u, v, parent, cities);
			printf("%d\n", (int) distance[w]);
			freeHeap(s);
			return;
    } else { //Go through all other nodes connected to u
      ListPointer z = graph[u];
      while(z != NULL){
				// Check if goal is reachable
				if(distance[u] == LDBL_MAX){
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
							s.pseudo[i] = heuristic(x[z->designation], y[z->designation], x[w], y[w], distance[z->designation]);
//							printf("%Lf\n", heuristic(x[z->designation], y[z->designation], x[w], y[w], distance[z->designation]));
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
