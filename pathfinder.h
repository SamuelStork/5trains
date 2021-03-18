#ifndef PATHFINDER_H
#define PATHFINDER_H

typedef struct ListNode *ListPointer;

typedef struct ListNode {
	int designation;
	int weight;
	ListPointer next;
} ListNode;

ListPointer newNode(int weight, int des);
//struct Graph *newGraph(int nodeNumber);
void connect(ListPointer *master, int start, int destination, int weight);
void printGraph(ListPointer *graph);



#endif
