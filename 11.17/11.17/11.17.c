#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int a;
//	printf("是否加入比特>1:0?");
//	{
//		scanf("%d", &a);
//	}
//	if (a == 1)
//	{
//		printf("好好学习\n");
//	}
//	else
//		printf("回家\n");
//
//	system("pause");
//	return 0;
//
//}
//
//int main()
//{
//	int a=0;
//	printf("是否加入比特>2:1:0?");
//	{
//		scanf("%d", &a);
//	}
//	if (a == 2)
//	{
//		printf("好好学习\n");
//	}
//	else if (a == 1)
//	{
//		printf("家里有房子80\n");
//	}
//	else
//	{
//		printf("回家\n");
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
//		printf("呵呵\n");
//	printf("哈哈\n");
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int a = 1;
//	if (5==a)
//		printf("呵呵\n");
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
//		printf("星期一\n");
//		break;
//	case 2:
//		printf("星期二\n");
//		break;
//	case 3:
//		printf("星期三\n");
//		break;
//	case 4:
//		printf("星期四\n");
//		break;
//	case 5:
//		printf("星期五\n");
//		break;
//	case 6:
//		printf("星期六\n");
//		break;
//	case 7:
//		printf("星期日\n");
//		break;
//	default:
//		printf("错误\n");
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
//		printf("请输入密码:");
//		scanf("%s", ch);
//		if (strcmp(ch, "961126") == 0)
//		{
//			printf("密码正确\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//	if (i >=3)
//	{
//		printf("三次密码输入错误，退出程序\n");
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
		printf("没找到\n");
	}
	system("pause");
                                                                                                                                                                 	return 0;
}