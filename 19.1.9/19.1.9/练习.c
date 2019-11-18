#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int search_pos(int arr[], int sz,int* pos1,int* pos2)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int target = 14;
//		target = target - arr[i];
//		for (j = 0; j < sz; j++)
//		{
//			if ((target == arr[j]) && (i != j))
//			{
//				*pos1 = i;
//				*pos2 = j;
//				return  1;
//			}
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[] = { 2, 7, 7, 9 };
//	int pos1 = 0;
//	int pos2 = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret=search_pos(arr, sz,&pos1,&pos2);
//	if(ret==1)
//	printf("%d %d\n", pos1, pos2);
//	else
//	printf("Ã»ÕÒµ½\n");
//	system("pause");
//	return 0;
//
//}

//int main()
//{
//
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	int ret = 0;
//	int num = 0;
//	scanf("%d", &n);
//	while (n>0)
//	{
//		ret=n % 10;
//		int m = n;
//		while (m>9)
//		{
//			ret=ret * 10;
//			m=m / 10;
//		}
//		num = num + ret;
//		n=n / 10;
//		
//	}
//	printf("%d\n", num);
//	system("pause");
//	return 0;
//}
#include<string.h>
//int main()
//{
//	/*int i = 10;
//	int *p = (int*)&i;
//	*p = NULL;
//	p = NULL;*/
//	int *p = NULL;
//	printf("%d\n", sizeof(p));
//	printf("%d\n", sizeof(*p));
//	system("pause");
//	return 0;
//}

char* Getmem()
{
	char p[7] = "hello";
	return p;
}
void test()
{
	//char* str = NULL;
	//Getmem(&str);
	//strcpy(str, "hehe");
	//printf("%s\n", str);
	//free(str);
	//str = NULL;
	char *str = NULL;
	str = Getmem();
	printf("%s\n", str);
}
int main()
{	
	test();
	//int num = 5;
	//int i = 0;
	//int* p = (int*)malloc(INT_MAX);
	//if (p != NULL)
	//{
	//	for (i = 0; i < num; i++)
	//	{
	//		*(p + i) = i;
	//	}
	//}
	//free(p);
	//p = NULL;
	/*int i = 5;
	int* p = &i;
	free(p);
	p = NULL;*/
	//int num = 5;
	//int* p = (int *)malloc(num  * sizeof(int));
	//if (p == NULL)
	//{
	//	return 0;
	//}
	//int i = 0;
	//for (i = 0; i < num+3; i++)
	//{
	//	*(p + i) = i + 1;
	//}
	//free(p);
	//p = NULL;
	//int num = 5;
	//int* p = (int *)malloc(num * sizeof(int));
	//if (p == NULL)
	//{
	//	return 0;
	//}
	//int i = 0;
	//for (i = 0; i < num; i++)
	//{
	//	*(p + i) = i + 1;
	//}
	//int *ptr = realloc(p, num * 8000 * sizeof(int));
	//if (ptr == NULL)
	//{
	//	return 0;
	//}
	//p = ptr;
	//free(p);
	//p = NULL;
	//ptr = NULL;
	/*free(p);
	p = NULL;*/
	/*int num = 5;
	int* p = calloc(num, sizeof(int));
	if (p == NULL)
	{
		perror("use malloc");
		return 0;
	}
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%d ", *(p + i));
	}
	free(p);
	p = NULL;*/
	/*int* p = (int*)malloc(10 * sizeof(int));
	int i = 0;
	if (p == NULL)
	{
		perror("use malloc");
		system("pause");
		return 0;
	}
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i + 1;
	}
	free(p);
	p = NULL;*/
	system("pause");
	return 0;
}