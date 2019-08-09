#include <stdio.h>
#include <stdlib.h>
#include "EmployeeManageStack.h"


//Stack 초기화
void StackInit(Stack* pstack)
{
	pstack->top = NULL;
	pstack->tail = NULL;
}

//Stack에 데이터 입력(push)
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

//Stack에서 데이터 출력(pop)
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

//Stack이 비어있는지 확인(IsEmpty)
int SIsEmpty(Stack* pstack)
{
	if (pstack->top == NULL)
		return TRUE;
	else
		return FALSE;
}