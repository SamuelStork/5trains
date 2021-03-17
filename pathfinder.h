#ifndef PATHFINDER_H
#define PATHFINDER_H



typedef struct ListNode *ListPointer;

typedef struct {
	int node;
	int weight;
	ListPointer next;
} ListNode;

typedef struct{
	ListNode n;
	int data;
	int visited;
} Graph;

Graph newGarph();
void findPath();

#endif
