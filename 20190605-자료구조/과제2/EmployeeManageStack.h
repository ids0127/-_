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

//Stack 초기화
void StackInit(Stack* pstack);

//Stack에 데이터 입력(push)
void SPush(Stack* pstack, Data data);

//Stack에서 데이터 출력(pop)
Data SPop(Stack* pstack);

//Stack이 비어있는지 확인(IsEmpty)
int SIsEmpty(Stack* pstack);

#endif // ! _C_LINKED_LIST_STACK_H_

