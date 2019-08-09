#ifndef __EMP_MANAGE_CARD_H__
#define __EMP_MANAGE_CARD_H__

#define TRUE 1
#define FALSE 0

#define NAME_LEN 30

typedef struct _EmpInfo
{
	char name[NAME_LEN];				//직원 이름
	int empNumber;			//직원 번호
	

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


//초기화
void ListInit(List* plist);

//리스트에 데이터 추가
void LInsert(List* plist, LData data);

void LInsertFront(List* plist, LData data);


//첫번째인지 확인
int LFirst(List* plist, LData* data);

//다음으로 이동
int LNext(List* plist, LData* data);

//리스트에서 데이터 삭제
LData LRemove(List* plist);

//리스트에서 저장된 데이터 수
int LCount(List* plist);

//구조체에 사원 추가
EmpInfo MakeEmpInfo(int num, char* name);

//특근자 조회
void OverTimeSearch(List* list, char* name, int num);

//사원 전체 조회
void ShowEmpInfo(List* plist);

#endif // !__EMP_MANAGE_CARD_H__

