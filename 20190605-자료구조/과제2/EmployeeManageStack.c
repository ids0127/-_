#include <stdio.h>
#include <stdlib.h>
#include "EmployeeManageStack.h"


//Stack �ʱ�ȭ
void StackInit(Stack* pstack)
{
	pstack->top = NULL;
	pstack->tail = NULL;
}

//Stack�� ������ �Է�(push)
void SPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (pstack->top == NULL)
		pstack->tail = newNode;
	
	newNode->next = pstack->top;
	pstack->top = newNode;
	pstack->tail->next = pstack->top;
}

//Stack���� ������ ���(pop)
Data SPop(Stack* pstack)
{
	Node* pNode = pstack->top;
	Data pData = pNode->data;

	if (pstack->top == pstack->tail)
		pstack->top == NULL;
	else
		pstack->top = pstack->top->next;

	pstack->tail->next = pstack->top;

	free(pNode);

	return pData;
}

//Stack�� ����ִ��� Ȯ��(IsEmpty)
int SIsEmpty(Stack* pstack)
{
	if (pstack->top == NULL)
		return TRUE;
	else
		return FALSE;
}