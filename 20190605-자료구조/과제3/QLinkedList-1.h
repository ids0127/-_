
#ifndef __Queueing_LINKEDLIST_H__
#define __Queueing_LINKEDLIST_H__

#define TRUE 1
#define FALSE 0

#define SIMUL_MAX 100

typedef struct employee
{
	int cheese;
	int bulgogi;
	int bigmag;
} Employee;

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _CLLQueue
{
	Node* front;
	Node* rear;
} CLLQ;

typedef CLLQ QUEUE;

void InitEmp(Employee* employee);
void InitQ(QUEUE* queue);
void EnQueue(QUEUE* queue, int data);
Data DeQueue(QUEUE* queue);
int IsEmptyQ(QUEUE* queue);

#endif // !__Q_LINKEDLIST_H__
