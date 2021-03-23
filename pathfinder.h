#ifndef PATHFINDER_H
#define PATHFINDER_H
//#include "LibStack.h"

typedef struct ListNode *ListPointer;

typedef struct ListNode {
	int designation;
	int weight;
	ListPointer next;
} ListNode;

ListPointer newNode(int weight, int des);
void freeGraph(ListPointer *graph);
void connect(ListPointer *master, int start, int destination, int weight);
void disconnect(ListPointer *master, int start, int destination);
void printGraph(ListPointer *graph);
void findPath(ListPointer *graph, int v, int w, char **cities);
void printPath(int u, int v, int parent[], char **cities);
void printGraph(ListPointer *graph);

#endif
