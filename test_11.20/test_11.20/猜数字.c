#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("************\n");
	printf("** 1.play **\n");
	printf("** 0.exit **\n");
	printf("************\n");
}
void game()
{
	int ret = rand() % 100 + 1;
	int n=0;
	while (1)
	{
		printf("��������µ�����:");
		scanf("%d", &n);
		if (ret > n)
		{
			printf("���С��\n");
		}
		else
			if (ret < n)
			{
				printf("��´���\n");
			}
			else
			{
				printf("��¶���\n");
				break;
			}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do{
		menu();
		printf("��ѡ��>?");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;

}