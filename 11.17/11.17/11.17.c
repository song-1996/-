#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int a;
//	printf("�Ƿ�������>1:0?");
//	{
//		scanf("%d", &a);
//	}
//	if (a == 1)
//	{
//		printf("�ú�ѧϰ\n");
//	}
//	else
//		printf("�ؼ�\n");
//
//	system("pause");
//	return 0;
//
//}
//
//int main()
//{
//	int a=0;
//	printf("�Ƿ�������>2:1:0?");
//	{
//		scanf("%d", &a);
//	}
//	if (a == 2)
//	{
//		printf("�ú�ѧϰ\n");
//	}
//	else if (a == 1)
//	{
//		printf("�����з���80\n");
//	}
//	else
//	{
//		printf("�ؼ�\n");
//	}
//
//	system("pause");
//
//
//	return 0;
//}


//int main()
//{
//	int a = 1;
//	if (a)
//		printf("�Ǻ�\n");
//	printf("����\n");
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int a = 1;
//	if (5==a)
//		printf("�Ǻ�\n");
//	else
//	{
//		printf("haha\n");
//	}
//	system("pause");
//	return 0;
//
//}
//
//int main()
//{
//
//	int i;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 0)
//			continue;
//		else
//			printf("%d ", i);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//
//}
//int main()
//{
//	int day=0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("����һ\n");
//		break;
//	case 2:
//		printf("���ڶ�\n");
//		break;
//	case 3:
//		printf("������\n");
//		break;
//	case 4:
//		printf("������\n");
//		break;
//	case 5:
//		printf("������\n");
//		break;
//	case 6:
//		printf("������\n");
//		break;
//	case 7:
//		printf("������\n");
//		break;
//	default:
//		printf("����\n");
//		break;
//	}
//	system("pause");
//	return 0;
////////}
//
//int main()
//{
//	int i=0;
//	while (i < 10)
//	{
//		i++;
//		if (5 == i)
//			continue;
//		printf("%d ", i);
//	}
//
//	system("pause");
//	return 0;
//
//}
//int main()
//{
//		int i = 0;
//		int k = 0;
//		for (i = 0, k = 0;k=0; i++, k++)
//			k++;//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	char ch1[] = "welcome to xian!";
//	char ch2[] = "################";
//	int left = 0;
//	int right = sizeof(ch2) / sizeof(ch2[0])-2;
//
//	while (left<=right)
//	{
//		ch2[left] = ch1[left];
//		ch2[right] = ch1[right];
//		left++;
//		right--;
//		printf("%s\n", ch2);
//	}
//	system("pause");
//	return 0;
//}
//#include<string.h>
//int main()
//{
//	char ch[] = "961126";
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("����������:");
//		scanf("%s", ch);
//		if (strcmp(ch, "961126") == 0)
//		{
//			printf("������ȷ\n");
//			break;
//		}
//		else
//		{
//			printf("�������\n");
//		}
//	}
//	if (i >=3)
//	{
//		printf("����������������˳�����\n");
//	}
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	for (n = 1; n <= 3; n++)
//	{
//		ret = ret * n;
//		sum = sum + ret;
//	}
//	printf("%d ", sum);
//	printf("\n");
//	system("pause");
//	return 0;
//}
int main()
{

	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int mid = 0;
	int key = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] < key)
		{
			left = mid+1;
		}
		else
		if (arr[mid] > key)

		{
			right = mid-1;
		}
		else
		if (arr[mid] == key)
		{
			printf("%d\n ", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("û�ҵ�\n");
	}
	system("pause");
                                                                                                                                                                 	return 0;
}