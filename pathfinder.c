#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */
#include <string.h>
#include "pathfinder.h"

struct ListNode *newNode(int weight, int des){
	struct ListNode *newNode = malloc(sizeof(struct ListNode));
	newNode->designation = des;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}
struct Graph *newGraph(int nodeNumber){
	struct Graph *newGraph = malloc(sizeof(struct Graph));
	newGraph->start = malloc(nodeNumber*sizeof(struct ListNode*));
	for (int i = 0; i < nodeNumber; i++){
		newGraph->start[i] = NULL;
	}
	return newGraph;
}
void connect(struct Graph *master, int start, int destination, int weight){
	struct ListNode *edge;

	edge = newNode(weight, destination);
	edge->next = master->start[start];
	master->start[start] = edge;

	edge = newNode(weight, start);
	edge->next = master->start[destination];
	master->start[destination] = edge;
}

/*
void findPath(Graph g, int v, int w){
  int pos[12];
  int u;
  Stack path;
  int distance[12];
  //S <- nodes(graph)
  Heap s = makeHeap();

  for(int i = 0; i < 12; i++){
    if(i == v){
      distance[i] = 0;
    }
    else{
      distance[i] = -1;
    }
    enqueue(distance[i], i, s, &pos);
  }

  while(!isEmptyHeap(s)){
    u = removeMin(s, &pos);
    if(u == w){
      while(u != v){
        push(u, path);
        u <- parent of u // unsure yet
      }
      push(v, path)
      return path;
    } else {
      z = neighbourList[u];
      while(z != NULL){
        if(distance[z->node] > distance[u] + z->weight){
          //setparent
          distance[z] = distance[u] + z->weight;
        }
        z = z->next;
      }
    }
  }
}
*/
