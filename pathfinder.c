#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */
#include <string.h>
#include "pathfinder.h"

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
