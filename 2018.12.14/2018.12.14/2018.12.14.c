#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832

//int main()
//{
//	int a = 25;
//	int i = 0;
//	long long sum = 0;
//	while (i < 32)
//	{
//		int j;
//		long long p = a & 1;
//		if (p != 0)
//		{
//			for (j = 31 - i; j > 0; j--)
//			{
//				p = p * 2;
//			}
//			sum = sum + p;
//		}
//		a=a >> 1;
//		i++;
//	}
//	printf("%lld ", sum);
//	system("pause");
//	return 0;
//
//}

//��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��

//int add(int x, int y)//������ʵ�ּӷ��ĺ���
//{
//	int tmp = 0;
//	do
//	{
//		tmp = x ^ y;
//		y = x & y;
//		x = tmp;
//		y <<= 1;//��λ
//	} while (y != 0);
//	return x;
//}
//
//int avg(int x, int y)//��������ƽ��ֵ�ĺ���
//{
//	return add(((x^y) >> 1), x&y);
//}
//
//int main()//������
//{
//	int a = 0;
//	int b = 0;
//	printf("Input two number:");
//	scanf("%d%d", &a, &b);
//	printf("%d\n", avg(a, b));
//	system("pause");
//	return 0;
//
//}

//���ʵ�֣� 
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩

//int main()
//{
//	int arr[5] = { 1,1,2,3,2 };
//	int i = 0;
//	int sum = arr[0];
//	for (i = 1; i < 5; i++)
//	{
//		sum = sum ^ arr[i];
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}


//��һ���ַ����������Ϊ:"student a am i",
//	���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����
//	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���


//int main()
//{
//	char arr[] = "student a am i";
//	int right = sizeof(arr) / sizeof(arr[0])-2;
//	int left = 0;
//	while (left <= right)
//	{
//		char tmp=0;
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//	int i=0;
//	int len = sizeof(arr) / sizeof(arr[0]) - 2;
//	while (i <= len)
//	{
//		if (arr[i] != ' ')
//		{
//			left = i;
//			while (arr[i] && arr[i] != ' ')
//			{
//				i++;
//			}
//			right = i-1;
//		}
//		char tmp = 0;
//		while (left <= right)
//		{
//			char tmp = 0;
//			tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//			left++;
//			right--;
//		}
//		i++;
//	}
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}