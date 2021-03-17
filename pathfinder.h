#ifndef PATHFINDER_H
#define PATHFINDER_H

#define N 11

int data[N];
int visited[N];

typedef struct ListNode *ListPointer;

typedef struct {
	int node;
	int weight;
	ListPointer next;
} ListNode;

ListPointer neighbourList[N];

#endif
