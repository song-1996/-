#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//strcmp�ַ����Ƚ�

//int my_strcmp(const char* str1, const char* str2)
//{
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}
//int main()
//{
//	char *p1 = "abc";
//	char *p2 = "abh";
//	int ret=my_strcmp(p1, p2);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//
//}

//strncpy�������޵��ַ������ƺ���
//char* my_strncpy(char* dest, const char* src, size_t count)
//{
//	char* ret = dest;
//	while (count)
//	{
//		if (*src == '\0')
//		{
//			*dest = '\0';
//		}
//		*dest++ = *src++;
//		count--;
//	}
//	return ret;
//
//}
//int main()
//{
//	char arr1[20] = {"aaaaaaaa"};
//	char *p = "hello";
//	char* q=my_strncpy(arr1, p,7);
//	printf("%s\n", q);
//	system("pause");
//	return 0;
//}


//strncat�������޵��ַ������Ӻ���

//char* my_strncat(char* dest, const char* src, size_t count)
//{
//	char* ret = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (count)
//	{
//		count--;
//		*dest++ = *src++;
//		if (*src == '\0')
//			break;
//		
//	}
//	*dest = '\0';
//	return ret;
//}
//int main()
//{
//	char a[20] = "abc \0acv";
//	char* p = "world";
//	char* q = my_strncat(a, a, 3);
//	printf("%s\n", q);
//	system("pause");
//	return 0;
//}
//
//strncmp�������޵��ַ����ȽϺ���
//int strncmp(const char* s1, const char* s2, size_t count)
//{
//	while (count && *s1 == *s2)
//	{
//		if (count == 1)
//			return 0;
//		s1++;
//		s2++;
//		count--;
//	}
//	return *s1 - *s2;
//
//}
//int main()
//{
//	char *p = "abcde";
//	char *q = "abc";
//	int ret = strncmp(p, q,5);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//strstr ����ָ���ַ����ַ����е�һ�γ��ֵ�λ��
//char* strchr(const char* src, int c)
//{
//	assert(src);
//	while (*src != '\0')
//	{
//		if(*src== c)
//			return  src;
//		src++;
//	}
//	return NULL;
//}
//int main()
//{
//	char* p = "abcdefc";
//	char* q = strchr(NULL,'q');
//	printf("%s\n",q);
//	system("pause");
//	return 0;
//}

//strstr ��һ���ַ����в����Ӵ���һ�γ��ֵ�λ��
//char* my_strstr(const char* str1, const char* str2)
//{
//	if (*str2 == '\0')
//		return str1;
//	while (*str1 != '\0')
//	{
//		const char* s1 = str1;
//		const char* s2 = str2;
//		while (*str1 == *str2)
//		{
//			str1++;
//			str2++;
//			if (*str2 == '\0')
//				return s1;
//		}
//		str2 = s2;
//		str1 = s1 + 1;
//	}
//	return NULL;
//}
//int main()
//{
//	char* p = "shushushu";
//	char* ret=my_strstr(p, "pk");
//	printf("%s\n", ret);
//	system("pause");
//	return 0;
//}

//memcpy�ڴ濽��
#include<memory.h>
//void* my_memcpy(const void* dest, const void* src, size_t count)
//{
//	const void* ret = dest;
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
//	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int b[] = { 1,1,1,1};
//	my_memcpy(a+2, a, 16);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}


//memmove�ص����ڴ濽��
//void* my_memmove(const void* dest,const void* src, size_t count)
//{
//	const void* ret = dest;
//	while ((dest < src)&&count)
//	{
//		*(char*)dest = *(char*)src;
//		((char*)dest)++;
//		((char*)src)++;
//		count--;
//	}
//	while ((dest > src)&&count)
//	{
//		count--;
//		*(((char*)dest) + count) = *(((char*)src) + count);
//
//	}
//	return ret;
//}
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(a+2, a, 16);
//	system("pause");
//	return 0;
//}

//memset�ڴ�ռ�ĳ�ʼ��
//void* my_memset(void* dest, int c, size_t count)
//{
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
//	int a[5] = { 1,2,3,4,5 };
//	my_memset(a, 6, 20);
//
//	system("pause");
//	return 0;
//}

//memcmp�ڴ�ռ�ıȽ�
//int my_memcmp(const void* buf1, const void* buf2, size_t count)
//{
//	while (count)
//	{
//		while (*(char*)buf1 == *(char*)buf2)
//		{
//			if (count == 1)
//				return 0;
//			((char*)buf1)++;
//			((char*)buf2)++;
//			count--;
//		}
//		return (*(char*)buf1 - *(char*)buf2);
//	}
//}
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int a2[5] = { 1,3,4,5,6 };
//	int ret=my_memcmp(a, a2, 5);
//	printf("%d\n", ret);
//
//	system("pause");
//	return 0;
//}