#include"ListNode.h"
int main()
{
	ListNode* l;
	InitListNode(&l);
	PushBack(&l, 1);
	PushBack(&l, 2);
	PushBack(&l, 3);
	PushBack(&l, 4);
	swapPairs(&l);
	system("pause");
	return 0;

}