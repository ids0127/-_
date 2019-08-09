#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EmpManageCard.h"

//초기화
void ListInit(List* plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}
void LInsertFront(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}
}

//리스트에 데이터 추가
void LInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;

	}
	(plist->numOfData)++;
}

//구조체에 사원 추가
EmpInfo MakeEmpInfo(int num, char* name)
{
	EmpInfo* newData = (EmpInfo*)malloc(sizeof(EmpInfo));
	strcpy(newData->name, name);
	newData->empNumber = num;

	return *newData;
}

//첫번째인지 확인
int LFirst(List* plist, LData* data)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*data = plist->cur->data;
	return TRUE;
}

//다음으로 이동
int LNext(List* plist, LData* data)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*data = plist->cur->data;
	return TRUE;

}


//리스트에서 저장된 데이터 수
int LCount(List* plist)
{
	return plist->numOfData;
}

//특근자 조회
void OverTimeSearch(List* plist, char* name, int num)
{
	EmpInfo* EmpWorker = (EmpInfo*)malloc(sizeof(EmpInfo));

	if (LFirst(plist, EmpWorker))
	{
		if (!strcmp(EmpWorker->name,name))
		{
			for (int i = 0; i < num; i++)
				LNext(plist, EmpWorker);
		}
		printf("%s 이후 %d번째 특근자 : [%d][%s]\n", name, num, EmpWorker->empNumber, EmpWorker->name);
		return;
	}
	for (int i = 0; i = LCount(plist) - 1; i++)
	{
		LNext(plist, EmpWorker);
		if (!strcmp(EmpWorker->name,name))
		{
			for (int i = 0; i < num; i++)
				LNext(plist, EmpWorker);
		}
		printf("%d번째 특근자 : [%d]\n", num, EmpWorker->empNumber);
		return;
	}

	printf("등록된 사원이 없습니다.");
	return;
}

//전체사원
void ShowEmpInfo(List* plist)
{
	LData data;

	printf("=== 등록된 사원리스트 ===\n\n");

	if (LFirst(plist, &data))
	{
		printf("[사번] : %d [이름] : %s\n", data.empNumber,data.name);
		for (int i = 0; i < plist->numOfData-1; i++)
		{
			LNext(plist, &data);
			printf("[사번] : %d [이름] : %s\n", data.empNumber, data.name);
		}
	}
	printf("\n\n");
}
