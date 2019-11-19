#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
//void meun()
//{
//	printf("***********************\n");
//	printf("*****0.exit 1.paly*****\n");
//	printf("***********************\n");
//}
//void Game()
//{
//	int ret = rand() % 100 + 1;
//	int guess = 0;
//	while (1)
//	{
//		printf("请猜数字->");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("你猜大了\n");
//		}
//		else  if (guess < ret)
//		{
//			printf("你猜小了\n");
//		}
//		else
//		{
//			printf("你猜对了\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int input = 0;
//	do 
//	{
//		meun();
//		printf("请选择->");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，请重新选择\n");
//		}
//	} while (input);
//	system("pause");
//	return 0;
//
//}

//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,3,4,5 };
//	char* p1 = "1234";
//	char*p2 = "1234";
//	if (arr1 == arr2)
//	{
//		printf("hehe\n");
//	}
//	if (p1 == p2)
//	{
//		printf("haha\n");
//	}
//	system("pause");
//	return 0;
//}
//void print(int* arr,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr+i));
//	}
//	printf("\n");
//}
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		int flag = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 1;
//			}
//		}
//	if(flag==0)
//		return;
//	}
//}
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = sz-1; i > 0; i--)
//	{
//		int j = 0;
//		
//		for (j = i-1; j >=0; j--)
//		{
//			if (arr[i] < arr[j])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[i];
//				arr[i] = tmp;
//			}
//		}
//	}
//}
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		int j = 0;
//
//		for (j = i+1; j <sz; j++)
//		{
//			if (arr[i] > arr[j])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[i];
//				arr[i] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr,sz);
//	bubble_sort(arr, sz);
//	print(arr,sz);
//	system("pause");
//	return 0;
//}

//#include<string.h>
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str+1);
//	}
//	else
//		return 0;
//}
//int main()
//{
//	printf("%d\n", my_strlen("00000"));
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* p = &a;
//	char* *pp = (char**)&p;
//	printf("%p\n", pp);
//	printf("%p\n", pp + 1);
//	system("pause");
//	return 0;
//}
//#include<assert.h>
//int main()
//{
//	int* p=NULL;
//	assert(p);
//		*p = 20;
//	printf("%d\n", *p);
//	system("pause");
//	return 0;
//}
//void menu()
//{
//	printf("********************\n");
//	printf("*** 1.Add  2.Sub ***\n");
//	printf("*** 3.Mul  4.Div ***\n");
//	printf("*** 0.exit       ***\n");
//	printf("********************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//void calc(int(*pf)(int, int))
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入两个数->");
//	scanf("%d%d", &a, &b);
//	printf("%d\n",pf(a, b));
//}
//int main()
//{
//	int input = 0;
//	do 
//	{
//		menu();
//		printf("请选择->");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calc(Add);
//			break;
//		case 2:
//			calc(Sub);
//			break;
//		case 3:
//			calc(Mul);
//			break;
//		case 4:
//			calc(Div);
//			break;
//		case 0:
//			printf("退出程序!\n");
//				break;
//		default:
//			printf("选择错误\n");
//			break;
//		} 
//	} while (input);
//	system("pause");
//	return 0;
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
//void swap(char* buf1, char* buf2, size_t width)
//{
//	size_t i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//void bubble_sort(void* base, size_t sz,size_t width, int(*cmp)(const void *e1, const void *e2))
//{
//	size_t i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		size_t j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)base+j*width,(char*)base+(j+1)*width)>0)
//			{
//				swap((char*)base + j * width, (char*)base + (j + 1)*width, width);
//			}
//		}
//	}
//}
//
////void qsort(void *base, 
////	size_t num, 
////	size_t width,
////	int(*cmp)(const void *e1, const void *e2));
//
//int cmp_int(const void*e1, const void*e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//struct S
//{
//	char name[20];
//	int age;
//};
//int cmp_by_name(const void*e1, const void*e2)
//{
//	return strcmp(((struct S*)e1)->name, ((struct S*)e2)->name);
//}
//int cmp_by_age(const void*e1, const void*e2)
//{
//	return (((struct S*)e1)->age - ((struct S*)e2)->age);
//}
//void test2()
//{
//	struct S s[3] = { {"zhangsan",20},{"lisi",40},{"wangwu",15} };
//	int sz = sizeof(s)/sizeof(s[0]);
//	/*qsort(s, sz, sizeof(s[0]), cmp_by_age);*/
//	bubble_sort(s, sz, sizeof(s[0]), cmp_by_age);
//}
//int main()
//{
	//int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//print(arr, sz);
	//bubble_sort(arr, sz);
	//print(arr, sz);
//	test2();
//	system("pause");
//	return 0;
//}
#include<assert.h>
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest);
//	assert(src);
//	char* ret = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "abcde";
//	char* arr2 = "123";
//	printf("%s\n", my_strcat(arr1, arr2));
//	system("pause");
//	return 0;
//}
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1);
//	assert(str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}
//int main()
//{
//	char* arr1 = "aa";
//	char* arr2 = "aa";
//	printf("%d\n", my_strcmp(arr1, arr2));
//	system("pause");
//	return 0;
//}
//char* my_strncpy(char* dest, const char* src,int count)
//{
//	assert(dest);
//	assert(src);
//	char* ret = dest;
//	while (count)
//	{
//		if (*src == '\0')
//		{
//			*dest = '\0';
//		}
//		else
//		{
//			*dest = *src;
//			src++;
//		}
//		dest++;
//		count--;
//	}
//	return ret;
//}
//int main()
//{
//	char arr[20] = "aaaaaaa";
//	char* arr1 = "hel";
//	printf("%s\n", my_strncpy(arr, arr1, 3));
//	system("pause");
//	return 0;
//}
//char* my_strncat(char* dest, const char* src, int count)
//{
//	assert(dest);
//	assert(src);
//	char* ret = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (count)
//	{
//		if (*src == '\0')
//		{
//			break;
//		}
//		*dest = *src;
//		dest++;
//		src++;
//		count--;
//	}
//	*dest = '\0';
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "abc\0aaaaa\0fff";
//	char* arr2 = "def";
//	printf("%s\n", my_strncat(arr1, arr2, 6));
//	system("pause");
//	return 0;
//}
//int my_strncmp(const char* str1, const char* str2, int count)
//{
//	assert(str1);
//	assert(str2);
//	while (*str1 == *str2&&count)
//	{
//		if (*str1 == '\0')
//		{
//			break;
//		}
//		str1++;
//		str2++;
//		count--;
//	}
//	return *str1 - *str2;
//}
//int main()
//{
//	char* arr1 = "abr";
//	char* arr2 = "ab";
//	printf("%d\n", my_strncmp(arr1, arr2, 5));
//	system("pause");
//	return 0;
//}

#include<stdio.h>
void foo(const char** p)
{

}
int main()
{
	char* c = "abc";
	char** s= &c;
	const char** s1 = s;
	foo(s);
	system("pause");
	return 0;
}