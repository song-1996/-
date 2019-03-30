#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{

	////第一种方法
	//int a = 10, b = 20;
	//printf("a=%d b=%d\n", a, b);
	//a = a + b;
	//b = a - b;
	//a = a - b;
	//printf("a=%d b=%d\n", a, b);

	//第二种方法
	//10二进制码01010
	//20二进制码10100
	//  a^b   a=11110
	//  a^b   b=01010
	//  a^b   a=10100
	int a = 10, b = 20;
	printf("a=%d b=%d\n", a, b);
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a=%d b=%d\n", a, b);
	system("pause");
	return 0;
}