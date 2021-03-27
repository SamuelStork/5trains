#ifndef PATHFINDER_H
#define PATHFINDER_H
#include <math.h>
//#include "LibStack.h"

typedef struct ListNode *ListPointer;

typedef struct ListNode {
	int designation;
	long double weight;
	ListPointer next;
} ListNode;

long double heuristic(long double x1, long double y1, long double x2, long double y2, long double distance);
ListPointer newNode(long double weight, int des);
void freeGraph(ListPointer *graph);
void connect(ListPointer *master, int start, int destination, long double weight);
void disconnect(ListPointer *master, int start, int destination);
void printGraph(ListPointer *graph);
void findPath(ListPointer *graph, int v, int w, char **cities, long double *x, long double *y);
void printPath(int u, int v, int parent[], char **cities);
void printGraph(ListPointer *graph);

#endif
