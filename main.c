#include <stdio.h>  /* printf */
#include <stdlib.h> /* free */
#include <assert.h> /* assert */
#include "pathfinder.h"

int main(int argc, char *argv[]) {

	char dictionary[10][25]{
		"Amsterdam", //0
		"Den Helder",
		"Den Haag", 
		"Eindhoven",
		"Enschede", 
		"Groningen",
		"Leeuwarden",
		"Maastricht"
		"Meppel", 
		"Nijnmegen",
		"Utrecht", 
		"Zwolle" 
	};

	int graph [9][9];

	findPath();
	return 0;
}
