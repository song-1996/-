#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//char* my_strchr(const char* str, int c)
//{
//	assert(str);
//	while (*str != '\0')
//	{
//		if (*str == c)
//		{
//			return (char*)str;
//		}
//		str++;
//	}
//	if (*str == c)
//		return (char*)str;
//	return NULL;
//}
//int main()
//{
//	char* arr = "abcd";
//	char* ret=my_strchr(arr, '\0');
//	if (ret != NULL)
//	{
//		printf("%s\n", ret);
//	}
//	else
//	{
//		printf("找不到\n");
//	}
//	system("pause");
//	return 0;
//
//}
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1);
//	assert(str2);
//	const char* cur = str1;
//	const char* s2 = str2;
//	while (*cur)
//	{
//		const char* s1 = cur;
//		s2 = str2;
//		while (*s1 && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)cur;
//		}
//		cur++;
//	}
//	return NULL;
//}
//int main()
//{
//	char* arr = "abbbaaaaadddddc";
//	char* ret=strstr(arr, " ");
//	if (ret != NULL)
//	{
//		printf("%s\n", ret);
//	}
//	else
//	{
//		printf("找不到\n");
//	}
//	system("pause");
//	return 0;
//}

//void* my_memcpy(void* dest, const void* src, int count)
//{
//	assert(dest);
//	assert(src);
//	void* ret = dest;
//	while (count)
//	{
//		*(char*)dest = *(char*)src;
//		((char*)dest)++;
//		((char*)src)++;
//		count--;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
//	int arr2[10] = { 0 };
//	my_memcpy(arr2, arr1,20);
//	system("pause");
//	return 0;
//}
//void* my_memmove(void* dest, const void* src, int count)
//{
//	assert(dest);
//	assert(src);
//	void* ret = dest;
//	if(dest < src)
//	{
//		while (count)
//		{
//			*(char*)dest = *(char*)src;
//			((char*)dest)++;
//			((char*)src)++;
//			count--;
//		}
//	}
//	else
//	{
//		while (count)
//		{
//			count--;
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr , arr+2, 16);
//	system("pause");
//	return 0;
//}
//void* my_memset(void* dest, int c, size_t count)
//{
//	assert(dest);
//	void* ret = dest;
//	while (count)
//	{
//		*(char*)dest = c;
//		((char*)dest)++;
//		count--;
//	}
//	return ret;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
//	my_memset(arr,0,40);
//	system("pause");
//	return 0;
//}
//int my_memcmp(const void* str1, const void* str2, int count)
//{
//	assert(str1);
//	assert(str2);
//	while (*(char*)str1 == *(char*)str2 && count)
//	{
//		((char*)str1)++;
//		((char*)str2)++;
//		count--;
//		if (count == 0)
//			return 0;
//	}
//	return *(char*)str1 - *(char*)str2;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4 };
//	int arr2[] = { 1,2,3 };
//	int ret = my_memcmp(arr1, arr2, 16);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//itoa的实现
//char* my_itoa(int a, char* str)
//{
//	assert(str);
//	int p = 0;
//	int b = 0;
//	char* ret = str;
//	if (a < 0)
//	{
//		*str++ = '-';
//		 a = -a;
//	}
//	b = a;
//	for (p = 1; b >= 10; b /= 10)
//	{
//		p = p * 10;
//	}
//	while (p > 0)
//	{
//		*str++ = '0' + a / p;
//		a = a % p;
//		p=p / 10;
//	}
//	*str = '\0';
//	return ret;
//}
//int main()
//{
//	int a = -1000;
//	char s[20];
//	char* ret=my_itoa(a, s);
//	printf("%s\n", ret);
//	system("pause");
//	return 0;
//}


#include<stddef.h>
struct tap
{
	char a;
	int b;
	double c;
	int d;
};
#define my_offsetof(StructName,MemName) \
		//(int)&(((StructName*)0)->MemName)
int main()
{
	struct tap t = {0};
	printf("%p\n", &t.a);
	printf("%d\n", (&t.b-&t.a));
	printf("%p\n", &t.c);
	printf("%p\n", &t.d);
	//printf("%d\n", my_offsetof(struct tap,a));
	//printf("%d\n", my_offsetof(struct tap,b));
	//printf("%d\n", my_offsetof(struct tap,c));
	//printf("%d\n", my_offsetof(struct tap,d));
	system("pause");
	return 0;
}