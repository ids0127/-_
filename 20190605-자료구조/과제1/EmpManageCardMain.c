#include <stdio.h>
#include "EmpManageCard.h"

int main(void)
{
	// 1. List�� ����, �ʱ�ȭ
	List list;

	ListInit(&list);

	LInsert(&list, MakeEmpInfo(1, "������"));
	LInsert(&list, MakeEmpInfo(2, "�ż���"));
	LInsert(&list, MakeEmpInfo(3, "������"));
	LInsert(&list, MakeEmpInfo(4, "������"));

	ShowEmpInfo(&list);

	//OverTimeSearch(&list, "������", 3);
	OverTimeSearch(&list,"������",5);

	int data;

	return 0;
}