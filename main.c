#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */
#include <limits.h> /* INT_MAX */
#include <string.h>
#include "pathfinder.h"
#include "heap.h"

int main(int argc, char *argv[]) {
	// Set predefined amount of nodes & create the city dictionary
	int n = 12;
	char *cities[n];
		cities[0] = "Amsterdam";
		cities[1] = "Den Haag";
		cities[2] = "Den Helder";
		cities[3] = "Eindhoven";
		cities[4] = "Enschede";
		cities[5] = "Groningen";
		cities[6] = "Leeuwarden";
		cities[7] = "Maastricht";
		cities[8] = "Meppel";
		cities[9] = "Nijmegen";
		cities[10] = "Utrecht";
		cities[11] = "Zwolle";

	// Create and initialize Graph & add predefined connections
	ListPointer graph[n];
	for(int i = 0; i < n; i++){
		graph[i] = NULL;
	}

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

	// Scan the number of disruptions
	int disruptions;
	scanf("%d", &disruptions);

	// While loop to receive input
	while(1){
		char from[n], to[n];
		int i1 = -1, i2 = -1;
		getchar();
		scanf("%[^\n]s", from);
		getchar();
		scanf("%[^\n]s", to);

		// If statement for loop termination
		if(from[0] == '!'){
			break;
		}

		// Compare scanned input with dictionary
		for(int i = 0; i < n; i++){
			if(strcmp(from, cities[i]) == 0){
				i1 = i;
			} else if(strcmp(to, cities[i]) == 0){
				i2 = i;
			}
		}
		// Remove connections or find shortest path
		if(disruptions){
			disconnect(graph, i1, i2);
			disconnect(graph, i2, i1);
			disruptions--;
		} else{
			findPath(graph, i1, i2, cities);
		}
	}
	freeGraph(graph);
	return 0;
}
