#include"heap.h"
//void test()
//{
//	Heap hp;
//	int arr[] = { 5,4,6,7,10,3,2,11,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	CreatHeap(&hp, arr, sz, Less);
//	Print(&hp);
//	InsertHeap(&hp, 1);
//	printf("Size=%d Empty=%d\n", SizeHeap(&hp), EmptyHeap(&hp));
//	Print(&hp);
//	SortHeap(&hp);
//	Print(&hp);
//	DestroyHeap(&hp);
//
//}
void test1()
{
	Heap hp;
	int arr[] = { 5,4,6,7,10,3,2,11,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	CreatHeap(&hp, arr, sz, Greater);
	Print(&hp);
	InsertHeap(&hp, 1);
	InsertHeap(&hp, 12);
	Print(&hp);
	EraseHeap(&hp);
	Print(&hp);
}
int main()
{
	/*test();*/
	test1();
	system("pause");
	return 0;

}