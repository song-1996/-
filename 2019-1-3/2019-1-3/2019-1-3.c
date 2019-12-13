#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//字符串的复制
//char* my_strcpy( char* str2, const char* str1)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	char* ret = str1;
//	while (*str2++ = *str1++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = { 0 };
//	char* c=my_strcpy(arr2, arr1);
//	printf("%s\n",c);
//	system("pause");
//	return 0;
//
//}

//字符串的长度
//int my_strlen(const char *str)
//{
//	assert(str != NULL);
//	const char* str1 = str;
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return  str - str1;
//}
//int main()
//{
//	char *a = "abcdef";
//	printf("%d\n",my_strlen(a));
//	system("pause");
//	return 0;
//}

//字符串的连接
//char* my_strcat(char* a, const char* b)
//{
//	assert(a!= NULL);
//	assert(b!= NULL);
//	char* ret = a;
//	while (*a != '\0')
//	{
//		a++;
//	}
//	while (*a++ = *b++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char a[] = "abcdef";
//	char* b = "china";
//	char* c=my_strcat(a, b);
//	printf("%s\n",c);
//	system("pause");
//	return 0;
//}

//字符串的比较
//int my_strcmp(char* a, char* b)
//{
//	while ((*a) != '\0')
//	{
//		while ((*b) != '\0')
//		{
//			if (*a - *b == 0)
//			{
//				a++;
//				b++;
//				if (*a == '\0'&&*b == '\0')
//					return 0;
//				break;
//			}
//			if (*a - *b > 0)
//			{
//				return 1;
//			}
//			else
//				return -1;
//		}
//		if (b == '\0')
//			return 1;
//	}
//	if (b != '\0')
//		return -1;
//}
//int main()
//{
//	char a[] = "abcrdskmskjqjdwjdn";
//	char b[] = "abcze";
//	printf("%d\n", my_strcmp(a, b));
//	system("pause");
//	return 0;
//}