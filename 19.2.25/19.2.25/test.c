#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int cmp_int(const void*e1, const void* e2)
//{
//	return (*(int*)e1 - *(int*)e2);
//}
//void merge(int* nums1, int m, int* nums2, int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = m; i < m + n; i++)
//	{
//		if (nums2[j] != 0)
//		{
//			nums1[i] = nums2[j];
//			j++;
//		}
//		else
//		{
//			j++;
//		}
//	}
//	qsort(nums1, m+n, sizeof(nums1[0]), cmp_int);
//}
//int main()
//{
//	int arr1[] = { 1,2,3,0,0,0 };
//	int arr2[] = { 2,5,6 };
//	merge(arr1, 3, arr2, 3);
//	int i = 0;
//	for (i = 0; i < 3 + 3; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//
//}

//int maxProfit(int* prices, int pricesSize) {
//	int max = 0, realmax = 0;
//	for (int i = 1; i < pricesSize; i++)
//	{
//		max = max + prices[i] - prices[i - 1];
//		if (max < 0)
//			max = 0;
//		if (max > realmax)
//			realmax = max;
//	}
//	return realmax;
//}
//int main()
//{
//	int arr[] = { 7,1,5,3,6,4 };
//	printf("%d\n", maxProfit(arr, 6));
//	system("pause");
//	return 0;
//}

//void rotate(int* nums, int numsSize, int k)
//{
//	int  i = 0;
//	while (k--)
//	{
//		int tmp = nums[numsSize - 1];
//		for (i = numsSize - 2; i >= 0; i--)
//		{
//			nums[i + 1] = nums[i];
//		}
//		nums[0] = tmp;
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7 };
//	rotate(arr, 7, 3);
//	system("pause");
//	return 0;
//}
//int containsDuplicate(int* nums, int numsSize)
//{
	//int i = 0;
	//int j = 0;
	//for (i = 0; i < numsSize - 1; i++)
	//{
	//	int flag = 0;
	//	for (j = 0; j < numsSize - 1 - i; j++)
	//	{
	//		if (nums[j] > nums[j + 1])
	//		{
	//			int tmp = nums[j];
	//			nums[j] = nums[j + 1];
	//			nums[j + 1] = tmp;
	//			flag = 1;
	//		}
	//	}
	//	if (flag == 0)
	//		break;
	//}
//	for (i = 0; i < numsSize - 1; i++)
//	{
//		if (((nums[i]) ^ (nums[i + 1])) == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int a = 1;
//	int b = 3;
//	int c = a ^ b;
//	int arr[] = { 3,1 };
//	containsDuplicate(arr, 2);
//	system("pause");
//	return 0;
//}

//int findMaxConsecutiveOnes(int* nums, int numsSize)
//{
//	if (numsSize == 0)
//		return 0;
//	if (numsSize == 1)
//		return nums[0];
//	if (nums[0] == 1)
//		return 1;
//	int i = 0;
//	int sum = 0;
//	int max = 0;
//	for (i = 0; i < numsSize - 1; i++)
//	{
//		if (nums[i] + nums[i + 1] != nums[i])
//		{
//			sum = nums[i] + nums[i + 1];
//		}
//		else
//		{
//			if (max <= sum)
//				max = sum;
//			sum = 0;
//		}
//	}
//	return max;
//}
//int main()
//{
//	int arr[] = { 1,0,1,1,0,1 };
//	findMaxConsecutiveOnes(arr, 6);
//	system("pause");
//	return 0;
//}
//#include<string.h>
//#include<assert.h>
//int buddyStrings(char* A, char* B)
//{
//	assert(A);
//	assert(B);
//	if (*A == '\0')
//		return 0;
//	char* start = A;
//	int count = 0;
//	while (*A&&*B)
//	{
//		if (*A == *B)
//		{
//			A++;
//			B++;
//		}
//		else
//		{
//			if (count == 1)
//				return 0;
//			char tmp = *A;
//			*A = *(A + 1);
//			*(A + 1) = tmp;
//			count++;
//		}
//	}
//	if (*(A - 2) != *(A - 1))
//	{
//		char tmp = *(A - 2);
//		*(A - 2) = *(A - 1);
//		*(A - 1) = tmp;
//		if (*(A - 1) != *(B - 1))
//			return 0;
//		else
//			return 1;
//	}
//	else
//		return 1;
//}
//int main()
//{
//	char* a = "ab";
//	char* b = "ba";
//	buddyStrings(a, b);
//	system("pause");
//	return 0;
//}

