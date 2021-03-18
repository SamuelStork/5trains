#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */
#include <string.h>
#include "pathfinder.h"

ListNode * newNode(int weight, int des){
	ListNode *newNode = malloc(sizeof(ListNode));
	newNode->designation = des;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}
Graph * newGraph(int nodeNumber){
	Graph *newGraph = malloc(sizeof(Graph));
	newGraph->start = malloc(nodeNumber*sizeof(ListNode*));
	for (int i = 0; i < nodeNumber; i++){
		newGraph->start[i] = NULL;
	}
	return newGraph;
}
void connect(Graph *Master, int start, int destination, int weight){
	ListNode *edge;

	edge = newNode(weight, destination);
	edge->next = Master->start[start];
	Master->start[start] = edge;

	edge = newNode(weight, start);
	edge->next = Master->start[destination];
	Master->start[destination] = edge;
}


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
