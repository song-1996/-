#include"SeqList.h"
int main()
{
	SeqList1 s;
	SeqListInit(&s);
	SeqListPushBack(&s,1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	/*int a=SeqListGetFront(&s);*/
	//int a=SeqListGetBack(&s);
	//SeqListEmpty(&s);
	/*int a=SeqListCapacity(&s);*/
	//int a=SeqListSize(&s);
	//SeqListRemove(&s, 3);
	//SeqListMove(&s, 8);
	//int a=SeqListFind(&s, 3);
	/*printf("%d\n", a);*/
	//SeqListPushFront(&s, 0);
	//SeqListPopFront(&s);
	//SeqListPopBack(&s );
	//SeqListInsert(&s, 2, 0);
	//SeqListErase(&s, 2);
	PrintSeqList(&s);
	SeqListDestroy(&s);
	system("pause");
	return 0;

}