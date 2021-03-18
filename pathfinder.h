#ifndef PATHFINDER_H
#define PATHFINDER_H



typedef struct {
	int designation;
	int weight;
	struct ListNode *next;
} ListNode;

typedef struct {
	ListNode **start;
} Graph;


ListNode *newNode(int weight, int des);
Graph *newGraph(int nodeNumber);
void connect(Graph *Master, int start, int destination, int weight);



#endif
