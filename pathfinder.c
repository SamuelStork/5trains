#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */
#include <string.h>
#include "pathfinder.h"

void findPath(int graph[9][9], int v, int w){
  int distance[12];
  //S <- nodes(graph)

  for(int i = 0; i < 12; i++){
    if(i == v){
      distance[i] = 0;
    }
    else{
      distance[i] = -1;
    }
  }

}
