
#include <stdio.h>
#include <stdlib.h>
#include "QLinkedList-1.h"

void InitEmp(Employee* employee)
{
	employee->cheese = 12;
	employee->bulgogi = 15;
	employee->bigmag = 24;
}

void InitQ(QUEUE* queue)
{
	queue->front = (Node*)malloc(sizeof(Node));
	queue->front->next = NULL;

	queue->rear = NULL;
}

void EnQueue(QUEUE* queue, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (IsEmptyQ(queue) == TRUE)
	{
		queue->front->next = newNode;
		queue->rear = newNode;
		newNode->next = queue->front;
	}
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
		newNode->next = queue->front;
	}
}

Data DeQueue(QUEUE* queue)
{
	if (queue->front->next == NULL)
	{
		puts("저장된 데이터가 없습니다.");
		exit(-1);
	}

	Node* cur = queue->front->next;
	Data curData = cur->data;
	Node* curNext = cur->next;

	if (queue->front == curNext)
	{
		queue->front->next = NULL;
		queue->rear = NULL;
	}
	else
		queue->front->next = curNext;

	free(cur);

	return curData;
}

int IsEmptyQ(QUEUE* queue)
{
	if ((queue->front->next == NULL) && (queue->rear == NULL))
		return TRUE;

	return FALSE;
}
