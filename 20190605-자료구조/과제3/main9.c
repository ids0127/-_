
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
					printf("주문번호 %d : 빅맥버거\n", orderNum++);
					break;

				case Bulgogi:
					printf("주문번호 %d : 불고기버거\n", orderNum++);
					break;

				case Cheese:
					printf("주문번호 %d : 치즈버거\n", orderNum++);
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
					puts("빅맥버거 완성\n");
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
					puts("불고기버거 완성\n");
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
					puts("치즈버거 완성\n");
					cheeseMakingCnt = 0;
				}
				break;
			}
		}
	}

	puts("\n[ 결과 ]");
	printf("총 주문고객수 : %d\n", numOfCus);
	printf("남은 점심시간 : %d초\n", lunchTime);
	printf("남은 점심시간 : %.2lf분\n", (double)(lunchTime / 60.0));
	printf("처리된 주문 : %d", count);

	return 0;
}