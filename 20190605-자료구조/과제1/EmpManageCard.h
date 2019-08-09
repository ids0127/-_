#ifndef __EMP_MANAGE_CARD_H__
#define __EMP_MANAGE_CARD_H__

#define TRUE 1
#define FALSE 0

#define NAME_LEN 30

typedef struct _EmpInfo
{
	char name[NAME_LEN];				//���� �̸�
	int empNumber;			//���� ��ȣ
	

}EmpInfo;

typedef EmpInfo LData;

typedef struct _node
{
	LData data;
	struct _node* next;
}Node;

typedef struct _CLL
{
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
}CList;

typedef CList List;


//�ʱ�ȭ
void ListInit(List* plist);

//����Ʈ�� ������ �߰�
void LInsert(List* plist, LData data);

void LInsertFront(List* plist, LData data);


//ù��°���� Ȯ��
int LFirst(List* plist, LData* data);

//�������� �̵�
int LNext(List* plist, LData* data);

//����Ʈ���� ������ ����
LData LRemove(List* plist);

//����Ʈ���� ����� ������ ��
int LCount(List* plist);

//����ü�� ��� �߰�
EmpInfo MakeEmpInfo(int num, char* name);

//Ư���� ��ȸ
void OverTimeSearch(List* list, char* name, int num);

//��� ��ü ��ȸ
void ShowEmpInfo(List* plist);

#endif // !__EMP_MANAGE_CARD_H__

