#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EmpManageCard.h"

//�ʱ�ȭ
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

//����Ʈ�� ������ �߰�
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

//����ü�� ��� �߰�
EmpInfo MakeEmpInfo(int num, char* name)
{
	EmpInfo* newData = (EmpInfo*)malloc(sizeof(EmpInfo));
	strcpy(newData->name, name);
	newData->empNumber = num;

	return *newData;
}

//ù��°���� Ȯ��
int LFirst(List* plist, LData* data)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*data = plist->cur->data;
	return TRUE;
}

//�������� �̵�
int LNext(List* plist, LData* data)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*data = plist->cur->data;
	return TRUE;

}


//����Ʈ���� ����� ������ ��
int LCount(List* plist)
{
	return plist->numOfData;
}

//Ư���� ��ȸ
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
		printf("%s ���� %d��° Ư���� : [%d][%s]\n", name, num, EmpWorker->empNumber, EmpWorker->name);
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
		printf("%d��° Ư���� : [%d]\n", num, EmpWorker->empNumber);
		return;
	}

	printf("��ϵ� ����� �����ϴ�.");
	return;
}

//��ü���
void ShowEmpInfo(List* plist)
{
	LData data;

	printf("=== ��ϵ� �������Ʈ ===\n\n");

	if (LFirst(plist, &data))
	{
		printf("[���] : %d [�̸�] : %s\n", data.empNumber,data.name);
		for (int i = 0; i < plist->numOfData-1; i++)
		{
			LNext(plist, &data);
			printf("[���] : %d [�̸�] : %s\n", data.empNumber, data.name);
		}
	}
	printf("\n\n");
}
