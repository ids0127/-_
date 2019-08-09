#include <stdio.h>
//#include "EmpManageCard.h"
#include "EmployeeManageStack.h"

//int main(void)
//{
//	// 1. List의 생성, 초기화
//	List list;
//
//	ListInit(&list);
//
//	LInsert(&list, MakeEmpInfo(1, "간석기"));
//	LInsert(&list, MakeEmpInfo(2, "신석기"));
//	LInsert(&list, MakeEmpInfo(3, "구석기"));
//	LInsert(&list, MakeEmpInfo(4, "뗀석기"));
//
//	ShowEmpInfo(&list);
//
//	//OverTimeSearch(&list, "구석기", 3);
//	OverTimeSearch(&list,"뗀석기",5);
//
//	int data;
//
//	return 0;
//}

int main(void)
{
	// Stack의 생성 및 초기화 ///////
	Stack stack;
	StackInit(&stack);

	// 데이터 넣기 ///////
	SPush(&stack, 1);  SPush(&stack, 2);
	SPush(&stack, 3);  SPush(&stack, 4);
	SPush(&stack, 5);

	// 데이터 꺼내기 ///////
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}