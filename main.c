#include <stdio.h>  /* printf */
#include <stdlib.h> /* free */
#include <assert.h> /* assert */
#include "heap.c"
#include "pathfinder.h"

void nameScan(char **dictionary, int n){
	int currentNumber;
	int i = 0;
	while (n > i){
		scanf("%d %s", &currentNumber, dictionary[i]);
		i ++;
	}
}

int main(int argc, char *argv[]) {
	int networkNumber;
	int nodeNumber;
	int connectionNumber;

	int i = 0;

	scanf("%d", &networkNumber);
	scanf("%d", &nodeNumber);
	char **dictionary = malloc(nodeNumber * sizeof(char *));
	dictionary[0] = malloc(nodeNumber * 35);
	for (i = 1; i < nodeNumber; i++){
		dictionary[i] = dictionary[0] + i*35;
	}
	printf("dictionary created");
	nameScan(dictionary, nodeNumber);
	Graph *graph;
	graph = newGraph(nodeNumber);

	scanf("%d", &connectionNumber);

	int start, destination, weight;

	for (i = 0; i < connectionNumber; i++){
		scanf("%d %d %d", &start, &destination, &weight);
		connect(graph, start, destination, weight);
	}
	printGraph(graph, nodeNumber);
 	


	return 0;	
}
