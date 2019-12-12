#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//typedef struct S
//{
//	int age;
//	char name[];
//}S;

//typedef struct Stu
//{
//	int a;
//	int* b;
//}Stu;
//typedef struct S
//{
//	char name[20];
//	int age;
//	float a;
//}S;
//int main()
//{
//	int c = 0;
//	FILE* p = fopen("test.txt", "r");
//	if (p == NULL)
//	{
//		return 0;
//	}
//	while ((c = getc(p)) != EOF)
//	{
//		printf("%c ", c);
//	}
//	if (ferror(p))
//	{
//		printf("error\n");
//	}
//	else if (feof(p))
//	{
//		printf("success end\n");
//	}
//	fclose(p);
//	p = NULL;
	/*char a[10] = "abcdef";
	FILE* p = fopen("test.txt", "r");
	if (p == NULL)
	{
		return 0;
	}
	printf("%c\n",fgetc(p));
	printf("%c\n", fgetc(p));
	long int b = ftell(p);
	fseek(p, b, SEEK_CUR);
	printf("%c\n", fgetc(p));
	printf("%c\n", fgetc(p));
	printf("%ld\n", b);
	fclose(p);
	p = NULL;*/
	/*S s = {"zhangsan",20,3.14};
	char a[10] = {0};
	char b[10] = { 0 };
	FILE* p = fopen("test.txt", "w");
	if (p == NULL)
	{
		return 0;
	}*/
	//sprintf(a, "%s %d %f", s.name, s.age, s.a);
	//sscanf(b, "%s", &a);
	//printf("%s",a);
	/*sscanf(p, "%s %d %f", s.name, &s.age, &s.a);
	printf("%s %d %f", s.name, s.age, s.a);*/
	//char *sp=fgets(a, 8, p);
	//char *sp1 = fgets(a, 8, p);
	//printf("%s", a);
	//printf("%s", sp);
	//printf("%s", sp1);
	//fclose(p);
	//p = NULL;
	//char a[10] = { 0 };
	//int ch = 0;
	//printf("ÇëÊäÈëÃÜÂë:>");
	//scanf("%s", a);
	//printf("ÇëÑ¡Ôñ(Y/N):>");
	//while (getchar() != '\n')
	//{
	//	;
	//}
	//	ch = getchar();

	//	if (ch == 'Y')
	//	{
	//		printf("yes");
	//	}
	//	else
	//		printf("no");
	//int a = 10000;
	//FILE* pf = fopen("F:\\cÓïÑÔ\\Á·Ï°\\2019.1.11\\2019.1.11\\test.txt", "r");
	//if (pf == NULL)
	//{
	//	perror("fopen");
	//	return 0;
	//	system("pause");
	//}
	//fwrite(&a, 4, 1, pf);
	//fclose(pf);
	//pf = NULL;
	/*int i = 0;
	Stu *s = (Stu*)malloc(sizeof(Stu));
	if (s == NULL)
	{
		return 0;
	}
	s->a = 10;
	s->b = (int *)malloc(sizeof(int)*(s->a));
	if (s->b == NULL)
	{
		return 0;
	}
	for (i = 0; i < s->a; i++)
	{
		*(s->b + i) = i + 1;
	}
	free(s->b);
	s->b = NULL;	
	free(s);
	s = NULL;*/
	//printf("%d\n", sizeof(Stu));
	//Stu* s = (Stu*)malloc(sizeof(Stu));
	/*int i = 0;
	S *ptr = (S*)malloc(sizeof(S) + 10*sizeof(char));
	if (ptr == NULL)
	{
		return 0;
	}
	ptr->age = 10;
	for (i = 0; i < ptr->age; i++)
	{
		ptr->name[i] = 'a';
	}
	S* s = (S*)realloc(ptr, sizeof(S) + 20 * sizeof(char));
	if (s == NULL)
	{
		return 0;
	}
	ptr = s;
	for (i = 0; i < ptr->age; i++)
	{
		ptr->name[i] = 'b';
	}
	free(ptr);
	ptr = NULL;*/
	/*struct S s;
	printf("%d\n", sizeof(s));*/
//	system("pause");
//	return 0;
//
//}
//void swap(char* e1, char* e2,size_t width)
//{
//	size_t i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *e1;
//		*e1 = *e2;
//		*e2 = tmp;
//		e1++;
//		e2++;
//	}
//}
//void bubble_qsort(void* base,size_t num,size_t width,
//					int (*cmp)(const void*e1,const void*e2) )
//{
//	size_t i = 0;
//	for (i = 0; i < num - 1; i++)
//	{
//		size_t j = 0;
//		for (j = 0; j < num - 1 - i; j++)
//		{
//			if (cmp((char*)base+j*width,(char*)base+(j+1)*width)>0)
//			{
//				swap((char*)base + j * width, (char*)base + (j + 1)*width,width);
//			}
//		}
//		
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
//int cmp(const void* e1, const void* e2)
//{
//	return (*((int*)e1) - *((int*)e2));
//}
//int main()
//{
//	int arr[] = { 0,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	bubble_qsort(arr, sz,sizeof(arr[0]),cmp);
//	print(arr, sz);
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	char arr[100][20] = { 0 };
//	int i = 0;
//	int input_n = 0;
//	scanf("%d", &input_n);
//	for (i = 0; i < input_n;i++)
//	{
//		scanf("%s",arr[i]);
//	}
//	for (i = 0; i < input_n; i++)
//	{
//		printf("%s\n", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//#include<string.h>
//int isValid(char *arr)
//{
//	if (*arr == ' ');
//	return 1;
//	int len = strlen(arr);
//	char* end = arr + len - 1;
//	while (arr < end)
//	{
//		if ((*arr=='{'&&*end=='}')||
//			(*arr == '('&&*end == ')')||
//			(*arr == '['&&*end == ']'))
//		{
//			arr++;
//			end--;
//			if (arr > end)
//				return 1;
//		}
//		else
//			if ((*arr=='{'&&*arr+1=='}')||
//				(*arr == '('&&*arr + 1 == ')')||
//				(*arr == '['&&*arr + 1 == ']'))
//			{
//				arr += 2;
//				if (arr > end)
//					return 1;
//			}
//			else
//				return 0;
//	}
//}
//int main()
//{
//	char arr[] = { 0 };
//	scanf("%s", arr);
//	if (isValid(arr) == 1)
//	{
//		printf("true\n");
//	}
//	else
//		printf("false\n");
//	system("pause");
//	return 0;
//}
//int removeDuplicates(int* nums, int numsSize)
//{
//	if (numsSize == 0)
//		return 0;
//	int i = 0;
//	for (int j = 0; j < numsSize; j++)
//	{
//		if (nums[i] != nums[j])
//		{
//			i++;
//			nums[i] = nums[j];
//		}
//	}
//	return i + 1;
//}


//int main()
//{
//	int arr[] = { 0,0,1,1,1,2,2,3,3,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret=removeDuplicates(arr, sz);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//int searchInsert(int arr[], int sz, int key)
//{
//	int left = 0;
//	int right = sz - 1;
//	int mid =0;
//	while (left <= right)
//	{
//		mid = left + (right - left) / 2;
//		if (arr[mid] == key)
//		{
//			return mid;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			right = mid - 1;
//		}
//	}
//	return left;
//}
//int main()
//{
//	int arr[] = { 1,3,5,6 };
//	int key = 2;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n",searchInsert(arr, sz, key));
//	system("pause");
//	return 0;
//}


int main()
{
	int i = -20;
	unsigned int j = 10;
	printf("%d\n", i + j);
	/*
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));*/
	system("pause");
	return 0;
}