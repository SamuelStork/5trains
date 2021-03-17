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


void findPath(int v, int w){

}
