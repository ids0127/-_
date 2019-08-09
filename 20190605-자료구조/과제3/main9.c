
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "QLinkedList-1.h"

enum Burger
{
	Cheese = 1, Bulgogi, Bigmag
};

int main(void)
{
	QUEUE queue;
	Employee employee;
	int lunchTime = 3600;
	int count = 0;
	int numOfCus = 0;

	InitEmp(&employee);
	InitQ(&queue);

	srand((unsigned)time(NULL));
	int time = -1;

	int cheeseMakingCnt = 0;
	int bigmagMakingCnt = 0;
	int bulgogiMakingCnt = 0;

	for (int i = 0; i < 3600; i++)
	{
		if (lunchTime <= 0)
			break;

		time = (i % 15);

		if (time == 0)
		{
			EnQueue(&queue, (rand() % 3 + 1));
			numOfCus++;

			Node* cur = queue.front->next;

			int orderNum = numOfCus;
			while (!IsEmptyQ(&queue))
			{				
				switch (cur->data)
				{
				case Bigmag:
					printf("�ֹ���ȣ %d : ��ƹ���\n", orderNum++);
					break;

				case Bulgogi:
					printf("�ֹ���ȣ %d : �Ұ�����\n", orderNum++);
					break;

				case Cheese:
					printf("�ֹ���ȣ %d : ġ�����\n", orderNum++);
					break;
				}

				cur = cur->next;

				if (cur->next == queue.front)
					break;
			}
			puts("");
		}
		
		lunchTime--;		

		Sleep(100);

		if (!IsEmptyQ(&queue))
		{
			switch (queue.front->next->data)
			{
			case Bigmag:
				bigmagMakingCnt++;

				if (bigmagMakingCnt == employee.bigmag)
				{
					DeQueue(&queue);
					if (lunchTime >= 0)
						count++;
					puts("��ƹ��� �ϼ�\n");
					bigmagMakingCnt = 0;
				}
				break;

			case Bulgogi:
				bulgogiMakingCnt++;

				if (bulgogiMakingCnt == employee.bulgogi)
				{
					DeQueue(&queue);
					if (lunchTime >= 0)
						count++;
					puts("�Ұ����� �ϼ�\n");
					bulgogiMakingCnt = 0;
				}
				break;

			case Cheese:
				cheeseMakingCnt++;

				if (cheeseMakingCnt == employee.cheese)
				{
					DeQueue(&queue);
					if (lunchTime >= 0)
						count++;
					puts("ġ����� �ϼ�\n");
					cheeseMakingCnt = 0;
				}
				break;
			}
		}
	}

	puts("\n[ ��� ]");
	printf("�� �ֹ����� : %d\n", numOfCus);
	printf("���� ���ɽð� : %d��\n", lunchTime);
	printf("���� ���ɽð� : %.2lf��\n", (double)(lunchTime / 60.0));
	printf("ó���� �ֹ� : %d", count);

	return 0;
}