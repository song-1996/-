#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("***************\n");
	printf("**1.��ʼ��Ϸ***\n");
	printf("**0.�˳���Ϸ***\n");
	printf("***************\n");
}
void game(int n)
{
	int input = 0;
	n = rand() % 100 + 1;
	while (1)
	{
		printf("��������µ�����:");
		scanf("%d", &input);
		if (n > input)
		{
			printf("��С��\n");
		}
		else
			if (n < input)
			{
				printf("�´���\n");
			}
			else
			{
				printf("�¶���\n");
				break;
			}
	}
}
int main()
{
	int n = 0;
	srand((unsigned)time(NULL));
	menu(n);
again:	
	printf("��ѡ��:");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		game(n);
		break;
	case 0:
		break;
	default:
		printf("ѡ�����,������ѡ��\n");
		goto again;
		break;
	}
	system("pause");
	return 0;

}