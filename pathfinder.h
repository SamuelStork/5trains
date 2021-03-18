#ifndef PATHFINDER_H
#define PATHFINDER_H

struct ListNode{
	int designation;
	int weight;
	struct ListNode *next;
};

struct Graph{
	struct ListNode **start;
};


struct ListNode *newNode(int weight, int des);
struct Graph *newGraph(int nodeNumber);
void connect(struct Graph *master, int start, int destination, int weight);



#endif
