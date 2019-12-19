#include"ListNode.h"
int main()
{
	ListNode* l;
	InitListNode(&l);
	PushBack(&l, 1);
	PushBack(&l, 2);
	PushBack(&l, 3);
	PushBack(&l, 4);
	PushBack(&l, 5);
	PushBack(&l, 6);
	PushBack(&l, 7);
	PushBack(&l, 8);
	PushBack(&l, 9);
	EntryNodeOfLoop(l);
	DestroyListNode(&l);
	system("pause");
	return 0;

}