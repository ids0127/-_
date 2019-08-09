#ifndef _C_LINKED_LIST_STACK_H_
#define _C_LINKED_LIST_STACK_H_

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

typedef struct _cLinkedListStack
{
	Node* top;
	Node* tail;

}CLinkedListStack;

typedef CLinkedListStack Stack;

//Stack �ʱ�ȭ
void StackInit(Stack* pstack);

//Stack�� ������ �Է�(push)
void SPush(Stack* pstack, Data data);

//Stack���� ������ ���(pop)
Data SPop(Stack* pstack);

//Stack�� ����ִ��� Ȯ��(IsEmpty)
int SIsEmpty(Stack* pstack);

#endif // ! _C_LINKED_LIST_STACK_H_

