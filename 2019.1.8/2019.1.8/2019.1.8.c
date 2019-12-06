#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//struct Stu
//{
//	char a;//1
//	char b;//1
//	int i;//4
//};
////8
//struct S
//{
//	int x;//4
//	struct Stu s;//8
//	double y;//8
//};
//int main()
//{
//	struct Stu s = { 'x','y',0 };
//	struct S s1 = { 0 };
//	printf("%d\n", sizeof(struct S));//24
//
//	system("pause");
//	return 0;
//
//}

//struct Stu
//{
//	char name[20];
//	int age;
//	char sex;
//};
//int main()
//{
//	struct Stu s[3] = { 0 };
//	printf("%d\n", sizeof(struct Stu [3])/sizeof(struct Stu));
//	system("pause");
//	return 0;
//}
//#include<stddef.h>
//#define my_offsetof(structName,memName)\
//		(int)&((structName*)0)->memName
//struct S
//{
//	int x;//0 1 2 3
//	short y;//4
//};
//int main()
//{
//	struct S s = { 0 };
//	printf("%p\n",  &s);
//	printf("%p\n", &(s.x));
//	printf("%p\n", &(s.y));
//	printf("%d\n",my_offsetof(struct S,x));
//	printf("%d\n", my_offsetof(struct S,y));
//	system("pause");
//	return 0;
//}

//union U
//{
//	char a;
//	int b;
//	double c;
//};
//int main()
//{
//	union U u = { 0 };
//	printf("%p\n", &u.a);
//	printf("%p\n", &u.b);
//	printf("%p\n", &u.c);
//	system("pause");
//	return 0;
//}

//1
//0x 00 00 00 01
//大端 00 00 00 01    
//小端 01 00 00 00
//
//int main()
//{
//	int a = 1;
//	if (*(char*)&a == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	system("pause");
//	return 0;
//}

//union U
//{
//	char a;
//	int b;
//};
//int main()
//{
//	union U u;
//	u.b = 1;
//	if ((int)u.a == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	system("pause");
//	return 0;
//}

//struct S
//{
//	int a : 3;
//	int c : 5;
//	int b : 10;
//	int d : 30;
//};
//int main()
//{
//	struct S s = { 0 };
//	printf("%d\n", sizeof(s));
//	system("pause");
//	return 0;
//}

//第14次作业
#include<string.h>
//void left_rotate(char* str,int n)
//{
//	char start = *str;
//	char* end = str + n - 1;
//	while (str < end)
//	{
//		*str = *(str + 1);
//		str++;
//	}
//	 *str = start;
//}
//void rotate(char* str, int len, int count)
//{
//	while (count)
//	{
//		left_rotate(str, len);
//		count--;
//	}
//}
//int main()
//{
//	char p[] = "ABCD";
//	int len = strlen(p);
//	int n = 0;
//	scanf("%d", &n);
//	rotate(p, len, n);
//	printf("%s\n", p);
//	system("pause");
//	return 0;
//}

#include<assert.h>
//char* left_rotate(char *str, int len)
//{
//
//	char ret = *str;
//	char* start = str;
//	char* end = str + len - 1;
//	while (str < end)
//	{
//		*str = *(str+1);
//		str++;
//	}
//	*str = ret;
//	return start;
//}
//int rotate(char* s1, int len,const char* s2)
//{
//	assert(s1);
//	assert(s2);
//	int n = 4;
//	while (n)
//	{
//		left_rotate(s1, len);
//		if (strcmp(s1, s2) == 0)
//		return 1;
//		n--;
//	}
//	return 0;
//}
//int main()
//{
//	char s1[] = "abcd";
//	char s2[] = "ACBD";
//	int len = strlen(s1);
//	int ret = rotate(s1, len,s2);
//	if ( ret== 1)
//	{
//		printf("是\n");
//	}
//	else
//	{
//		printf("不是\n");
//	}
//	system("pause");
//	return 0;
//}

//第15次作业
//int main()
//{
//	int sum = 0;
//	int p = 0;
//	int p1 = 0;
//	int p2 = 0;
//	int m = 20;
//	while (m)
//	{
//		m--;
//		p1++;
//		p2 = (p1 + p2) / 2;
//		p = p1 + p2;
//		sum = sum + p;
//		p1 = 0;
//		p2 = p;
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	char arr[] = {'a','b','c','d','e'};
//	printf("%d\n", strlen(arr));//err
//	printf("%d\n", strlen(arr + 0));//err
//	printf("%d\n", strlen(*arr));//a
//	printf("%d\n", strlen(arr[1]));//b
//	printf("%d\n", strlen(&arr));//
//	printf("%d\n", strlen(&arr + 1));
//	printf("%d\n", strlen(&arr[0] + 1));
//
//
//	system("pause");
//	return 0;
//}

//int left_move(char* str1, char* str2)
//{
//	char* ret = NULL;
//	int len1 = strlen(str1);
//	int len2 = strlen(str2);
//	strncat(str1, str1, len1);
//	if(len2==len1)
//	ret=strstr(str1, str2);
//	if (ret == NULL)
//	{
//		return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int ret = 0;
//	char arr1[50] = "ABCDEF";
//	char* arr2 = "DEFA";
//	ret=left_move(arr1,arr2);
//	if (ret == 1)
//	{
//		printf("是\n");
//	}
//	else
//	{
//		printf("不是\n");
//	}
//	system("pause");
//	return 0;
//}

//int search(int arr[][3], int* raw, int* col, int key)
//{
//	int x = 0;
//	int y = (*col) - 1;
//	while ((x < (*col)) && (y >= 0))
//	{
//		if (arr[x][y] == key)
//		{
//			(*raw) = x;
//			(*col) = y;
//			return 1;
//		}
//		else
//			if (arr[x][y] > key)
//			{
//				y--;
//			}
//			else
//				x++;
//	}
//	(*raw) = -1;
//	(*col) = -1;
//	return 0;
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int key = 88;
//	int x = 3;
//	int y = 3;
//	if(search(arr, &x, &y, key)==1)
//		printf("找到了%d,%d\n",x,y);
//	else
//		printf("没找到%d,%d\n",x,y);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int ret = 0;
//	int pos = 0;
//	int ret1 = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret = ret ^ arr[i];
//	}
//	for (i = 0; i < 32; i++)
//	{
//		if (((ret >> i)&1) == 1)
//			pos = i;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		if(((arr[i] >> pos) & 1)==1)
//		ret1=ret1^arr[i];
//	}
//	ret = ret ^ ret1;
//	printf("%d %d", ret, ret1);
//	system("pause");
//	return 0;
//}