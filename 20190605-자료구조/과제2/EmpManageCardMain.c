#include <stdio.h>
//#include "EmpManageCard.h"
#include "EmployeeManageStack.h"

//int main(void)
//{
//	// 1. List�� ����, �ʱ�ȭ
//	List list;
//
//	ListInit(&list);
//
//	LInsert(&list, MakeEmpInfo(1, "������"));
//	LInsert(&list, MakeEmpInfo(2, "�ż���"));
//	LInsert(&list, MakeEmpInfo(3, "������"));
//	LInsert(&list, MakeEmpInfo(4, "������"));
//
//	ShowEmpInfo(&list);
//
//	//OverTimeSearch(&list, "������", 3);
//	OverTimeSearch(&list,"������",5);
//
//	int data;
//
//	return 0;
//}

int main(void)
{
	// Stack�� ���� �� �ʱ�ȭ ///////
	Stack stack;
	StackInit(&stack);

	// ������ �ֱ� ///////
	SPush(&stack, 1);  SPush(&stack, 2);
	SPush(&stack, 3);  SPush(&stack, 4);
	SPush(&stack, 5);

	// ������ ������ ///////
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}