#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//#include <ctype.h>
//#include <stdio.h>
void      my_itoa(int n, char s[]);
//atoi ����������ת��Ϊ������
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
//	if ((sign = n) < 0)//��¼����
//		n = -n;//ʹn��Ϊ����
//	i = 0;
//	do {
//		s[i++] = n % 10 + '0';//ȡ��һ������
//	} while ((n /= 10) > 0);//ɾ��������
//	if (sign < 0)
//		s[i++] = '-';
//	s[i] = '\0';
//	for (j = i; j >= 0; j--)//���ɵ�����������ģ�����Ҫ�������
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