//void GreedySelector(int n, int s[], int f[], int A[])
//{
//	A[1] = 1;
//	int j = 1;
//	int i = 0;
//	for (i = 2; i < n; i++)
//	{
//		if (s[i] >= f[j])
//		{
//			A[i] = 1;
//			j = i;
//		}
//		else
//		{
//			A[i] = 0;
//		}
//	}
//	for (i = 1; i < n; i++)
//	{
//		if(A[i]==1)
//		printf("%d ", i);
//	}
//	printf("\n");
//}
//int main()
//{
//
//		int s[11] = { 0,1,3,0,5,3,5,6,8,8,2 };
//		int f[11] = { 0 ,4,5,6,7,8,9,10,11,12,13};
//		int A[11] = { 0 };
//		GreedySelector(11, s, f, A);
//	system("pause");
//	return 0;
//}



//#include "stdio.h"
//#define N 3
//int x[N];
//int count = 0;
//
//void dump() {
//	int i = 0;
//	for (i = 0; i < N; i++) {
//		printf("%d", x[i]);
//	}
//	printf("\n");
//}
//
//void swap(int a, int b) {
//	int t = x[a];
//	x[a] = x[b];
//	x[b] = t;
//}
//
//void run(int n) {
//	int i;
//	if (N - 1 == n) {
//		dump();
//		count++;
//		return;
//	}
//	for (i = n; i < N; i++) {
//		swap(n, i);
//  		run(n + 1);
//		swap(n, i);
//	}
//}
//
//int main() {
//	int i;
//	for (i = 0; i < N; i++) {
//		x[i] = i + 1;
//	}
//	run(0);
//	printf("* Total: %d\n", count);
//}

//#include<stdio.h>
//int main()
//{
//	char *p = "abc";
//	char *q = "abc123";
//	while (*p = *q)
//		printf("%c %c", *p, *q);
//}

//#include<stdio.h>
//int book[10] ;
//int arr[10] ;
//void dfs(int step,int n)
//{
//	if (step == n + 1)
//	{
//		for (int i = 1; i <= n; i++)
//			printf("%d ", arr[i]);
//		printf("\n");
//		return;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (book[i] == 0)
//		{
//			arr[step] = i;
//			book[i] = 1;
//			dfs(step + 1,n);
//			book[i] = 0;
//		}
//	}
//	return;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	dfs(1,n);
//	system("pause");
//	return 0;
//}

//int book[10];
//int arr[10];
//int n = 9;
//int total;
//void dfs(int step)
//{
//
//	if (step == n + 1)
//	{
//		int flag = 0;
//		if (arr[1] * 100 + arr[2] * 10 + arr[3] + arr[4] * 100 + arr[5] * 10 + arr[6]
//			== arr[7] * 100 + arr[8] * 10 + arr[9])
//			flag = 1;
//		if (flag == 1)
//		{
//			for (int i = 1; i <= n; i++)
//				printf("%d ", arr[i]);
//			total++;
//			printf("\n");
//		}
//		return;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (book[i] == 0)
//		{
//			arr[step] = i;
//			book[i] = 1;
//			dfs(step + 1);
//			book[i] = 0;
//		}
//	}
//	return;
//}
//int main()
//{
//	dfs(1);
//	printf("%d\n", total/2);
//	system("pause");
//	return 0;
//}

typedef struct node
{
	int x;
	int y;
	int step;
}node;
int main()
{
	node qe[2501];
	int map[50][50] = {0};
	int book[50][50] = {0};
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int head, tail;
	int p,q,cx,cy;
	int i, j,k;
	int m, n,tx,ty;
	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d %d %d %d",&cx,&cy ,&p, &q);
	head = 0;
	tail = 0;
	qe[tail].x = cx;
	qe[tail].y = cy;
	qe[tail].step = 0;
	tail++;
	book[cx][cy] = 1;

	int flag = 0;
	while (head < tail)
	{
		for (k = 0; k < 4; k++)
		{
			tx = qe[head].x + next[k][0];
			ty = qe[head].y + next[k][1];
			if ((tx >= 0 && tx < m) && (ty >= 0 && ty < n))
			{
				if ((book[tx][ty] == 0) && (map[tx][ty] == 0))
				{
					book[tx][ty] = 1;
					qe[tail].x = tx;
					qe[tail].y = ty;
					qe[tail].step = qe[head].step + 1;
					tail++;
					if (tx == p && ty == q)
					{
						flag = 1;
						break;
					}
				}
			}
		}
		if (flag == 1)
			break;
		head++;
	}
	printf("%d\n", qe[tail-1].step);
}