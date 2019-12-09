#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//typedef struct Stu 
//{
//	char name[20];
//	int age;
//	char sex[20];
//} *ss;
//
//print1(ss ps)
//{
//	printf("%s\n", ps->name);
//	printf("%d\n", ps->age);
//	printf("%s\n", ps->sex);
//}
//print2(ss *ps)
//{
//	printf("%s\n", (*ps)->name);
//	printf("%d\n", (*ps)->age);
//	printf("%s\n", (*ps)->sex);
//}
//int main()
//{
//	char k;
//	ss s=&k;
//	strcpy(s->name,"zhangsan");
//	s->age = 20;
//	strcpy(s->sex,"M");
//	print1(s);
//	print2(&s);
//	system("pause");
//	return 0;
//
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int *p = arr;
//	for (i = 0; i < sz; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p+i));
//	}
//	system("pause");
//	return 0;
//}

//int my_strlen1(char *str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int my_strlen2(char *str)
//{
//	char* str1 = str;
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return (str - str1);
//}
//int my_strlen3(char *str)
//{
//	if (*str != '\0')
//	{
//		return 1+ my_strlen2(str+1);
//	}
//	else
//		return 0;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", my_strlen1(arr));
//	printf("%d\n", my_strlen2(arr));
//	printf("%d\n", my_strlen3(arr));
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int i = 0;
//	int* arr[3] = { arr1,arr2,arr3 };
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(arr[i] + j));
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}

//struct Bir
//{
//	int year;
//	int month;
//	int day;
//};
//struct Stu
//{
//	char name[20];
//	struct Bir ss;
//};
//int main()
//{
//	struct Stu s = { "zhangsan",{1997,11,26} };
//	printf("%s\n%d %d %d\n", s.name, s.ss.year, s.ss.month, s.ss.day);
//	system("pause");
//	return 0;
//}