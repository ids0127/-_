#include <stdio.h>
#include "EmpManageCard.h"

int main(void)
{
	// 1. List의 생성, 초기화
	List list;

	ListInit(&list);

	LInsert(&list, MakeEmpInfo(1, "간석기"));
	LInsert(&list, MakeEmpInfo(2, "신석기"));
	LInsert(&list, MakeEmpInfo(3, "구석기"));
	LInsert(&list, MakeEmpInfo(4, "뗀석기"));

	ShowEmpInfo(&list);

	//OverTimeSearch(&list, "구석기", 3);
	OverTimeSearch(&list,"뗀석기",5);

	int data;

	return 0;
}