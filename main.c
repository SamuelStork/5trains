#include <stdio.h>  /* printf */
#include <stdlib.h> /* free */
#include <assert.h> /* assert */
#include "pathfinder.h"

int main(int argc, char *argv[]) {

	char dictionary[12][25]{
		"Amsterdam", //0
		"Den Haag", //1
		"Den Helder",//2
		"Eindhoven",//3
		"Enschede", //4
		"Groningen",//5
		"Leeuwarden",//6
		"Maastricht"//7
		"Meppel", //8
		"Nijnmegen",//9
		"Utrecht", //10
		"Zwolle" //11
	};

	int graph [12][12];

	for (int i = 0, i < 12, i++){
		for (int j = 0, j < 12, j++){
			if (i == j){
				graph[i][j] = 0;
			} else {
				graph[i][j] = -1;
			}
		}
	}

	graph[0][1] = 46;
	graph[0][2] = 77;
	graph[0][10] = 26;
	graph[1][3] = 

	findPath();
	return 0;
}