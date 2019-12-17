#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j =0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	bubble_sort(arr, sz);
//	print(arr, sz);
//	system("pause");
//	return 0;
//
//}

//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j =0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int *)e1 - *(int *)e2;
//}
//struct Stu
//{
//	char name[20];
//	int age;
//};
//int cmp_name(const void* e1, const void* e2)
//{
//	return  strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//int cmp_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age-((struct Stu*)e2)->age;
//}
//void print()
//{
//	struct Stu arr[3] = { {"zhangsan",20},{"lisi",19},{"wangwu",23} };
//	qsort(arr, 3, sizeof(struct Stu), cmp_name);
//	qsort(arr, 3, sizeof(struct Stu), cmp_age);
//}
//int main()
//{
//	/*int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);*/
//	//bubble_sort(arr, sz);
//	/*qsort(arr, sz, 4, cmp_name);*/
//	print();
//	system("pause");
//	return 0;
//
//}


//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int sum = 0;
//	int a = 3;
//	int b = 4;
//	int(*p)(int, int) = Add;
//	sum=p(a, b);
//	//sum=Add(a, b);
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	char* p = "abcd";
//	char* q = "abcc";
//	printf("%d\n", strcmp(p, q));
//	system("pause");
//	return 0;
//}

//void qsort(void *base, 
//			 size_t num,
//			 size_t width, 
//			 int( *compare)(const void *e1, const void *e2));


int cmp_int(const void* e1, const void* e2)
{
	return *(int *)e1 - *(int *)e2;
}

void swap(char *buf1,char *buf2, size_t width )
{
	size_t i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void qbubble_sort(void *base, size_t sz,size_t width,int (*cmp)(const void *e1,const void *e2))
{
	size_t i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		size_t j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base+j*width,(char*)base+(j+1)*width)>0)
			{
				swap((char*)base + j * width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	qbubble_sort(arr, sz,4, cmp_int);
	print(arr, sz);
	system("pause");
	return 0;

}