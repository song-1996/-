#define _CRT_SECURE_NO_WARNINGS 1
#include"2019.4.27.hpp"



int main()
{
	int arr[] = { 1,2,3,4,5 };
	mylist::List<int> l1;
	l1.ListPushBack(-1);
	l1.ListPushBack(5);
	l1.ListPushBack(3);
	l1.ListPushBack(4);
	l1.ListPushBack(0);
	l1.insertionSortList(l1.Get_Head());
	return 0;
}