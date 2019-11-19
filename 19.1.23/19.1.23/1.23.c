#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//#include <ctype.h>
//#include <stdio.h>
void      my_itoa(int n, char s[]);
//atoi 函数：将ｓ转换为整形数
//int main(void)
//{
//	int n;
//	char s[100];
//	printf("Input n:\n");
//	scanf("%d", &n);
//	printf("the string : \n");
//	my_itoa(n, s);
//	system("pause");
//	return 0;
//}
//void my_itoa(int n, char s[])
//{
//	int i, j, sign;
//	if ((sign = n) < 0)//记录符号
//		n = -n;//使n成为正数
//	i = 0;
//	do {
//		s[i++] = n % 10 + '0';//取下一个数字
//	} while ((n /= 10) > 0);//删除该数字
//	if (sign < 0)
//		s[i++] = '-';
//	s[i] = '\0';
//	for (j = i; j >= 0; j--)//生成的数字是逆序的，所以要逆序输出
//		printf("%c", s[j]);
//}
void my_itoa(int n, char str[])
{
	int sign, i=0, j=0;
	if ((sign = n) < 0)
		n = -n;
	while (n)
	{
		str[i] = n % 10 + '0';
		i++;
		n = n / 10;
	}
	if (sign < 0)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	for (j = i; j >= 0; j--)
	{
		printf("%c", str[j]);
	}
}
int main()
{
	int a = -324;
	char arr[100];
	my_itoa(a, arr);
	system("pause");
	return 0;

}