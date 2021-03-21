#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */
#include <limits.h> /* INT_MAX */
#include <string.h>
#include "pathfinder.h"
#include "heap.h"
#include "LibStack.h"
#define N 12
/*
void nameScan(char **dictionary, int n){
	int currentNumber;
	int i = 0;
	while (n > i){
		scanf("%d %s", &currentNumber, dictionary[i]);
		i ++;
	}
}
*/
int main(int argc, char *argv[]) {
	/*
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
	*/
	char cities[N][N] = {
		"Amsterdam",
		"Den Haag",
		"Den Helder",
		"Eindhoven",
		"Enschede",
		"Groningen",
		"Leeuwarden",
		"Maastricht",
		"Meppel",
		"Nijmegen",
		"Utrecht",
		"Zwolle"
	};

	ListPointer graph[N] = { 0 };

	connect(graph, 0, 1, 46);
	connect(graph, 0, 2, 77);
	connect(graph, 0, 10, 26);
	connect(graph, 1, 3, 89);
	connect(graph, 3, 7, 63);
	connect(graph, 3, 9, 55);
	connect(graph, 3, 10, 47);
	connect(graph, 4, 11, 50);
	connect(graph, 5, 6, 34);
	connect(graph, 5, 8, 49);
	connect(graph, 6, 8, 40);
	connect(graph, 7, 9, 111);
	connect(graph, 8, 11, 15);
	connect(graph, 9, 11, 77);
	connect(graph, 10, 11, 51);

	int disruptions;
	scanf("%d", &disruptions);

	while(disruptions != 0){
		char s1[N], s2[N];
		int i1 = -1, i2 = -1;
		scanf("%s", s1);
		scanf("%s", s2);

		for(int i = 0; i < N; i++){
			if(strcmp(s1, cities[i]) == 0){
				i1 = i;
			} else if(strcmp(s2, cities[i]) == 0){
				i2 = i;
			}
		}

		disconnect(graph, i1, i2);
		disconnect(graph, i2, i1);
		disruptions--;
	}

	while(1){
		char from[N], to[N];
		int i1 = -1, i2 = -1;
		scanf("%s", from);
		scanf("%s", to);

		if(from[0] == '!'){
			break;
		}

		for(int i = 0; i < N; i++){
			if(strcmp(from, cities[i]) == 0){
				i1 = i;
			} else if(strcmp(to, cities[i]) == 0){
				i2 = i;
			}
		}
		findPath(graph, i1, i2, cities);
	}
	freeGraph(graph);
	return 0;
}
